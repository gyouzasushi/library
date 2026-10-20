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
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/library-checker/tree_path_composite_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\
    #include <atcoder/modint>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"graph/rerooting.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <type_traits>\n#line 6 \"graph/rerooting.hpp\"\n#include <variant>\n\
    #line 8 \"graph/rerooting.hpp\"\ntemplate <class R>\nstruct rerooting {\npublic:\n\
    \    using T = typename R::T;\n    using M = typename R::M;\n    using E = typename\
    \ R::E;\n    using V = typename R::V;\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::put_edge), const T&, const E&, int, int>,\n                  \"\
    R::put_edge must work as M(const T&, const E&, int u, int v)\");\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::merge), const M&, const M&>,\n                  \"R::merge must\
    \ work as M(const M&, const M&)\");\n    static_assert(std::is_invocable_r_v<M,\
    \ decltype(R::e)>, \"R::e must work as M()\");\n    static_assert(std::is_invocable_r_v<T,\
    \ decltype(R::put_vertex), const M&, const V&, int>,\n                  \"R::put_vertex\
    \ must work as T(const M&, const V&, int v)\");\n\n    rerooting() {\n    }\n\
    \    explicit rerooting(int n) : rerooting(std::vector<V>(n)) {\n    }\n    explicit\
    \ rerooting(std::vector<V> a) : _n(int(a.size())), vdata(std::move(a)), g(_n)\
    \ {\n    }\n    int add_edge(int u, int v, E w = E()) {\n        assert(0 <= u\
    \ && u < _n);\n        assert(0 <= v && v < _n);\n        int i = int(edges.size());\n\
    \        edges.emplace_back(u, v);\n        edata.push_back(std::move(w));\n \
    \       g[u].push_back(i);\n        g[v].push_back(i);\n        return i;\n  \
    \  }\n    void solve() {\n        assert(int(edges.size()) == _n - 1);\n     \
    \   _dp.assign(_n, T());\n        _agg.assign(_n, R::e());\n        _sub.assign(2\
    \ * (_n - 1), T());\n        std::vector<int> order, par(_n, -1), pe(_n, -1);\n\
    \        order.reserve(_n);\n        order.push_back(0);\n        for (int k =\
    \ 0; k < _n; k++) {\n            int v = order[k];\n            for (int i : g[v])\
    \ {\n                int to = other(i, v);\n                if (to == par[v])\
    \ continue;\n                par[to] = v;\n                pe[to] = i;\n     \
    \           order.push_back(to);\n            }\n        }\n        // bottom-up:\
    \ sub(par[v] -> v)\n        for (int k = _n - 1; k > 0; k--) {\n            int\
    \ v = order[k];\n            M acc = R::e();\n            for (int i : g[v]) {\n\
    \                int to = other(i, v);\n                if (to == par[v]) continue;\n\
    \                acc = R::merge(acc, R::put_edge(_sub[dir(i, v)], edata[i], v,\
    \ to));\n            }\n            _sub[dir(pe[v], par[v])] = R::put_vertex(acc,\
    \ vdata[v], v);\n        }\n        // top-down: sub(v -> par[v]) is ready when\
    \ v is visited\n        std::vector<M> pre, suf;\n        for (int v : order)\
    \ {\n            int deg = int(g[v].size());\n            pre.assign(deg + 1,\
    \ R::e());\n            suf.assign(deg + 1, R::e());\n            for (int j =\
    \ 0; j < deg; j++) {\n                int i = g[v][j], to = other(i, v);\n   \
    \             pre[j + 1] = R::merge(pre[j], R::put_edge(_sub[dir(i, v)], edata[i],\
    \ v, to));\n            }\n            for (int j = deg; j > 0; j--) {\n     \
    \           int i = g[v][j - 1], to = other(i, v);\n                suf[j - 1]\
    \ = R::merge(R::put_edge(_sub[dir(i, v)], edata[i], v, to), suf[j]);\n       \
    \     }\n            _agg[v] = pre[deg];\n            _dp[v] = R::put_vertex(_agg[v],\
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
    \ 2 * i + (edges[i].first == u ? 0 : 1);\n    }\n};\n#line 8 \"test/library-checker/tree_path_composite_sum.test.cpp\"\
    \nusing mint = atcoder::modint998244353;\nstruct R {\n    struct T {\n       \
    \ mint sum;\n        int cnt;\n    };\n    using M = T;\n    using E = std::pair<mint,\
    \ mint>;  // f(x) = b x + c\n    using V = mint;\n    static M put_edge(const\
    \ T& x, const E& f, int, int) {\n        return {f.first * x.sum + f.second *\
    \ x.cnt, x.cnt};\n    }\n    static M merge(const M& a, const M& b) {\n      \
    \  return {a.sum + b.sum, a.cnt + b.cnt};\n    }\n    static M e() {\n       \
    \ return {0, 0};\n    }\n    static T put_vertex(const M& acc, const V& a, int)\
    \ {\n        return {acc.sum + a, acc.cnt + 1};\n    }\n};\nint main() {\n   \
    \ int n;\n    std::cin >> n;\n    std::vector<mint> a(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int x;\n        std::cin >> x;\n        a[i] = mint::raw(x);\n\
    \    }\n    rerooting<R> rr(a);\n    for (int i = 0; i < n - 1; i++) {\n     \
    \   int u, v, b, c;\n        std::cin >> u >> v >> b >> c;\n        rr.add_edge(u,\
    \ v, {mint::raw(b), mint::raw(c)});\n    }\n    rr.solve();\n    for (int i =\
    \ 0; i < n; i++) {\n        std::cout << rr.dp(i).sum.val() << (i + 1 < n ? '\
    \ ' : '\\n');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include <atcoder/modint>\n#include <iostream>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"graph/rerooting.hpp\"\nusing mint = atcoder::modint998244353;\n\
    struct R {\n    struct T {\n        mint sum;\n        int cnt;\n    };\n    using\
    \ M = T;\n    using E = std::pair<mint, mint>;  // f(x) = b x + c\n    using V\
    \ = mint;\n    static M put_edge(const T& x, const E& f, int, int) {\n       \
    \ return {f.first * x.sum + f.second * x.cnt, x.cnt};\n    }\n    static M merge(const\
    \ M& a, const M& b) {\n        return {a.sum + b.sum, a.cnt + b.cnt};\n    }\n\
    \    static M e() {\n        return {0, 0};\n    }\n    static T put_vertex(const\
    \ M& acc, const V& a, int) {\n        return {acc.sum + a, acc.cnt + 1};\n   \
    \ }\n};\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int x;\n        std::cin >> x;\n \
    \       a[i] = mint::raw(x);\n    }\n    rerooting<R> rr(a);\n    for (int i =\
    \ 0; i < n - 1; i++) {\n        int u, v, b, c;\n        std::cin >> u >> v >>\
    \ b >> c;\n        rr.add_edge(u, v, {mint::raw(b), mint::raw(c)});\n    }\n \
    \   rr.solve();\n    for (int i = 0; i < n; i++) {\n        std::cout << rr.dp(i).sum.val()\
    \ << (i + 1 < n ? ' ' : '\\n');\n    }\n}\n"
  dependsOn:
  - graph/rerooting.hpp
  isVerificationFile: true
  path: test/library-checker/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 21:57:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/tree_path_composite_sum.test.cpp
- /verify/test/library-checker/tree_path_composite_sum.test.cpp.html
title: test/library-checker/tree_path_composite_sum.test.cpp
---
