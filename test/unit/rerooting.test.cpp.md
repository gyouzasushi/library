---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728 DP (Rerooting)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/rerooting.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <utility>\n#include <variant>\n#include <vector>\n\n#line 3 \"graph/rerooting.hpp\"\
    \n#include <concepts>\n#line 7 \"graph/rerooting.hpp\"\ntemplate <class R>\nconcept\
    \ rerooting_spec = requires(const typename R::T& t, const typename R::M& m, const\
    \ typename R::E& e,\n                                  const typename R::V& v,\
    \ int i) {\n    { R::put_edge(t, e, i, i) } -> std::convertible_to<typename R::M>;\n\
    \    { R::merge(m, m) } -> std::convertible_to<typename R::M>;\n    { R::e() }\
    \ -> std::convertible_to<typename R::M>;\n    { R::put_vertex(m, v, i) } -> std::convertible_to<typename\
    \ R::T>;\n};\ntemplate <rerooting_spec R>\nstruct rerooting {\npublic:\n    using\
    \ T = typename R::T;\n    using M = typename R::M;\n    using E = typename R::E;\n\
    \    using V = typename R::V;\n\n    rerooting() {\n    }\n    explicit rerooting(int\
    \ n) : rerooting(std::vector<V>(n)) {\n    }\n    explicit rerooting(std::vector<V>\
    \ a) : _n(int(a.size())), vdata(std::move(a)), g(_n) {\n    }\n    int add_edge(int\
    \ u, int v, E w = E()) {\n        assert(0 <= u && u < _n);\n        assert(0\
    \ <= v && v < _n);\n        int i = int(edges.size());\n        edges.emplace_back(u,\
    \ v);\n        edata.push_back(std::move(w));\n        g[u].push_back(i);\n  \
    \      g[v].push_back(i);\n        return i;\n    }\n    void solve() {\n    \
    \    assert(int(edges.size()) == _n - 1);\n        _dp.assign(_n, T());\n    \
    \    _agg.assign(_n, R::e());\n        _sub.assign(2 * (_n - 1), T());\n     \
    \   std::vector<int> order, par(_n, -1), pe(_n, -1);\n        order.reserve(_n);\n\
    \        order.push_back(0);\n        for (int k = 0; k < _n; k++) {\n       \
    \     int v = order[k];\n            for (int i : g[v]) {\n                int\
    \ to = other(i, v);\n                if (to == par[v]) continue;\n           \
    \     par[to] = v;\n                pe[to] = i;\n                order.push_back(to);\n\
    \            }\n        }\n        // bottom-up: sub(par[v] -> v)\n        for\
    \ (int k = _n - 1; k > 0; k--) {\n            int v = order[k];\n            M\
    \ acc = R::e();\n            for (int i : g[v]) {\n                int to = other(i,\
    \ v);\n                if (to == par[v]) continue;\n                acc = R::merge(acc,\
    \ R::put_edge(_sub[dir(i, v)], edata[i], v, to));\n            }\n           \
    \ _sub[dir(pe[v], par[v])] = R::put_vertex(acc, vdata[v], v);\n        }\n   \
    \     // top-down: sub(v -> par[v]) is ready when v is visited\n        std::vector<M>\
    \ pre, suf;\n        for (int v : order) {\n            int deg = int(g[v].size());\n\
    \            pre.assign(deg + 1, R::e());\n            suf.assign(deg + 1, R::e());\n\
    \            for (int j = 0; j < deg; j++) {\n                int i = g[v][j],\
    \ to = other(i, v);\n                pre[j + 1] = R::merge(pre[j], R::put_edge(_sub[dir(i,\
    \ v)], edata[i], v, to));\n            }\n            for (int j = deg; j > 0;\
    \ j--) {\n                int i = g[v][j - 1], to = other(i, v);\n           \
    \     suf[j - 1] = R::merge(R::put_edge(_sub[dir(i, v)], edata[i], v, to), suf[j]);\n\
    \            }\n            _agg[v] = pre[deg];\n            _dp[v] = R::put_vertex(_agg[v],\
    \ vdata[v], v);\n            for (int j = 0; j < deg; j++) {\n               \
    \ int i = g[v][j], to = other(i, v);\n                if (to == par[v]) continue;\n\
    \                _sub[dir(i, to)] = R::put_vertex(R::merge(pre[j], suf[j + 1]),\
    \ vdata[v], v);\n            }\n        }\n    }\n    const T& dp(int v) const\
    \ {\n        assert(0 <= v && v < _n);\n        return _dp[v];\n    }\n    const\
    \ M& agg(int v) const {\n        assert(0 <= v && v < _n);\n        return _agg[v];\n\
    \    }\n    // sub(u, v): \u8FBA (u, v) \u3092\u5207\u3063\u305F\u3068\u304D\u306E\
    \ v \u5074\u306E\u90E8\u5206\u6728\u3092 v \u3092\u6839\u3068\u3057\u3066\u898B\
    \u305F\u5024\n    const T& sub(int u, int v) const {\n        for (int i : g[u])\
    \ {\n            if (other(i, u) == v) return _sub[dir(i, u)];\n        }\n  \
    \      assert(false);\n        return _dp[u];\n    }\n    // sub_by_edge(i, v):\
    \ \u8FBA i \u3092\u5207\u3063\u305F\u3068\u304D\u306E v \u5074\u306E\u90E8\u5206\
    \u6728\u3092 v \u3092\u6839\u3068\u3057\u3066\u898B\u305F\u5024\n    const T&\
    \ sub_by_edge(int i, int v) const {\n        assert(0 <= i && i < int(edges.size()));\n\
    \        assert(edges[i].first == v || edges[i].second == v);\n        return\
    \ _sub[dir(i, other(i, v))];\n    }\n\nprivate:\n    int _n;\n    std::vector<T>\
    \ _dp;\n    std::vector<M> _agg;\n    std::vector<V> vdata;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<std::pair<int, int>> edges;\n    std::vector<E> edata;\n\
    \    std::vector<T> _sub;\n    int other(int i, int v) const {\n        return\
    \ edges[i].first ^ edges[i].second ^ v;\n    }\n    // dir(i, u): \u8FBA i \u3092\
    \ u \u304B\u3089\u898B\u3066\u53CD\u5BFE\u5074\u306E\u90E8\u5206\u6728\u306E\u5024\
    \u306E\u683C\u7D0D\u4F4D\u7F6E\n    int dir(int i, int u) const {\n        return\
    \ 2 * i + (edges[i].first == u ? 0 : 1);\n    }\n};\n#line 11 \"test/unit/rerooting.test.cpp\"\
    \nusing ll = long long;\nconstexpr ll NEG = -(1LL << 60);\n\n// \u8DDD\u96E2\u306E\
    \u7DCF\u548C\u30FB\u90E8\u5206\u6728\u30B5\u30A4\u30BA\uFF08T = M, E = V = monostate\uFF09\
    \nstruct dist_sum {\n    struct T {\n        ll cnt, sum;\n    };\n    using M\
    \ = T;\n    using E = std::monostate;\n    using V = std::monostate;\n    static\
    \ M put_edge(const T& x, const E&, int, int) {\n        return {x.cnt, x.sum +\
    \ x.cnt};\n    }\n    static M merge(const M& a, const M& b) {\n        return\
    \ {a.cnt + b.cnt, a.sum + b.sum};\n    }\n    static M e() {\n        return {0,\
    \ 0};\n    }\n    static T put_vertex(const M& acc, const V&, int) {\n       \
    \ return {acc.cnt + 1, acc.sum};\n    }\n};\n// \u91CD\u307F\u4ED8\u304D\u8FBA\
    \u30FB\u9802\u70B9\u5024: max_{j != i} (dist(i, j) + d_j)\u3002\u7B54\u3048\u306F\
    \ agg\uFF08ABC222 F \u578B\uFF09\nstruct far_plus {\n    using T = ll;\n    using\
    \ M = ll;\n    using E = ll;\n    using V = ll;\n    static M put_edge(const T&\
    \ x, const E& w, int, int) {\n        return x + w;\n    }\n    static M merge(const\
    \ M& a, const M& b) {\n        return std::max(a, b);\n    }\n    static M e()\
    \ {\n        return NEG;\n    }\n    static T put_vertex(const M& acc, const V&\
    \ d, int) {\n        return std::max(acc, d);\n    }\n};\n// \u76F4\u5F84: T =\
    \ \u6700\u5927\u6DF1\u3055, M = \u4E0A\u4F4D 2 \u3064\uFF08T != M \u578B\uFF09\
    \nstruct diameter {\n    using T = ll;\n    struct M {\n        ll a, b;\n   \
    \ };\n    using E = std::monostate;\n    using V = std::monostate;\n    static\
    \ M put_edge(const T& x, const E&, int, int) {\n        return {x + 1, NEG};\n\
    \    }\n    static M merge(const M& p, const M& q) {\n        ll v[4] = {p.a,\
    \ p.b, q.a, q.b};\n        std::sort(v, v + 4, std::greater<ll>());\n        return\
    \ {v[0], v[1]};\n    }\n    static M e() {\n        return {NEG, NEG};\n    }\n\
    \    static T put_vertex(const M& acc, const V&, int) {\n        return std::max(acc.a,\
    \ 0LL);\n    }\n};\n// \u975E\u53EF\u63DB merge \u306E\u6574\u5408\u6027: \u96A3\
    \u63A5\u9806\u306B\u4E26\u3079\u305F\u5217\nstruct concat {\n    using T = std::vector<int>;\n\
    \    using M = std::vector<int>;\n    using E = std::monostate;\n    using V =\
    \ std::monostate;\n    static M put_edge(const T& x, const E&, int, int) {\n \
    \       return x;\n    }\n    static M merge(const M& a, const M& b) {\n     \
    \   M r = a;\n        r.insert(r.end(), b.begin(), b.end());\n        return r;\n\
    \    }\n    static M e() {\n        return {};\n    }\n    static T put_vertex(const\
    \ M& acc, const V&, int v) {\n        T r = {v};\n        r.insert(r.end(), acc.begin(),\
    \ acc.end());\n        return r;\n    }\n};\n\nvoid stress(std::mt19937& rng)\
    \ {\n    const int N = 1 + rng() % 25;\n    std::vector<std::pair<int, int>> es;\n\
    \    std::vector<ll> w(N - 1), d(N);\n    std::vector<std::vector<std::pair<int,\
    \ ll>>> g(N);\n    for (int v = 1; v < N; v++) {\n        int p = rng() % v;\n\
    \        if (rng() % 2) es.emplace_back(v, p);\n        else es.emplace_back(p,\
    \ v);\n        w[v - 1] = rng() % 10;\n        g[v].emplace_back(p, w[v - 1]);\n\
    \        g[p].emplace_back(v, w[v - 1]);\n    }\n    for (auto& x : d) x = rng()\
    \ % 20;\n    // \u8FBA\u306E\u9806\u756A\u3092\u30B7\u30E3\u30C3\u30D5\u30EB\u3057\
    \u3066 add_edge \u9806\u3068\u9802\u70B9\u756A\u53F7\u306E\u76F8\u95A2\u3092\u6D88\
    \u3059\n    std::vector<int> perm(N - 1);\n    for (int i = 0; i < N - 1; i++)\
    \ perm[i] = i;\n    std::shuffle(perm.begin(), perm.end(), rng);\n\n    // naive:\
    \ \u5168\u70B9 BFS\n    auto dists = [&](int s, bool weighted) {\n        std::vector<ll>\
    \ dist(N, -1);\n        std::vector<int> st = {s};\n        dist[s] = 0;\n   \
    \     while (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            for (auto [to, ww] : g[v]) {\n                if (dist[to] != -1)\
    \ continue;\n                dist[to] = dist[v] + (weighted ? ww : 1);\n     \
    \           st.push_back(to);\n            }\n        }\n        return dist;\n\
    \    };\n    auto side = [&](int u, int v) {  // \u8FBA (u, v) \u3092\u5207\u3063\
    \u305F\u3068\u304D\u306E v \u5074\u306E\u9802\u70B9\u96C6\u5408\n        std::vector<char>\
    \ in(N, 0);\n        std::vector<int> st = {v};\n        in[v] = 1;\n        while\
    \ (!st.empty()) {\n            int x = st.back();\n            st.pop_back();\n\
    \            for (auto [to, ww] : g[x]) {\n                if (in[to] || (x ==\
    \ v && to == u)) continue;\n                in[to] = 1;\n                st.push_back(to);\n\
    \            }\n        }\n        return in;\n    };\n\n    {\n        rerooting<dist_sum>\
    \ rr(N);\n        for (int i : perm) rr.add_edge(es[i].first, es[i].second);\n\
    \        rr.solve();\n        for (int v = 0; v < N; v++) {\n            auto\
    \ dist = dists(v, false);\n            ll s = 0;\n            for (ll x : dist)\
    \ s += x;\n            assert(rr.dp(v).cnt == N && rr.dp(v).sum == s);\n     \
    \   }\n        for (auto [u, v] : es) {\n            auto in = side(u, v);\n \
    \           auto dist = dists(v, false);\n            ll cnt = 0, s = 0;\n   \
    \         for (int x = 0; x < N; x++) {\n                if (!in[x]) continue;\n\
    \                cnt++, s += dist[x];\n            }\n            assert(rr.sub(u,\
    \ v).cnt == cnt && rr.sub(u, v).sum == s);\n            auto in2 = side(v, u);\n\
    \            ll cnt2 = 0;\n            for (int x = 0; x < N; x++) cnt2 += in2[x];\n\
    \            assert(rr.sub(v, u).cnt == cnt2);\n        }\n    }\n    if (N >=\
    \ 2) {\n        rerooting<far_plus> rr(d);\n        std::vector<int> eid(N - 1);\n\
    \        for (int i : perm) eid[i] = rr.add_edge(es[i].first, es[i].second, w[i]);\n\
    \        rr.solve();\n        for (int v = 0; v < N; v++) {\n            auto\
    \ dist = dists(v, true);\n            ll best = NEG;\n            for (int j =\
    \ 0; j < N; j++) {\n                if (j != v) best = std::max(best, dist[j]\
    \ + d[j]);\n            }\n            assert(rr.agg(v) == best);\n          \
    \  assert(rr.dp(v) == std::max(best, d[v]));\n        }\n        for (int i =\
    \ 0; i < N - 1; i++) {\n            auto [u, v] = es[i];\n            assert(rr.sub_by_edge(eid[i],\
    \ v) == rr.sub(u, v));\n            assert(rr.sub_by_edge(eid[i], u) == rr.sub(v,\
    \ u));\n        }\n    }\n    {\n        rerooting<diameter> rr(N);\n        for\
    \ (int i : perm) rr.add_edge(es[i].first, es[i].second);\n        rr.solve();\n\
    \        ll diam = 0;\n        for (int v = 0; v < N; v++) {\n            auto\
    \ dist = dists(v, false);\n            ll ecc = *std::max_element(dist.begin(),\
    \ dist.end());\n            assert(rr.dp(v) == ecc);\n            ll a = std::max(rr.agg(v).a,\
    \ 0LL), b = std::max(rr.agg(v).b, 0LL);\n            diam = std::max(diam, a +\
    \ b);\n        }\n        ll expect = 0;\n        for (int v = 0; v < N; v++)\
    \ {\n            auto dist = dists(v, false);\n            expect = std::max(expect,\
    \ *std::max_element(dist.begin(), dist.end()));\n        }\n        assert(diam\
    \ == expect);\n    }\n    {\n        rerooting<concat> rr(N);\n        for (int\
    \ i : perm) rr.add_edge(es[i].first, es[i].second);\n        rr.solve();\n   \
    \     for (int v = 0; v < N; v++) {\n            // v \u3092\u6839\u3068\u3057\
    \u305F DFS \u3067\u3001\u5404\u9802\u70B9\u306E\u96A3\u63A5\u3092 add_edge \u9806\
    \u306B\u898B\u305F\u524D\u9806\n            std::vector<std::vector<int>> adj(N);\n\
    \            for (int i : perm) {\n                adj[es[i].first].push_back(es[i].second);\n\
    \                adj[es[i].second].push_back(es[i].first);\n            }\n  \
    \          std::vector<int> pre;\n            auto dfs = [&](auto dfs, int x,\
    \ int p) -> void {\n                pre.push_back(x);\n                for (int\
    \ to : adj[x]) {\n                    if (to != p) dfs(dfs, to, x);\n        \
    \        }\n            };\n            dfs(dfs, v, -1);\n            assert(rr.dp(v)\
    \ == pre);\n        }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n \
    \   for (int trial = 0; trial < 300; trial++) stress(rng);\n    std::cout << \"\
    Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <random>\n\
    #include <utility>\n#include <variant>\n#include <vector>\n\n#include \"graph/rerooting.hpp\"\
    \nusing ll = long long;\nconstexpr ll NEG = -(1LL << 60);\n\n// \u8DDD\u96E2\u306E\
    \u7DCF\u548C\u30FB\u90E8\u5206\u6728\u30B5\u30A4\u30BA\uFF08T = M, E = V = monostate\uFF09\
    \nstruct dist_sum {\n    struct T {\n        ll cnt, sum;\n    };\n    using M\
    \ = T;\n    using E = std::monostate;\n    using V = std::monostate;\n    static\
    \ M put_edge(const T& x, const E&, int, int) {\n        return {x.cnt, x.sum +\
    \ x.cnt};\n    }\n    static M merge(const M& a, const M& b) {\n        return\
    \ {a.cnt + b.cnt, a.sum + b.sum};\n    }\n    static M e() {\n        return {0,\
    \ 0};\n    }\n    static T put_vertex(const M& acc, const V&, int) {\n       \
    \ return {acc.cnt + 1, acc.sum};\n    }\n};\n// \u91CD\u307F\u4ED8\u304D\u8FBA\
    \u30FB\u9802\u70B9\u5024: max_{j != i} (dist(i, j) + d_j)\u3002\u7B54\u3048\u306F\
    \ agg\uFF08ABC222 F \u578B\uFF09\nstruct far_plus {\n    using T = ll;\n    using\
    \ M = ll;\n    using E = ll;\n    using V = ll;\n    static M put_edge(const T&\
    \ x, const E& w, int, int) {\n        return x + w;\n    }\n    static M merge(const\
    \ M& a, const M& b) {\n        return std::max(a, b);\n    }\n    static M e()\
    \ {\n        return NEG;\n    }\n    static T put_vertex(const M& acc, const V&\
    \ d, int) {\n        return std::max(acc, d);\n    }\n};\n// \u76F4\u5F84: T =\
    \ \u6700\u5927\u6DF1\u3055, M = \u4E0A\u4F4D 2 \u3064\uFF08T != M \u578B\uFF09\
    \nstruct diameter {\n    using T = ll;\n    struct M {\n        ll a, b;\n   \
    \ };\n    using E = std::monostate;\n    using V = std::monostate;\n    static\
    \ M put_edge(const T& x, const E&, int, int) {\n        return {x + 1, NEG};\n\
    \    }\n    static M merge(const M& p, const M& q) {\n        ll v[4] = {p.a,\
    \ p.b, q.a, q.b};\n        std::sort(v, v + 4, std::greater<ll>());\n        return\
    \ {v[0], v[1]};\n    }\n    static M e() {\n        return {NEG, NEG};\n    }\n\
    \    static T put_vertex(const M& acc, const V&, int) {\n        return std::max(acc.a,\
    \ 0LL);\n    }\n};\n// \u975E\u53EF\u63DB merge \u306E\u6574\u5408\u6027: \u96A3\
    \u63A5\u9806\u306B\u4E26\u3079\u305F\u5217\nstruct concat {\n    using T = std::vector<int>;\n\
    \    using M = std::vector<int>;\n    using E = std::monostate;\n    using V =\
    \ std::monostate;\n    static M put_edge(const T& x, const E&, int, int) {\n \
    \       return x;\n    }\n    static M merge(const M& a, const M& b) {\n     \
    \   M r = a;\n        r.insert(r.end(), b.begin(), b.end());\n        return r;\n\
    \    }\n    static M e() {\n        return {};\n    }\n    static T put_vertex(const\
    \ M& acc, const V&, int v) {\n        T r = {v};\n        r.insert(r.end(), acc.begin(),\
    \ acc.end());\n        return r;\n    }\n};\n\nvoid stress(std::mt19937& rng)\
    \ {\n    const int N = 1 + rng() % 25;\n    std::vector<std::pair<int, int>> es;\n\
    \    std::vector<ll> w(N - 1), d(N);\n    std::vector<std::vector<std::pair<int,\
    \ ll>>> g(N);\n    for (int v = 1; v < N; v++) {\n        int p = rng() % v;\n\
    \        if (rng() % 2) es.emplace_back(v, p);\n        else es.emplace_back(p,\
    \ v);\n        w[v - 1] = rng() % 10;\n        g[v].emplace_back(p, w[v - 1]);\n\
    \        g[p].emplace_back(v, w[v - 1]);\n    }\n    for (auto& x : d) x = rng()\
    \ % 20;\n    // \u8FBA\u306E\u9806\u756A\u3092\u30B7\u30E3\u30C3\u30D5\u30EB\u3057\
    \u3066 add_edge \u9806\u3068\u9802\u70B9\u756A\u53F7\u306E\u76F8\u95A2\u3092\u6D88\
    \u3059\n    std::vector<int> perm(N - 1);\n    for (int i = 0; i < N - 1; i++)\
    \ perm[i] = i;\n    std::shuffle(perm.begin(), perm.end(), rng);\n\n    // naive:\
    \ \u5168\u70B9 BFS\n    auto dists = [&](int s, bool weighted) {\n        std::vector<ll>\
    \ dist(N, -1);\n        std::vector<int> st = {s};\n        dist[s] = 0;\n   \
    \     while (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            for (auto [to, ww] : g[v]) {\n                if (dist[to] != -1)\
    \ continue;\n                dist[to] = dist[v] + (weighted ? ww : 1);\n     \
    \           st.push_back(to);\n            }\n        }\n        return dist;\n\
    \    };\n    auto side = [&](int u, int v) {  // \u8FBA (u, v) \u3092\u5207\u3063\
    \u305F\u3068\u304D\u306E v \u5074\u306E\u9802\u70B9\u96C6\u5408\n        std::vector<char>\
    \ in(N, 0);\n        std::vector<int> st = {v};\n        in[v] = 1;\n        while\
    \ (!st.empty()) {\n            int x = st.back();\n            st.pop_back();\n\
    \            for (auto [to, ww] : g[x]) {\n                if (in[to] || (x ==\
    \ v && to == u)) continue;\n                in[to] = 1;\n                st.push_back(to);\n\
    \            }\n        }\n        return in;\n    };\n\n    {\n        rerooting<dist_sum>\
    \ rr(N);\n        for (int i : perm) rr.add_edge(es[i].first, es[i].second);\n\
    \        rr.solve();\n        for (int v = 0; v < N; v++) {\n            auto\
    \ dist = dists(v, false);\n            ll s = 0;\n            for (ll x : dist)\
    \ s += x;\n            assert(rr.dp(v).cnt == N && rr.dp(v).sum == s);\n     \
    \   }\n        for (auto [u, v] : es) {\n            auto in = side(u, v);\n \
    \           auto dist = dists(v, false);\n            ll cnt = 0, s = 0;\n   \
    \         for (int x = 0; x < N; x++) {\n                if (!in[x]) continue;\n\
    \                cnt++, s += dist[x];\n            }\n            assert(rr.sub(u,\
    \ v).cnt == cnt && rr.sub(u, v).sum == s);\n            auto in2 = side(v, u);\n\
    \            ll cnt2 = 0;\n            for (int x = 0; x < N; x++) cnt2 += in2[x];\n\
    \            assert(rr.sub(v, u).cnt == cnt2);\n        }\n    }\n    if (N >=\
    \ 2) {\n        rerooting<far_plus> rr(d);\n        std::vector<int> eid(N - 1);\n\
    \        for (int i : perm) eid[i] = rr.add_edge(es[i].first, es[i].second, w[i]);\n\
    \        rr.solve();\n        for (int v = 0; v < N; v++) {\n            auto\
    \ dist = dists(v, true);\n            ll best = NEG;\n            for (int j =\
    \ 0; j < N; j++) {\n                if (j != v) best = std::max(best, dist[j]\
    \ + d[j]);\n            }\n            assert(rr.agg(v) == best);\n          \
    \  assert(rr.dp(v) == std::max(best, d[v]));\n        }\n        for (int i =\
    \ 0; i < N - 1; i++) {\n            auto [u, v] = es[i];\n            assert(rr.sub_by_edge(eid[i],\
    \ v) == rr.sub(u, v));\n            assert(rr.sub_by_edge(eid[i], u) == rr.sub(v,\
    \ u));\n        }\n    }\n    {\n        rerooting<diameter> rr(N);\n        for\
    \ (int i : perm) rr.add_edge(es[i].first, es[i].second);\n        rr.solve();\n\
    \        ll diam = 0;\n        for (int v = 0; v < N; v++) {\n            auto\
    \ dist = dists(v, false);\n            ll ecc = *std::max_element(dist.begin(),\
    \ dist.end());\n            assert(rr.dp(v) == ecc);\n            ll a = std::max(rr.agg(v).a,\
    \ 0LL), b = std::max(rr.agg(v).b, 0LL);\n            diam = std::max(diam, a +\
    \ b);\n        }\n        ll expect = 0;\n        for (int v = 0; v < N; v++)\
    \ {\n            auto dist = dists(v, false);\n            expect = std::max(expect,\
    \ *std::max_element(dist.begin(), dist.end()));\n        }\n        assert(diam\
    \ == expect);\n    }\n    {\n        rerooting<concat> rr(N);\n        for (int\
    \ i : perm) rr.add_edge(es[i].first, es[i].second);\n        rr.solve();\n   \
    \     for (int v = 0; v < N; v++) {\n            // v \u3092\u6839\u3068\u3057\
    \u305F DFS \u3067\u3001\u5404\u9802\u70B9\u306E\u96A3\u63A5\u3092 add_edge \u9806\
    \u306B\u898B\u305F\u524D\u9806\n            std::vector<std::vector<int>> adj(N);\n\
    \            for (int i : perm) {\n                adj[es[i].first].push_back(es[i].second);\n\
    \                adj[es[i].second].push_back(es[i].first);\n            }\n  \
    \          std::vector<int> pre;\n            auto dfs = [&](auto dfs, int x,\
    \ int p) -> void {\n                pre.push_back(x);\n                for (int\
    \ to : adj[x]) {\n                    if (to != p) dfs(dfs, to, x);\n        \
    \        }\n            };\n            dfs(dfs, v, -1);\n            assert(rr.dp(v)\
    \ == pre);\n        }\n    }\n}\nint main() {\n    std::mt19937 rng(7959);\n \
    \   for (int trial = 0; trial < 300; trial++) stress(rng);\n    std::cout << \"\
    Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/rerooting.hpp
  isVerificationFile: true
  path: test/unit/rerooting.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 07:09:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/unit/rerooting.test.cpp
- /verify/test/unit/rerooting.test.cpp.html
title: test/unit/rerooting.test.cpp
---
