#pragma once
#include <cassert>
#include <functional>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
template <class R>
struct rerooting {
public:
    using T = typename R::T;
    using M = typename R::M;
    using E = typename R::E;
    using V = typename R::V;
    static_assert(std::is_invocable_r_v<M, decltype(R::put_edge), const T&, const E&, int, int>,
                  "R::put_edge must work as M(const T&, const E&, int u, int v)");
    static_assert(std::is_invocable_r_v<M, decltype(R::merge), const M&, const M&>,
                  "R::merge must work as M(const M&, const M&)");
    static_assert(std::is_invocable_r_v<M, decltype(R::e)>, "R::e must work as M()");
    static_assert(std::is_invocable_r_v<T, decltype(R::put_vertex), const M&, const V&, int>,
                  "R::put_vertex must work as T(const M&, const V&, int v)");

    rerooting() {
    }
    explicit rerooting(int n) : rerooting(std::vector<V>(n)) {
    }
    explicit rerooting(std::vector<V> a) : _n(int(a.size())), vdata(std::move(a)), g(_n) {
    }
    int add_edge(int u, int v, E w = E()) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        int i = int(edges.size());
        edges.emplace_back(u, v);
        edata.push_back(std::move(w));
        g[u].push_back(i);
        g[v].push_back(i);
        return i;
    }
    void solve() {
        assert(int(edges.size()) == _n - 1);
        _dp.assign(_n, T());
        _agg.assign(_n, R::e());
        _sub.assign(2 * (_n - 1), T());
        std::vector<int> order, par(_n, -1), pe(_n, -1);
        order.reserve(_n);
        order.push_back(0);
        for (int k = 0; k < _n; k++) {
            int v = order[k];
            for (int i : g[v]) {
                int to = other(i, v);
                if (to == par[v]) continue;
                par[to] = v;
                pe[to] = i;
                order.push_back(to);
            }
        }
        // bottom-up: sub(par[v] -> v)
        for (int k = _n - 1; k > 0; k--) {
            int v = order[k];
            M acc = R::e();
            for (int i : g[v]) {
                int to = other(i, v);
                if (to == par[v]) continue;
                acc = R::merge(acc, R::put_edge(_sub[dir(i, v)], edata[i], v, to));
            }
            _sub[dir(pe[v], par[v])] = R::put_vertex(acc, vdata[v], v);
        }
        // top-down: sub(v -> par[v]) is ready when v is visited
        std::vector<M> pre, suf;
        for (int v : order) {
            int deg = int(g[v].size());
            pre.assign(deg + 1, R::e());
            suf.assign(deg + 1, R::e());
            for (int j = 0; j < deg; j++) {
                int i = g[v][j], to = other(i, v);
                pre[j + 1] = R::merge(pre[j], R::put_edge(_sub[dir(i, v)], edata[i], v, to));
            }
            for (int j = deg; j > 0; j--) {
                int i = g[v][j - 1], to = other(i, v);
                suf[j - 1] = R::merge(R::put_edge(_sub[dir(i, v)], edata[i], v, to), suf[j]);
            }
            _agg[v] = pre[deg];
            _dp[v] = R::put_vertex(_agg[v], vdata[v], v);
            for (int j = 0; j < deg; j++) {
                int i = g[v][j], to = other(i, v);
                if (to == par[v]) continue;
                _sub[dir(i, to)] = R::put_vertex(R::merge(pre[j], suf[j + 1]), vdata[v], v);
            }
        }
    }
    const T& dp(int v) const {
        assert(0 <= v && v < _n);
        return _dp[v];
    }
    const M& agg(int v) const {
        assert(0 <= v && v < _n);
        return _agg[v];
    }
    // sub(u, v): 辺 (u, v) を切ったときの v 側の部分木を v を根として見た値
    const T& sub(int u, int v) const {
        for (int i : g[u]) {
            if (other(i, u) == v) return _sub[dir(i, u)];
        }
        assert(false);
        return _dp[u];
    }
    // sub_by_edge(i, v): 辺 i を切ったときの v 側の部分木を v を根として見た値
    const T& sub_by_edge(int i, int v) const {
        assert(0 <= i && i < int(edges.size()));
        assert(edges[i].first == v || edges[i].second == v);
        return _sub[dir(i, other(i, v))];
    }

private:
    int _n;
    std::vector<T> _dp;
    std::vector<M> _agg;
    std::vector<V> vdata;
    std::vector<std::vector<int>> g;
    std::vector<std::pair<int, int>> edges;
    std::vector<E> edata;
    std::vector<T> _sub;
    int other(int i, int v) const {
        return edges[i].first ^ edges[i].second ^ v;
    }
    // dir(i, u): 辺 i を u から見て反対側の部分木の値の格納位置
    int dir(int i, int u) const {
        return 2 * i + (edges[i].first == u ? 0 : 1);
    }
};
