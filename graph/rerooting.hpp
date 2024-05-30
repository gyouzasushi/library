#pragma once
#include <cassert>
#include <vector>
template <class S, S (*op)(S, S), S (*e)(), S (*put_edge)(S, int, int),
          S (*put_vertex)(S, int), S (*leaf)(int)>
struct rerooting {
public:
    rerooting() {
    }
    rerooting(int n) : _n(n), g(n), dp(n) {
    }
    void add_edge(int u, int v) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<S> solve() {
        for (int i = 0; i < _n; i++) {
            int deg = int(g[i].size());
            dp[i].resize(deg);
        }
        auto dfs1 = [&](auto dfs1, int u, int p) -> S {
            S ret = e();
            int deg = int(g[u].size());
            bool upd = false;
            for (int i = 0; i < deg; i++) {
                int v = g[u][i];
                if (v == p) continue;
                dp[u][i] = dfs1(dfs1, v, u);
                ret = op(ret, put_edge(dp[u][i], u, v));
                upd = true;
            }
            if (!upd) return leaf(u);
            return put_vertex(ret, u);
        };
        auto dfs2 = [&](auto dfs2, int u, int p, const S& top) -> void {
            int deg = int(g[u].size());
            std::vector<S> cum_left(deg + 1, e()), cum_right(deg + 1, e());
            for (int i = 0; i < deg; i++) {
                int v = g[u][i];
                if (v == p) dp[u][i] = top;
                cum_left[i + 1] = op(cum_left[i], put_edge(dp[u][i], u, v));
            }
            for (int i = deg; i > 0; i--) {
                int v = g[u][i - 1];
                if (v == p) dp[u][i - 1] = top;
                cum_right[i - 1] =
                    op(cum_right[i], put_edge(dp[u][i - 1], u, v));
            }
            for (int i = 0; i < deg; i++) {
                int v = g[u][i];
                if (v == p) continue;
                dfs2(dfs2, v, u,
                     deg == 1
                         ? leaf(u)
                         : put_vertex(op(cum_left[i], cum_right[i + 1]), u));
            }
        };
        dfs1(dfs1, 0, -1);
        dfs2(dfs2, 0, -1, e());
        std::vector<S> ret(_n, e());
        for (int u = 0; u < _n; u++) {
            int deg = int(g[u].size());
            for (int i = 0; i < deg; i++) {
                int v = g[u][i];
                ret[u] = op(ret[u], put_edge(dp[u][i], u, v));
            }
            ret[u] = put_vertex(ret[u], u);
        }
        return ret;
    }

private:
    int _n;
    std::vector<std::vector<int>> g;
    std::vector<std::vector<S>> dp;
};