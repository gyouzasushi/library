---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/xor_basis.test.cpp
    title: test/unit/xor_basis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/xor_basis.hpp\"\n#include <algorithm>\n#include <bit>\n\
    #include <cassert>\n#include <concepts>\n#include <functional>\n#include <limits>\n\
    #include <type_traits>\n#include <vector>\ntemplate <std::integral T = long long>\
    \ struct xor_basis {\n    xor_basis() = default;\n    int size() const {\n   \
    \     return int(b.size());\n    }\n    bool insert(T x) {\n        x = reduce(x);\n\
    \        if (x == 0) return false;\n        T p = T(1) << (std::bit_width(std::make_unsigned_t<T>(x))\
    \ - 1);\n        for (T& v : b) {\n            if (v & p) v ^= x;\n        }\n\
    \        b.insert(std::ranges::lower_bound(b, x, std::greater<T>()), x);\n   \
    \     return true;\n    }\n    bool contains(T x) const {\n        return reduce(x)\
    \ == 0;\n    }\n    T max(T xor_val = 0) const {\n        check(xor_val);\n  \
    \      for (T v : b) xor_val = std::max(xor_val, T(xor_val ^ v));\n        return\
    \ xor_val;\n    }\n    T min(T xor_val = 0) const {\n        return reduce(xor_val);\n\
    \    }\n    T kth_smallest(T k, T xor_val = 0) const {\n        int r = size();\n\
    \        assert(0 <= k && (r >= std::numeric_limits<T>::digits || k < (T(1) <<\
    \ r)));\n        T x = reduce(xor_val);\n        for (int i = 0; i < r; i++) {\n\
    \            if ((k >> (r - 1 - i)) & 1) x ^= b[i];\n        }\n        return\
    \ x;\n    }\n    T kth_largest(T k, T xor_val = 0) const {\n        int r = size();\n\
    \        T all = r == 0 ? 0 : ((T(1) << (r - 1)) - 1) * 2 + 1;\n        assert(0\
    \ <= k && k <= all);\n        return kth_smallest(all - k, xor_val);\n    }\n\n\
    \  private:\n    std::vector<T> b;\n    static void check([[maybe_unused]] T x)\
    \ {\n        if constexpr (std::is_signed_v<T>) assert(x >= 0);\n    }\n    T\
    \ reduce(T x) const {\n        check(x);\n        for (T v : b) x = std::min(x,\
    \ T(x ^ v));\n        return x;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <concepts>\n#include <functional>\n#include <limits>\n#include <type_traits>\n\
    #include <vector>\ntemplate <std::integral T = long long> struct xor_basis {\n\
    \    xor_basis() = default;\n    int size() const {\n        return int(b.size());\n\
    \    }\n    bool insert(T x) {\n        x = reduce(x);\n        if (x == 0) return\
    \ false;\n        T p = T(1) << (std::bit_width(std::make_unsigned_t<T>(x)) -\
    \ 1);\n        for (T& v : b) {\n            if (v & p) v ^= x;\n        }\n \
    \       b.insert(std::ranges::lower_bound(b, x, std::greater<T>()), x);\n    \
    \    return true;\n    }\n    bool contains(T x) const {\n        return reduce(x)\
    \ == 0;\n    }\n    T max(T xor_val = 0) const {\n        check(xor_val);\n  \
    \      for (T v : b) xor_val = std::max(xor_val, T(xor_val ^ v));\n        return\
    \ xor_val;\n    }\n    T min(T xor_val = 0) const {\n        return reduce(xor_val);\n\
    \    }\n    T kth_smallest(T k, T xor_val = 0) const {\n        int r = size();\n\
    \        assert(0 <= k && (r >= std::numeric_limits<T>::digits || k < (T(1) <<\
    \ r)));\n        T x = reduce(xor_val);\n        for (int i = 0; i < r; i++) {\n\
    \            if ((k >> (r - 1 - i)) & 1) x ^= b[i];\n        }\n        return\
    \ x;\n    }\n    T kth_largest(T k, T xor_val = 0) const {\n        int r = size();\n\
    \        T all = r == 0 ? 0 : ((T(1) << (r - 1)) - 1) * 2 + 1;\n        assert(0\
    \ <= k && k <= all);\n        return kth_smallest(all - k, xor_val);\n    }\n\n\
    \  private:\n    std::vector<T> b;\n    static void check([[maybe_unused]] T x)\
    \ {\n        if constexpr (std::is_signed_v<T>) assert(x >= 0);\n    }\n    T\
    \ reduce(T x) const {\n        check(x);\n        for (T v : b) x = std::min(x,\
    \ T(x ^ v));\n        return x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/xor_basis.hpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/xor_basis.test.cpp
documentation_of: math/xor_basis.hpp
layout: document
title: Xor Basis
---

### 概要
- 非負整数の集合が xor で張る空間 $V$ を扱う。

### 使い方
- `xor_basis<T = long long>()`: $V = \{0\}$ で初期化する。
- `insert(x)`: $V$ に `x` を加え、$V$ が広がったかを返す。
- `contains(x)`: `x` が $V$ に入るかを返す。
- `size()`: $V$ の次元を返す。$\lvert V \rvert = 2^{\mathrm{size}()}$。
- `max(xor_val = 0)`: $v \in V$ にわたる `v ^ xor_val` の最大値を返す。
- `min(xor_val = 0)`: $v \in V$ にわたる `v ^ xor_val` の最小値を返す。
- `kth_smallest(k, xor_val = 0)`: `v ^ xor_val` ($v \in V$) を昇順に並べたときの `k` 番目 (0-indexed) を返す。
- `kth_largest(k, xor_val = 0)`: `v ^ xor_val` ($v \in V$) を降順に並べたときの `k` 番目 (0-indexed) を返す。

### 制約
- `T` は整数型
- $0 \le x, \mathrm{xor\_val}$
- `kth_smallest`, `kth_largest`: $0 \le k < 2^{\mathrm{size}()}$

### 計算量
- 各操作: $\mathcal{O}(\mathrm{size}())$
