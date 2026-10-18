#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <utility>
#include <variant>
#include <vector>

#include "graph/rerooting.hpp"
using ll = long long;
constexpr ll NEG = -(1LL << 60);

// 距離の総和・部分木サイズ（T = M, E = V = monostate）
struct dist_sum {
    struct T {
        ll cnt, sum;
    };
    using M = T;
    using E = std::monostate;
    using V = std::monostate;
    static M put_edge(const T& x, const E&, int, int) {
        return {x.cnt, x.sum + x.cnt};
    }
    static M merge(const M& a, const M& b) {
        return {a.cnt + b.cnt, a.sum + b.sum};
    }
    static M e() {
        return {0, 0};
    }
    static T put_vertex(const M& acc, const V&, int) {
        return {acc.cnt + 1, acc.sum};
    }
};
// 重み付き辺・頂点値: max_{j != i} (dist(i, j) + d_j)。答えは agg（ABC222 F 型）
struct far_plus {
    using T = ll;
    using M = ll;
    using E = ll;
    using V = ll;
    static M put_edge(const T& x, const E& w, int, int) {
        return x + w;
    }
    static M merge(const M& a, const M& b) {
        return std::max(a, b);
    }
    static M e() {
        return NEG;
    }
    static T put_vertex(const M& acc, const V& d, int) {
        return std::max(acc, d);
    }
};
// 直径: T = 最大深さ, M = 上位 2 つ（T != M 型）
struct diameter {
    using T = ll;
    struct M {
        ll a, b;
    };
    using E = std::monostate;
    using V = std::monostate;
    static M put_edge(const T& x, const E&, int, int) {
        return {x + 1, NEG};
    }
    static M merge(const M& p, const M& q) {
        ll v[4] = {p.a, p.b, q.a, q.b};
        std::sort(v, v + 4, std::greater<ll>());
        return {v[0], v[1]};
    }
    static M e() {
        return {NEG, NEG};
    }
    static T put_vertex(const M& acc, const V&, int) {
        return std::max(acc.a, 0LL);
    }
};
// 非可換 merge の整合性: 隣接順に並べた列
struct concat {
    using T = std::vector<int>;
    using M = std::vector<int>;
    using E = std::monostate;
    using V = std::monostate;
    static M put_edge(const T& x, const E&, int, int) {
        return x;
    }
    static M merge(const M& a, const M& b) {
        M r = a;
        r.insert(r.end(), b.begin(), b.end());
        return r;
    }
    static M e() {
        return {};
    }
    static T put_vertex(const M& acc, const V&, int v) {
        T r = {v};
        r.insert(r.end(), acc.begin(), acc.end());
        return r;
    }
};

