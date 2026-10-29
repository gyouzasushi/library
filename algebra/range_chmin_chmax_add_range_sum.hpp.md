---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit/segtree_beats.test.cpp
    title: test/unit/segtree_beats.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/range_chmin_chmax_add_range_sum.hpp\"\n#include\
    \ <algorithm>\n#include <limits>\ntemplate <class T>\nstruct range_chmin_chmax_add_range_sum\
    \ {\n    struct S {\n        T sum, min, max, min2, max2;\n        int minc, maxc,\
    \ len;\n        bool fail;\n    };\n    struct F {\n        T add, chmin, chmax;\n\
    \    };\n    static S op(S a, S b) {\n        if (a.len == 0) return b;\n    \
    \    if (b.len == 0) return a;\n        S c;\n        c.sum = a.sum + b.sum;\n\
    \        c.len = a.len + b.len;\n        c.fail = false;\n        if (a.max >\
    \ b.max) {\n            c.max = a.max;\n            c.maxc = a.maxc;\n       \
    \     c.max2 = std::max(a.max2, b.max);\n        } else if (a.max < b.max) {\n\
    \            c.max = b.max;\n            c.maxc = b.maxc;\n            c.max2\
    \ = std::max(a.max, b.max2);\n        } else {\n            c.max = a.max;\n \
    \           c.maxc = a.maxc + b.maxc;\n            c.max2 = std::max(a.max2, b.max2);\n\
    \        }\n        if (a.min < b.min) {\n            c.min = a.min;\n       \
    \     c.minc = a.minc;\n            c.min2 = std::min(a.min2, b.min);\n      \
    \  } else if (a.min > b.min) {\n            c.min = b.min;\n            c.minc\
    \ = b.minc;\n            c.min2 = std::min(a.min, b.min2);\n        } else {\n\
    \            c.min = a.min;\n            c.minc = a.minc + b.minc;\n         \
    \   c.min2 = std::min(a.min2, b.min2);\n        }\n        return c;\n    }\n\
    \    static S e() {\n        return {T(0), inf, ninf, inf, ninf, 0, 0, 0, false};\n\
    \    }\n    static S mapping(F f, S x) {\n        if (x.len == 0) return x;\n\
    \        if (f.add != T(0)) {\n            x.sum += f.add * x.len;\n         \
    \   x.min += f.add;\n            x.max += f.add;\n            if (x.min2 != inf)\
    \ x.min2 += f.add;\n            if (x.max2 != ninf) x.max2 += f.add;\n       \
    \ }\n        if (f.chmin < x.max) {\n            if (f.chmin <= x.min) {\n   \
    \             fill(x, f.chmin);\n            } else if (x.max2 < f.chmin) {\n\
    \                x.sum += (f.chmin - x.max) * x.maxc;\n                if (x.min2\
    \ == x.max) x.min2 = f.chmin;\n                x.max = f.chmin;\n            }\
    \ else {\n                x.fail = true;\n                return x;\n        \
    \    }\n        }\n        if (f.chmax > x.min) {\n            if (f.chmax >=\
    \ x.max) {\n                fill(x, f.chmax);\n            } else if (f.chmax\
    \ < x.min2) {\n                x.sum += (f.chmax - x.min) * x.minc;\n        \
    \        if (x.max2 == x.min) x.max2 = f.chmax;\n                x.min = f.chmax;\n\
    \            } else {\n                x.fail = true;\n            }\n       \
    \ }\n        return x;\n    }\n    static F composition(F f, F g) {\n        T\
    \ chmin = g.chmin == inf ? inf : g.chmin + f.add;\n        T chmax = g.chmax ==\
    \ ninf ? ninf : g.chmax + f.add;\n        return {f.add + g.add, std::min(chmin,\
    \ f.chmin), std::max(std::min(chmax, f.chmin), f.chmax)};\n    }\n    static F\
    \ id() {\n        return {T(0), inf, ninf};\n    }\n    static constexpr bool\
    \ composition_commutative = false;\n    static S from(T v) {\n        return {v,\
    \ v, v, inf, ninf, 1, 1, 1, false};\n    }\n    static F chmin(T x) {\n      \
    \  return {T(0), x, ninf};\n    }\n    static F chmax(T x) {\n        return {T(0),\
    \ inf, x};\n    }\n    static F add(T x) {\n        return {x, inf, ninf};\n \
    \   }\n    static F assign(T x) {\n        return {T(0), x, x};\n    }\n\nprivate:\n\
    \    static constexpr T inf = std::numeric_limits<T>::max();\n    static constexpr\
    \ T ninf = std::numeric_limits<T>::lowest();\n    static void fill(S& x, T v)\
    \ {\n        x.sum = v * x.len;\n        x.min = x.max = v;\n        x.min2 =\
    \ inf;\n        x.max2 = ninf;\n        x.minc = x.maxc = x.len;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\ntemplate <class T>\n\
    struct range_chmin_chmax_add_range_sum {\n    struct S {\n        T sum, min,\
    \ max, min2, max2;\n        int minc, maxc, len;\n        bool fail;\n    };\n\
    \    struct F {\n        T add, chmin, chmax;\n    };\n    static S op(S a, S\
    \ b) {\n        if (a.len == 0) return b;\n        if (b.len == 0) return a;\n\
    \        S c;\n        c.sum = a.sum + b.sum;\n        c.len = a.len + b.len;\n\
    \        c.fail = false;\n        if (a.max > b.max) {\n            c.max = a.max;\n\
    \            c.maxc = a.maxc;\n            c.max2 = std::max(a.max2, b.max);\n\
    \        } else if (a.max < b.max) {\n            c.max = b.max;\n           \
    \ c.maxc = b.maxc;\n            c.max2 = std::max(a.max, b.max2);\n        } else\
    \ {\n            c.max = a.max;\n            c.maxc = a.maxc + b.maxc;\n     \
    \       c.max2 = std::max(a.max2, b.max2);\n        }\n        if (a.min < b.min)\
    \ {\n            c.min = a.min;\n            c.minc = a.minc;\n            c.min2\
    \ = std::min(a.min2, b.min);\n        } else if (a.min > b.min) {\n          \
    \  c.min = b.min;\n            c.minc = b.minc;\n            c.min2 = std::min(a.min,\
    \ b.min2);\n        } else {\n            c.min = a.min;\n            c.minc =\
    \ a.minc + b.minc;\n            c.min2 = std::min(a.min2, b.min2);\n        }\n\
    \        return c;\n    }\n    static S e() {\n        return {T(0), inf, ninf,\
    \ inf, ninf, 0, 0, 0, false};\n    }\n    static S mapping(F f, S x) {\n     \
    \   if (x.len == 0) return x;\n        if (f.add != T(0)) {\n            x.sum\
    \ += f.add * x.len;\n            x.min += f.add;\n            x.max += f.add;\n\
    \            if (x.min2 != inf) x.min2 += f.add;\n            if (x.max2 != ninf)\
    \ x.max2 += f.add;\n        }\n        if (f.chmin < x.max) {\n            if\
    \ (f.chmin <= x.min) {\n                fill(x, f.chmin);\n            } else\
    \ if (x.max2 < f.chmin) {\n                x.sum += (f.chmin - x.max) * x.maxc;\n\
    \                if (x.min2 == x.max) x.min2 = f.chmin;\n                x.max\
    \ = f.chmin;\n            } else {\n                x.fail = true;\n         \
    \       return x;\n            }\n        }\n        if (f.chmax > x.min) {\n\
    \            if (f.chmax >= x.max) {\n                fill(x, f.chmax);\n    \
    \        } else if (f.chmax < x.min2) {\n                x.sum += (f.chmax - x.min)\
    \ * x.minc;\n                if (x.max2 == x.min) x.max2 = f.chmax;\n        \
    \        x.min = f.chmax;\n            } else {\n                x.fail = true;\n\
    \            }\n        }\n        return x;\n    }\n    static F composition(F\
    \ f, F g) {\n        T chmin = g.chmin == inf ? inf : g.chmin + f.add;\n     \
    \   T chmax = g.chmax == ninf ? ninf : g.chmax + f.add;\n        return {f.add\
    \ + g.add, std::min(chmin, f.chmin), std::max(std::min(chmax, f.chmin), f.chmax)};\n\
    \    }\n    static F id() {\n        return {T(0), inf, ninf};\n    }\n    static\
    \ constexpr bool composition_commutative = false;\n    static S from(T v) {\n\
    \        return {v, v, v, inf, ninf, 1, 1, 1, false};\n    }\n    static F chmin(T\
    \ x) {\n        return {T(0), x, ninf};\n    }\n    static F chmax(T x) {\n  \
    \      return {T(0), inf, x};\n    }\n    static F add(T x) {\n        return\
    \ {x, inf, ninf};\n    }\n    static F assign(T x) {\n        return {T(0), x,\
    \ x};\n    }\n\nprivate:\n    static constexpr T inf = std::numeric_limits<T>::max();\n\
    \    static constexpr T ninf = std::numeric_limits<T>::lowest();\n    static void\
    \ fill(S& x, T v) {\n        x.sum = v * x.len;\n        x.min = x.max = v;\n\
    \        x.min2 = inf;\n        x.max2 = ninf;\n        x.minc = x.maxc = x.len;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/range_chmin_chmax_add_range_sum.hpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/segtree_beats.test.cpp
  - test/library-checker/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: algebra/range_chmin_chmax_add_range_sum.hpp
