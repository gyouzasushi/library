---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/manhattanmst.test.cpp
    title: test/library-checker/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <vector>\n\n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#line\
    \ 7 \"atcoder/segtree.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\n\
    int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n)\
    \ {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9\
    \ \"atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0) {}\n \
    \   explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 11 \"graph/manhattan_mst.hpp\"\ntemplate <typename T>\nstruct\
    \ manhattan_mst_S {\n    T val;\n    int id;\n};\ntemplate <typename T>\nmanhattan_mst_S<T>\
    \ manhattan_mst_op(manhattan_mst_S<T> a,\n                                   \
    \ manhattan_mst_S<T> b) {\n    return a.val < b.val ? a : b;\n}\ntemplate <typename\
    \ T>\nmanhattan_mst_S<T> manhattan_mst_e() {\n    return {std::numeric_limits<T>::max(),\
    \ -1};\n}\ntemplate <typename T>\nstd::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T>\
    \ x,\n                                                   std::vector<T> y) {\n\
    \    int n = x.size();\n    assert(int(x.size()) == n && int(y.size()) == n);\n\
    \    std::vector<int> id(n);\n    std::iota(id.begin(), id.end(), 0);\n    std::vector<int>\
    \ y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0;\
    \ a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n            for (int c\
    \ = 0; c < 2; c++) {\n                sort(id.begin(), id.end(), [&](int i, int\
    \ j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n\
    \                        return i < j;\n                    if (y[i] - x[i] ==\
    \ y[j] - x[j]) return y[i] > y[j];\n                    return y[i] - x[i] < y[j]\
    \ - x[j];\n                });\n                std::vector<T> _y = y;\n     \
    \           std::sort(_y.begin(), _y.end());\n                for (int i = 0;\
    \ i < n; i++) {\n                    y_id[i] = std::lower_bound(_y.begin(), _y.end(),\
    \ y[i]) -\n                              _y.begin();\n                }\n    \
    \            atcoder::segtree<manhattan_mst_S<T>, manhattan_mst_op<T>,\n     \
    \                            manhattan_mst_e<T>>\n                    segt(n);\n\
    \                for (int i : id) {\n                    manhattan_mst_S<T> p\
    \ = segt.prod(y_id[i], n);\n                    if (p.id != -1) {\n          \
    \              ret.emplace_back(i, p.id, p.val - (x[i] + y[i]));\n           \
    \         }\n                    segt.set(y_id[i], {x[i] + y[i], i});\n      \
    \          }\n                std::swap(x, y);\n            }\n            for\
    \ (T &x : x) x = -x;\n        }\n        for (T &y : y) y = -y;\n    }\n    sort(ret.begin(),\
    \ ret.end(),\n         [](auto a, auto b) { return std::get<2>(a) < std::get<2>(b);\
    \ });\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <vector>\n\n#include\
    \ \"atcoder/segtree.hpp\"\ntemplate <typename T>\nstruct manhattan_mst_S {\n \
    \   T val;\n    int id;\n};\ntemplate <typename T>\nmanhattan_mst_S<T> manhattan_mst_op(manhattan_mst_S<T>\
    \ a,\n                                    manhattan_mst_S<T> b) {\n    return\
    \ a.val < b.val ? a : b;\n}\ntemplate <typename T>\nmanhattan_mst_S<T> manhattan_mst_e()\
    \ {\n    return {std::numeric_limits<T>::max(), -1};\n}\ntemplate <typename T>\n\
    std::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,\n       \
    \                                            std::vector<T> y) {\n    int n =\
    \ x.size();\n    assert(int(x.size()) == n && int(y.size()) == n);\n    std::vector<int>\
    \ id(n);\n    std::iota(id.begin(), id.end(), 0);\n    std::vector<int> y_id(n);\n\
    \    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0; a < 2; a++)\
    \ {\n        for (int b = 0; b < 2; b++) {\n            for (int c = 0; c < 2;\
    \ c++) {\n                sort(id.begin(), id.end(), [&](int i, int j) {\n   \
    \                 if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n          \
    \              return i < j;\n                    if (y[i] - x[i] == y[j] - x[j])\
    \ return y[i] > y[j];\n                    return y[i] - x[i] < y[j] - x[j];\n\
    \                });\n                std::vector<T> _y = y;\n               \
    \ std::sort(_y.begin(), _y.end());\n                for (int i = 0; i < n; i++)\
    \ {\n                    y_id[i] = std::lower_bound(_y.begin(), _y.end(), y[i])\
    \ -\n                              _y.begin();\n                }\n          \
    \      atcoder::segtree<manhattan_mst_S<T>, manhattan_mst_op<T>,\n           \
    \                      manhattan_mst_e<T>>\n                    segt(n);\n   \
    \             for (int i : id) {\n                    manhattan_mst_S<T> p = segt.prod(y_id[i],\
    \ n);\n                    if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2023-03-05 19:19:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
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