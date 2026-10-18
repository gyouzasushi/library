---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: "HL\u5206\u89E3 (Heavy-Light Decomposition)"
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
  bundledCode: "#line 1 \"test/unit/heavy_light_decomposition.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"graph/heavy_light_decomposition.hpp\"\n#include\
    \ <algorithm>\n#line 6 \"graph/heavy_light_decomposition.hpp\"\nstruct heavy_light_decomposition\
    \ {\npublic:\n    heavy_light_decomposition() {\n    }\n    heavy_light_decomposition(int\
    \ n, int root = 0)\n        : _n(n),\n          _root(root),\n          g(n),\n\
    \          sub(n),\n          dep(n),\n          par(n),\n          heavy(n, -1),\n\
    \          head(n),\n          in(n),\n          out(n),\n          rev(n) {\n\
    \    }\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < _n);\n\
    \        assert(0 <= v && v < _n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \        edges.emplace_back(u, v);\n    }\n    void build() {\n        par[_root]\
    \ = -1;\n        dep[_root] = 0;\n        std::vector<int> order, st = {_root};\n\
    \        order.reserve(_n);\n        while (!st.empty()) {\n            int v\
    \ = st.back();\n            st.pop_back();\n            order.push_back(v);\n\
    \            for (int c : g[v]) {\n                if (c == par[v]) continue;\n\
    \                par[c] = v;\n                dep[c] = dep[v] + 1;\n         \
    \       st.push_back(c);\n            }\n        }\n        for (int i = _n -\
    \ 1; i >= 0; i--) {\n            int v = order[i], p = par[v];\n            sub[v]++;\n\
    \            if (p == -1) continue;\n            sub[p] += sub[v];\n         \
    \   if (heavy[p] == -1 || sub[v] > sub[heavy[p]]) heavy[p] = v;\n        }\n \
    \       int t = 0;\n        head[_root] = _root;\n        st = {_root};\n    \
    \    while (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            in[v] = t++;\n            rev[in[v]] = v;\n            out[v] = in[v]\
    \ + sub[v];\n            for (int c : g[v]) {\n                if (c == par[v]\
    \ || c == heavy[v]) continue;\n                head[c] = c;\n                st.push_back(c);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    int index(int v) const {\n        return in[v];\n    }\n   \
    \ int vertex(int i) const {\n        return rev[i];\n    }\n    std::pair<int,\
    \ int> subtree(int v) const {\n        return {in[v], out[v]};\n    }\n    int\
    \ edge_index(int i) const {\n        assert(0 <= i && i < (int)edges.size());\n\
    \        auto [u, v] = edges[i];\n        return in[par[u] == v ? u : v];\n  \
    \  }\n    int depth(int v) const {\n        return dep[v];\n    }\n    int parent(int\
    \ v) const {\n        return par[v];\n    }\n    int head_of(int v) const {\n\
    \        return head[v];\n    }\n    int lca(int u, int v) const {\n        while\
    \ (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]]) std::swap(u,\
    \ v);\n            u = par[head[u]];\n        }\n        return dep[u] < dep[v]\
    \ ? u : v;\n    }\n    int lca(int u, int v, int r) const {\n        return lca(u,\
    \ v) ^ lca(v, r) ^ lca(r, u);\n    }\n    int dist(int u, int v) const {\n   \
    \     return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    int la(int v, int\
    \ k) const {\n        if (k < 0 || dep[v] < k) return -1;\n        while (dep[v]\
    \ - dep[head[v]] < k) {\n            k -= dep[v] - dep[head[v]] + 1;\n       \
    \     v = par[head[v]];\n        }\n        return rev[in[v] - k];\n    }\n  \
    \  int jump(int s, int t, int k) const {\n        int l = lca(s, t);\n       \
    \ int d = dep[s] + dep[t] - 2 * dep[l];\n        if (k < 0 || d < k) return -1;\n\
    \        if (k <= dep[s] - dep[l]) return la(s, k);\n        return la(t, d -\
    \ k);\n    }\n    bool in_subtree(int u, int v) const {\n        return in[u]\
    \ <= in[v] && in[v] < out[u];\n    }\n    bool on_path(int s, int t, int x) const\
    \ {\n        return dist(s, x) + dist(x, t) == dist(s, t);\n    }\n\n    template\
    \ <typename F>\n    void for_each_vertex(int u, int v, const F& f) const {\n \
    \       for_each(u, v, false, f);\n    }\n    template <typename F>\n    void\
    \ for_each_edge(int u, int v, const F& f) const {\n        for_each(u, v, true,\
    \ f);\n    }\n    template <typename F>\n    void for_each_vertex_noncommutative(int\
    \ u, int v, const F& f) const {\n        for_each_noncommutative(u, v, false,\
    \ f);\n    }\n    template <typename F>\n    void for_each_edge_noncommutative(int\
    \ u, int v, const F& f) const {\n        for_each_noncommutative(u, v, true, f);\n\
    \    }\n    template <typename F>\n    void for_each_vertex_in_subtree(int v,\
    \ const F& f) const {\n        f(in[v], out[v]);\n    }\n    template <typename\
    \ F>\n    void for_each_edge_in_subtree(int v, const F& f) const {\n        if\
    \ (in[v] + 1 < out[v]) f(in[v] + 1, out[v]);\n    }\n\nprivate:\n    int _n, _root;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<int> sub, dep, par, heavy, head, in, out, rev;\n    template\
    \ <typename F>\n    void for_each(int u, int v, bool edge, const F& f) const {\n\
    \        while (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]])\
    \ std::swap(u, v);\n            f(in[head[u]], in[u] + 1);\n            u = par[head[u]];\n\
    \        }\n        if (dep[u] > dep[v]) std::swap(u, v);\n        if (in[u] +\
    \ edge < in[v] + 1) f(in[u] + edge, in[v] + 1);\n    }\n    template <typename\
    \ F>\n    void for_each_noncommutative(int u, int v, bool edge, const F& f) const\
    \ {\n        std::vector<std::pair<int, int>> down;\n        while (head[u] !=\
    \ head[v]) {\n            if (dep[head[u]] >= dep[head[v]]) {\n              \
    \  f(in[u] + 1, in[head[u]]);\n                u = par[head[u]];\n           \
    \ } else {\n                down.emplace_back(in[head[v]], in[v] + 1);\n     \
    \           v = par[head[v]];\n            }\n        }\n        if (dep[u] >\
    \ dep[v]) {\n            if (in[v] + edge < in[u] + 1) f(in[u] + 1, in[v] + edge);\n\
    \        } else {\n            if (in[u] + edge < in[v] + 1) f(in[u] + edge, in[v]\
    \ + 1);\n        }\n        for (auto it = down.rbegin(); it != down.rend(); it++)\
    \ {\n            f(it->first, it->second);\n        }\n    }\n};\n#line 9 \"test/unit/heavy_light_decomposition.test.cpp\"\
    \nconstexpr long long MOD = 998244353;\nvoid stress(std::mt19937 &rng) {\n   \
    \ const int N = 1 + rng() % 40;\n    const int root = rng() % N;\n    heavy_light_decomposition\
    \ hld(N, root);\n    std::vector<std::vector<int>> g(N);\n    for (int v = 1;\
    \ v < N; v++) {\n        int p = rng() % v;\n        hld.add_edge(v, p);\n   \
    \     g[v].push_back(p);\n        g[p].push_back(v);\n    }\n    hld.build();\n\
    \    std::vector<int> par(N, -1), dep(N, 0);\n    auto dfs = [&](auto dfs, int\
    \ v, int p) -> void {\n        for (int c : g[v]) {\n            if (c == p) continue;\n\
    \            par[c] = v;\n            dep[c] = dep[v] + 1;\n            dfs(dfs,\
    \ c, v);\n        }\n    };\n    dfs(dfs, root, -1);\n    for (int i = 0; i +\
    \ 1 < N; i++) {\n        // i \u756A\u76EE\u306E\u8FBA\u306F (i + 1, p) \u3067\
    \ p < i + 1\n        int v = i + 1, p = -1;\n        for (int x : g[v]) if (x\
    \ < v) p = x;\n        int child = par[v] == p ? v : p;\n        assert(hld.edge_index(i)\
    \ == hld.index(child));\n    }\n    auto naive_path = [&](int u, int v) {\n  \
    \      std::vector<int> a, b;\n        while (u != v) {\n            if (dep[u]\
    \ >= dep[v]) {\n                a.push_back(u);\n                u = par[u];\n\
    \            } else {\n                b.push_back(v);\n                v = par[v];\n\
    \            }\n        }\n        a.push_back(u);\n        a.insert(a.end(),\
    \ b.rbegin(), b.rend());\n        return a;\n    };\n    std::vector<long long>\
    \ w(N), fa(N), fb(N);\n    for (int v = 0; v < N; v++) {\n        w[v] = rng()\
    \ % 100;\n        fa[v] = rng() % MOD;\n        fb[v] = rng() % MOD;\n    }\n\
    \    for (int i = 0; i < N; i++) {\n        assert(hld.vertex(hld.index(i)) ==\
    \ i);\n        assert(hld.depth(i) == dep[i]);\n        assert(hld.parent(i) ==\
    \ par[i]);\n    }\n    for (int q = 0; q < 300; q++) {\n        int u = rng()\
    \ % N, v = rng() % N;\n        std::vector<int> path = naive_path(u, v);\n   \
    \     int l = -1;\n        for (int x : path) {\n            if (l == -1 || dep[x]\
    \ < dep[l]) l = x;\n        }\n        assert(hld.lca(u, v) == l);\n        assert(hld.dist(u,\
    \ v) == (int)path.size() - 1);\n        int k = rng() % (path.size() + 2) - 1;\n\
    \        if (0 <= k && k < (int)path.size()) {\n            assert(hld.jump(u,\
    \ v, k) == path[k]);\n        } else {\n            assert(hld.jump(u, v, k) ==\
    \ -1);\n        }\n        {\n            int x = rng() % N;\n            bool\
    \ on = false;\n            for (int y : path) on |= (y == x);\n            assert(hld.on_path(u,\
    \ v, x) == on);\n            bool sub = false;\n            for (int y = x; y\
    \ != -1; y = par[y]) sub |= (y == u);\n            assert(hld.in_subtree(u, x)\
    \ == sub);\n            int kk = rng() % (dep[x] + 2) - 1;\n            int y\
    \ = x;\n            for (int i = 0; i < kk && y != -1; i++) y = par[y];\n    \
    \        assert(hld.la(x, kk) == (kk < 0 ? -1 : y));\n        }\n        {\n \
    \           long long sv = 0, se = 0;\n            for (int x : path) sv += w[x];\n\
    \            for (int x : path) {\n                if (x != l) se += w[x];\n \
    \           }\n            long long hv = 0, he = 0;\n            hld.for_each_vertex(u,\
    \ v, [&](int a, int b) {\n                assert(a < b);\n                for\
    \ (int i = a; i < b; i++) hv += w[hld.vertex(i)];\n            });\n         \
    \   hld.for_each_edge(u, v, [&](int a, int b) {\n                assert(a < b);\n\
    \                for (int i = a; i < b; i++) he += w[hld.vertex(i)];\n       \
    \     });\n            assert(hv == sv);\n            assert(he == se);\n    \
    \    }\n        {\n            long long na = 1, nb = 0;\n            for (int\
    \ x : path) {\n                nb = (fa[x] * nb + fb[x]) % MOD;\n            \
    \    na = fa[x] * na % MOD;\n            }\n            long long nea = 1, neb\
    \ = 0;\n            for (int x : path) {\n                if (x == l) continue;\n\
    \                neb = (fa[x] * neb + fb[x]) % MOD;\n                nea = fa[x]\
    \ * nea % MOD;\n            }\n            auto apply = [&](long long &ca, long\
    \ long &cb, int a, int b) {\n                if (a < b) {\n                  \
    \  for (int i = a; i < b; i++) {\n                        int x = hld.vertex(i);\n\
    \                        cb = (fa[x] * cb + fb[x]) % MOD;\n                  \
    \      ca = fa[x] * ca % MOD;\n                    }\n                } else {\n\
    \                    for (int i = a - 1; i >= b; i--) {\n                    \
    \    int x = hld.vertex(i);\n                        cb = (fa[x] * cb + fb[x])\
    \ % MOD;\n                        ca = fa[x] * ca % MOD;\n                   \
    \ }\n                }\n            };\n            long long ha = 1, hb = 0;\n\
    \            hld.for_each_vertex_noncommutative(\n                u, v, [&](int\
    \ a, int b) { apply(ha, hb, a, b); });\n            assert(ha == na && hb == nb);\n\
    \            long long hea = 1, heb = 0;\n            hld.for_each_edge_noncommutative(\n\
    \                u, v, [&](int a, int b) { apply(hea, heb, a, b); });\n      \
    \      assert(hea == nea && heb == neb);\n        }\n        {\n            long\
    \ long sv = 0, se = 0;\n            for (int x = 0; x < N; x++) {\n          \
    \      bool sub = false;\n                for (int y = x; y != -1; y = par[y])\
    \ sub |= (y == u);\n                if (!sub) continue;\n                sv +=\
    \ w[x];\n                if (x != u) se += w[x];\n            }\n            long\
    \ long hv = 0, he = 0;\n            hld.for_each_vertex_in_subtree(u, [&](int\
    \ a, int b) {\n                for (int i = a; i < b; i++) hv += w[hld.vertex(i)];\n\
    \            });\n            hld.for_each_edge_in_subtree(u, [&](int a, int b)\
    \ {\n                assert(a < b);\n                for (int i = a; i < b; i++)\
    \ he += w[hld.vertex(i)];\n            });\n            assert(hv == sv);\n  \
    \          assert(he == se);\n            auto [a, b] = hld.subtree(u);\n    \
    \        assert(a == hld.index(u) && b - a == 1 + [&] {\n                int c\
    \ = 0;\n                for (int x = 0; x < N; x++) {\n                    bool\
    \ sub = false;\n                    for (int y = par[x]; y != -1; y = par[y])\
    \ sub |= (y == u);\n                    c += sub;\n                }\n       \
    \         return c;\n            }());\n        }\n    }\n}\nint main() {\n  \
    \  std::mt19937 rng(7959);\n    for (int trial = 0; trial < 100; trial++) stress(rng);\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#include \"graph/heavy_light_decomposition.hpp\"\nconstexpr\
    \ long long MOD = 998244353;\nvoid stress(std::mt19937 &rng) {\n    const int\
    \ N = 1 + rng() % 40;\n    const int root = rng() % N;\n    heavy_light_decomposition\
    \ hld(N, root);\n    std::vector<std::vector<int>> g(N);\n    for (int v = 1;\
    \ v < N; v++) {\n        int p = rng() % v;\n        hld.add_edge(v, p);\n   \
    \     g[v].push_back(p);\n        g[p].push_back(v);\n    }\n    hld.build();\n\
    \    std::vector<int> par(N, -1), dep(N, 0);\n    auto dfs = [&](auto dfs, int\
    \ v, int p) -> void {\n        for (int c : g[v]) {\n            if (c == p) continue;\n\
    \            par[c] = v;\n            dep[c] = dep[v] + 1;\n            dfs(dfs,\
    \ c, v);\n        }\n    };\n    dfs(dfs, root, -1);\n    for (int i = 0; i +\
    \ 1 < N; i++) {\n        // i \u756A\u76EE\u306E\u8FBA\u306F (i + 1, p) \u3067\
    \ p < i + 1\n        int v = i + 1, p = -1;\n        for (int x : g[v]) if (x\
    \ < v) p = x;\n        int child = par[v] == p ? v : p;\n        assert(hld.edge_index(i)\
    \ == hld.index(child));\n    }\n    auto naive_path = [&](int u, int v) {\n  \
    \      std::vector<int> a, b;\n        while (u != v) {\n            if (dep[u]\
    \ >= dep[v]) {\n                a.push_back(u);\n                u = par[u];\n\
    \            } else {\n                b.push_back(v);\n                v = par[v];\n\
    \            }\n        }\n        a.push_back(u);\n        a.insert(a.end(),\
    \ b.rbegin(), b.rend());\n        return a;\n    };\n    std::vector<long long>\
    \ w(N), fa(N), fb(N);\n    for (int v = 0; v < N; v++) {\n        w[v] = rng()\
    \ % 100;\n        fa[v] = rng() % MOD;\n        fb[v] = rng() % MOD;\n    }\n\
    \    for (int i = 0; i < N; i++) {\n        assert(hld.vertex(hld.index(i)) ==\
    \ i);\n        assert(hld.depth(i) == dep[i]);\n        assert(hld.parent(i) ==\
    \ par[i]);\n    }\n    for (int q = 0; q < 300; q++) {\n        int u = rng()\
    \ % N, v = rng() % N;\n        std::vector<int> path = naive_path(u, v);\n   \
    \     int l = -1;\n        for (int x : path) {\n            if (l == -1 || dep[x]\
    \ < dep[l]) l = x;\n        }\n        assert(hld.lca(u, v) == l);\n        assert(hld.dist(u,\
    \ v) == (int)path.size() - 1);\n        int k = rng() % (path.size() + 2) - 1;\n\
    \        if (0 <= k && k < (int)path.size()) {\n            assert(hld.jump(u,\
    \ v, k) == path[k]);\n        } else {\n            assert(hld.jump(u, v, k) ==\
    \ -1);\n        }\n        {\n            int x = rng() % N;\n            bool\
    \ on = false;\n            for (int y : path) on |= (y == x);\n            assert(hld.on_path(u,\
    \ v, x) == on);\n            bool sub = false;\n            for (int y = x; y\
    \ != -1; y = par[y]) sub |= (y == u);\n            assert(hld.in_subtree(u, x)\
    \ == sub);\n            int kk = rng() % (dep[x] + 2) - 1;\n            int y\
    \ = x;\n            for (int i = 0; i < kk && y != -1; i++) y = par[y];\n    \
    \        assert(hld.la(x, kk) == (kk < 0 ? -1 : y));\n        }\n        {\n \
    \           long long sv = 0, se = 0;\n            for (int x : path) sv += w[x];\n\
    \            for (int x : path) {\n                if (x != l) se += w[x];\n \
    \           }\n            long long hv = 0, he = 0;\n            hld.for_each_vertex(u,\
    \ v, [&](int a, int b) {\n                assert(a < b);\n                for\
    \ (int i = a; i < b; i++) hv += w[hld.vertex(i)];\n            });\n         \
    \   hld.for_each_edge(u, v, [&](int a, int b) {\n                assert(a < b);\n\
    \                for (int i = a; i < b; i++) he += w[hld.vertex(i)];\n       \
    \     });\n            assert(hv == sv);\n            assert(he == se);\n    \
    \    }\n        {\n            long long na = 1, nb = 0;\n            for (int\
    \ x : path) {\n                nb = (fa[x] * nb + fb[x]) % MOD;\n            \
    \    na = fa[x] * na % MOD;\n            }\n            long long nea = 1, neb\
    \ = 0;\n            for (int x : path) {\n                if (x == l) continue;\n\
    \                neb = (fa[x] * neb + fb[x]) % MOD;\n                nea = fa[x]\
    \ * nea % MOD;\n            }\n            auto apply = [&](long long &ca, long\
    \ long &cb, int a, int b) {\n                if (a < b) {\n                  \
    \  for (int i = a; i < b; i++) {\n                        int x = hld.vertex(i);\n\
    \                        cb = (fa[x] * cb + fb[x]) % MOD;\n                  \
    \      ca = fa[x] * ca % MOD;\n                    }\n                } else {\n\
    \                    for (int i = a - 1; i >= b; i--) {\n                    \
    \    int x = hld.vertex(i);\n                        cb = (fa[x] * cb + fb[x])\
    \ % MOD;\n                        ca = fa[x] * ca % MOD;\n                   \
    \ }\n                }\n            };\n            long long ha = 1, hb = 0;\n\
    \            hld.for_each_vertex_noncommutative(\n                u, v, [&](int\
    \ a, int b) { apply(ha, hb, a, b); });\n            assert(ha == na && hb == nb);\n\
    \            long long hea = 1, heb = 0;\n            hld.for_each_edge_noncommutative(\n\
    \                u, v, [&](int a, int b) { apply(hea, heb, a, b); });\n      \
    \      assert(hea == nea && heb == neb);\n        }\n        {\n            long\
    \ long sv = 0, se = 0;\n            for (int x = 0; x < N; x++) {\n          \
    \      bool sub = false;\n                for (int y = x; y != -1; y = par[y])\
    \ sub |= (y == u);\n                if (!sub) continue;\n                sv +=\
    \ w[x];\n                if (x != u) se += w[x];\n            }\n            long\
    \ long hv = 0, he = 0;\n            hld.for_each_vertex_in_subtree(u, [&](int\
    \ a, int b) {\n                for (int i = a; i < b; i++) hv += w[hld.vertex(i)];\n\
    \            });\n            hld.for_each_edge_in_subtree(u, [&](int a, int b)\
    \ {\n                assert(a < b);\n                for (int i = a; i < b; i++)\
    \ he += w[hld.vertex(i)];\n            });\n            assert(hv == sv);\n  \
    \          assert(he == se);\n            auto [a, b] = hld.subtree(u);\n    \
    \        assert(a == hld.index(u) && b - a == 1 + [&] {\n                int c\
    \ = 0;\n                for (int x = 0; x < N; x++) {\n                    bool\
    \ sub = false;\n                    for (int y = par[x]; y != -1; y = par[y])\
    \ sub |= (y == u);\n                    c += sub;\n                }\n       \
    \         return c;\n            }());\n        }\n    }\n}\nint main() {\n  \
    \  std::mt19937 rng(7959);\n    for (int trial = 0; trial < 100; trial++) stress(rng);\n\
    \    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - graph/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/unit/heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 02:29:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/unit/heavy_light_decomposition.test.cpp
- /verify/test/unit/heavy_light_decomposition.test.cpp.html
title: test/unit/heavy_light_decomposition.test.cpp
---
