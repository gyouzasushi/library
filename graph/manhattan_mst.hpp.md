---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':question:'
    path: algebra/monoid_argmin.hpp
    title: 'Monoid: Argmin'
  - icon: ':question:'
    path: datastructure/segtree.hpp
    title: Segment Tree (monoid wrapper)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\n#include <tuple>\n#include <vector>\n\n#line\
    \ 2 \"datastructure/segtree.hpp\"\n#include <atcoder/segtree>\n\n#line 2 \"algebra/concept.hpp\"\
    \n#include <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename\
    \ M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G>\
    \ && requires(typename G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 5 \"datastructure/segtree.hpp\"\
    \ntemplate <monoid M>\nusing segtree = atcoder::segtree<typename M::S, M::op,\
    \ M::e>;\n#line 2 \"algebra/monoid_argmin.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_argmin {\n    struct S {\n        T val;\n        int id;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.val != b.val) return a.val\
    \ < b.val ? a : b;\n        return a.id < b.id ? a : b;\n    }\n    static S e()\
    \ {\n        return {std::numeric_limits<T>::max(), -1};\n    }\n};\n#line 10\
    \ \"graph/manhattan_mst.hpp\"\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(y.size())\
    \ == n);\n    std::vector<int> id(n);\n    std::ranges::iota(id, 0);\n    std::vector<int>\
    \ y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0;\
    \ a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n            for (int c\
    \ = 0; c < 2; c++) {\n                sort(id.begin(), id.end(), [&](int i, int\
    \ j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n\
    \                        return i < j;\n                    if (y[i] - x[i] ==\
    \ y[j] - x[j]) return y[i] > y[j];\n                    return y[i] - x[i] < y[j]\
    \ - x[j];\n                });\n                std::vector<T> _y = y;\n     \
    \           std::ranges::sort(_y);\n                for (int i = 0; i < n; i++)\
    \ {\n                    y_id[i] = std::ranges::lower_bound(_y, y[i]) - _y.begin();\n\
    \                }\n                segtree<monoid_argmin<T>> segt(n);\n     \
    \           for (int i : id) {\n                    auto p = segt.prod(y_id[i],\
    \ n);\n                    if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <tuple>\n#include <vector>\n\n#include \"datastructure/segtree.hpp\"\n\
    #include \"algebra/monoid_argmin.hpp\"\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(y.size())\
    \ == n);\n    std::vector<int> id(n);\n    std::ranges::iota(id, 0);\n    std::vector<int>\
    \ y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0;\
    \ a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n            for (int c\
    \ = 0; c < 2; c++) {\n                sort(id.begin(), id.end(), [&](int i, int\
    \ j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n\
    \                        return i < j;\n                    if (y[i] - x[i] ==\
    \ y[j] - x[j]) return y[i] > y[j];\n                    return y[i] - x[i] < y[j]\
    \ - x[j];\n                });\n                std::vector<T> _y = y;\n     \
    \           std::ranges::sort(_y);\n                for (int i = 0; i < n; i++)\
    \ {\n                    y_id[i] = std::ranges::lower_bound(_y, y[i]) - _y.begin();\n\
    \                }\n                segtree<monoid_argmin<T>> segt(n);\n     \
    \           for (int i : id) {\n                    auto p = segt.prod(y_id[i],\
    \ n);\n                    if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}"
  dependsOn:
  - datastructure/segtree.hpp
  - algebra/concept.hpp
  - algebra/monoid_argmin.hpp
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/manhattanmst.test.cpp
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan MST
---

### 概要
- 2次元平面上にある $N$ 個の点に対して、2点間の距離をマンハッタン距離で定義したときの最小全域木を求める。
  
### 使い方
- `manhattan_mst(x, y)`: 最小全域木に含まれ得る $O(N)$ 本の辺 `(u, v, w)` を、重みの昇順で返す。 