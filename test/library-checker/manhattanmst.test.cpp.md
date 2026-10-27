---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_argmin.hpp
    title: 'Monoid: Argmin'
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/library-checker/manhattanmst.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include <atcoder/dsu>\n\
    #include <iostream>\n\n#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <tuple>\n#include <vector>\n\n\
    #line 2 \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\n\n#line 2 \"\
    algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept semigroup\
    \ = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n\
    \    { M::e() } -> std::same_as<typename M::S>;\n};\ntemplate <class G>\nconcept\
    \ group = monoid<G> && requires(typename G::S a) {\n    { G::inv(a) } -> std::same_as<typename\
    \ G::S>;\n};\ntemplate <class A>\nconcept action = requires(typename A::F f, typename\
    \ A::F g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n  \
    \  { A::id() } -> std::same_as<typename A::F>;\n    { A::composition_commutative\
    \ } -> std::convertible_to<bool>;\n};\ntemplate <class A>\nconcept acted_monoid\
    \ = monoid<A> && action<A> && requires(typename A::S x, typename A::F f) {\n \
    \   { A::mapping(f, x) } -> std::same_as<typename A::S>;\n};\ntemplate <class\
    \ R>\nconcept semiring = requires(typename R::S a, typename R::S b) {\n    { R::add(a,\
    \ b) } -> std::same_as<typename R::S>;\n    { R::zero() } -> std::same_as<typename\
    \ R::S>;\n    { R::mul(a, b) } -> std::same_as<typename R::S>;\n    { R::one()\
    \ } -> std::same_as<typename R::S>;\n};\n#line 5 \"datastructure/segtree.hpp\"\
    \ntemplate <monoid M>\nusing segtree = atcoder::segtree<typename M::S, M::op,\
    \ M::e>;\n#line 2 \"algebra/monoid_argmin.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_argmin {\n    struct S {\n        T val;\n        int id;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return a.val\
    \ < b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static S e()\
    \ {\n        return {std::numeric_limits<T>::max(), -1};\n    }\n};\n#line 10\
    \ \"graph/manhattan_mst.hpp\"\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(y.size())\
    \ == n);\n    std::vector<int> id(n);\n    std::iota(id.begin(), id.end(), 0);\n\
    \    std::vector<int> y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n\
    \    for (int a = 0; a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n  \
    \          for (int c = 0; c < 2; c++) {\n                sort(id.begin(), id.end(),\
    \ [&](int i, int j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i]\
    \ == y[j])\n                        return i < j;\n                    if (y[i]\
    \ - x[i] == y[j] - x[j]) return y[i] > y[j];\n                    return y[i]\
    \ - x[i] < y[j] - x[j];\n                });\n                std::vector<T> _y\
    \ = y;\n                std::sort(_y.begin(), _y.end());\n                for\
    \ (int i = 0; i < n; i++) {\n                    y_id[i] = std::lower_bound(_y.begin(),\
    \ _y.end(), y[i]) -\n                              _y.begin();\n             \
    \   }\n                segtree<monoid_argmin<T>> segt(n);\n                for\
    \ (int i : id) {\n                    auto p = segt.prod(y_id[i], n);\n      \
    \              if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}\n#line\
    \ 7 \"test/library-checker/manhattanmst.test.cpp\"\nint main() {\n    int n;\n\
    \    std::cin >> n;\n    std::vector<long long> x(n), y(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n    }\n\n    atcoder::dsu\
    \ uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int, int>> ans;\n\
    \    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (!uf.same(u, v))\
    \ {\n            uf.merge(u, v);\n            sum += w;\n            ans.emplace_back(u,\
    \ v);\n        }\n    }\n    std::cout << sum << '\\n';\n    for (auto [u, v]\
    \ : ans) {\n        std::cout << u << ' ' << v << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ <atcoder/dsu>\n#include <iostream>\n\n#include \"graph/manhattan_mst.hpp\"\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> x(n),\
    \ y(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n\
    \    }\n\n    atcoder::dsu uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (!uf.same(u,\
    \ v)) {\n            uf.merge(u, v);\n            sum += w;\n            ans.emplace_back(u,\
    \ v);\n        }\n    }\n    std::cout << sum << '\\n';\n    for (auto [u, v]\
    \ : ans) {\n        std::cout << u << ' ' << v << '\\n';\n    }\n}"
  dependsOn:
  - graph/manhattan_mst.hpp
  - datastructure/segtree.hpp
  - algebra/concept.hpp
  - algebra/monoid_argmin.hpp
  isVerificationFile: true
  path: test/library-checker/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/manhattanmst.test.cpp
- /verify/test/library-checker/manhattanmst.test.cpp.html
title: test/library-checker/manhattanmst.test.cpp
---