layout: document
title: 'Acted Monoid: Range Chmin Chmax Add Range Sum'
---

### 概要
- 区間 chmin・chmax・加算・代入と、区間の和・最小値・最大値。`segtree_beats<range_chmin_chmax_add_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum, min, max, min2, max2; int minc, maxc, len; bool fail}`, `F = {T add, chmin, chmax}`
- `from(v)`: 値 `v` 1 個分の要素を返す。初期化や一点更新ではこれで `S` を作る。
- `chmin(x)`: `a[i]` を `min(a[i], x)` にする作用を返す。
- `chmax(x)`: `a[i]` を `max(a[i], x)` にする作用を返す。
- `add(x)`: `a[i]` を `a[i] + x` にする作用を返す。
- `assign(x)`: `a[i]` を `x` にする作用を返す。
- `prod(l, r).sum`, `.min`, `.max` が区間の和、最小値、最大値。

### 制約
- 途中の値と和が `T` の範囲に収まる

### 計算量
- `apply`, `prod`: 償却 $\mathcal{O}(\log^2 N)$

### 問題例
Library Checker - Range Chmin Chmax Add Range Sum（[問題](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)）

```cpp
#include <iostream>

#include "algebra/range_chmin_chmax_add_range_sum.hpp"
#include "datastructure/segtree_beats.hpp"
int main() {
    using A = range_chmin_chmax_add_range_sum<long long>;
    int n, q;
    std::cin >> n >> q;
    std::vector<A::S> a(n);
    for (auto& x : a) {
        long long v;
        std::cin >> v;
        x = A::from(v);
    }
    segtree_beats<A> seg(a);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 3) {
            std::cout << seg.prod(l, r).sum << '\n';
            continue;
        }
        long long b;
        std::cin >> b;
        if (t == 0) seg.apply(l, r, A::chmin(b));
        if (t == 1) seg.apply(l, r, A::chmax(b));
        if (t == 2) seg.apply(l, r, A::add(b));
    }
}
```