void stress(std::mt19937& rng) {
    const int N = 1 + rng() % 25;
    std::vector<std::pair<int, int>> es;
    std::vector<ll> w(N - 1), d(N);
    std::vector<std::vector<std::pair<int, ll>>> g(N);
    for (int v = 1; v < N; v++) {
        int p = rng() % v;
        if (rng() % 2) es.emplace_back(v, p);
        else es.emplace_back(p, v);
        w[v - 1] = rng() % 10;
        g[v].emplace_back(p, w[v - 1]);
        g[p].emplace_back(v, w[v - 1]);
    }
    for (auto& x : d) x = rng() % 20;
    // 辺の順番をシャッフルして add_edge 順と頂点番号の相関を消す
    std::vector<int> perm(N - 1);
    for (int i = 0; i < N - 1; i++) perm[i] = i;
    std::shuffle(perm.begin(), perm.end(), rng);

    // naive: 全点 BFS
    auto dists = [&](int s, bool weighted) {
        std::vector<ll> dist(N, -1);
        std::vector<int> st = {s};
        dist[s] = 0;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            for (auto [to, ww] : g[v]) {
                if (dist[to] != -1) continue;
                dist[to] = dist[v] + (weighted ? ww : 1);
                st.push_back(to);
            }
        }
        return dist;
    };
    auto side = [&](int u, int v) {  // 辺 (u, v) を切ったときの v 側の頂点集合
        std::vector<char> in(N, 0);
        std::vector<int> st = {v};
        in[v] = 1;
        while (!st.empty()) {
            int x = st.back();
            st.pop_back();
            for (auto [to, ww] : g[x]) {
                if (in[to] || (x == v && to == u)) continue;
                in[to] = 1;
                st.push_back(to);
            }
        }
        return in;
    };

    {
        rerooting<dist_sum> rr(N);
        for (int i : perm) rr.add_edge(es[i].first, es[i].second);
        rr.solve();
        for (int v = 0; v < N; v++) {
            auto dist = dists(v, false);
            ll s = 0;
            for (ll x : dist) s += x;
            assert(rr.dp[v].cnt == N && rr.dp[v].sum == s);
        }
        for (auto [u, v] : es) {
            auto in = side(u, v);
            auto dist = dists(v, false);
            ll cnt = 0, s = 0;
            for (int x = 0; x < N; x++) {
                if (!in[x]) continue;
                cnt++, s += dist[x];
            }
            assert(rr.sub(u, v).cnt == cnt && rr.sub(u, v).sum == s);
            auto in2 = side(v, u);
            ll cnt2 = 0;
            for (int x = 0; x < N; x++) cnt2 += in2[x];
            assert(rr.sub(v, u).cnt == cnt2);
        }
    }
    if (N >= 2) {
        rerooting<far_plus> rr(d);
        std::vector<int> eid(N - 1);
        for (int i : perm) eid[i] = rr.add_edge(es[i].first, es[i].second, w[i]);
        rr.solve();
        for (int v = 0; v < N; v++) {
            auto dist = dists(v, true);
            ll best = NEG;
            for (int j = 0; j < N; j++) {
                if (j != v) best = std::max(best, dist[j] + d[j]);
            }
            assert(rr.agg[v] == best);
            assert(rr.dp[v] == std::max(best, d[v]));
        }
        for (int i = 0; i < N - 1; i++) {
            auto [u, v] = es[i];
            assert(rr.sub_by_edge(eid[i], v) == rr.sub(u, v));
            assert(rr.sub_by_edge(eid[i], u) == rr.sub(v, u));
        }
    }
    {
        rerooting<diameter> rr(N);
        for (int i : perm) rr.add_edge(es[i].first, es[i].second);
        rr.solve();
        ll diam = 0;
        for (int v = 0; v < N; v++) {
            auto dist = dists(v, false);
            ll ecc = *std::max_element(dist.begin(), dist.end());
            assert(rr.dp[v] == ecc);
            ll a = std::max(rr.agg[v].a, 0LL), b = std::max(rr.agg[v].b, 0LL);
            diam = std::max(diam, a + b);
        }
        ll expect = 0;
        for (int v = 0; v < N; v++) {
            auto dist = dists(v, false);
            expect = std::max(expect, *std::max_element(dist.begin(), dist.end()));
        }
        assert(diam == expect);
    }
    {
        rerooting<concat> rr(N);
        for (int i : perm) rr.add_edge(es[i].first, es[i].second);
        rr.solve();
        for (int v = 0; v < N; v++) {
            // v を根とした DFS で、各頂点の隣接を add_edge 順に見た前順
            std::vector<std::vector<int>> adj(N);
            for (int i : perm) {
                adj[es[i].first].push_back(es[i].second);
                adj[es[i].second].push_back(es[i].first);
            }
            std::vector<int> pre;
            auto dfs = [&](auto dfs, int x, int p) -> void {
                pre.push_back(x);
                for (int to : adj[x]) {
                    if (to != p) dfs(dfs, to, x);
                }
            };
            dfs(dfs, v, -1);
            assert(rr.dp[v] == pre);
        }
    }
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 300; trial++) stress(rng);
    std::cout << "Hello World" << std::endl;
    return 0;
}
