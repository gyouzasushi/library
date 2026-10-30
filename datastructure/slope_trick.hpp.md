---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/slope_trick.test.cpp
    title: test/unit/slope_trick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/slope_trick.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n\ntemplate <class T> struct slope_trick {\n    slope_trick()\
    \ : min_f(0), add_l(0), add_r(0) {}\n    T min() const { return min_f; }\n   \
    \ std::pair<std::optional<T>, std::optional<T>> argmin() const {\n        std::optional<T>\
    \ l, r;\n        if (!L.empty()) l = L.front() + add_l;\n        if (!R.empty())\
    \ r = R.front() + add_r;\n        return {l, r};\n    }\n    void add(T a) { min_f\
    \ += a; }\n    void add_x_minus_a(T a) {\n        if (!L.empty()) min_f += std::max<T>(0,\
    \ L.front() + add_l - a);\n        push_l(a);\n        push_r(pop_l());\n    }\n\
    \    void add_a_minus_x(T a) {\n        if (!R.empty()) min_f += std::max<T>(0,\
    \ a - (R.front() + add_r));\n        push_r(a);\n        push_l(pop_r());\n  \
    \  }\n    void add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \    }\n    void prefix_min() {\n        R.clear();\n        add_r = 0;\n    }\n\
    \    void suffix_min() {\n        L.clear();\n        add_l = 0;\n    }\n    void\
    \ shift(T a) { shift(a, a); }\n    void shift(T a, T b) {\n        assert(a <=\
    \ b);\n        add_l += a;\n        add_r += b;\n    }\n    void merge(slope_trick&\
    \ g) {\n        if (L.size() + R.size() < g.L.size() + g.R.size()) std::swap(*this,\
    \ g);\n        min_f += g.min_f;\n        for (T l : g.L) add_a_minus_x(l + g.add_l);\n\
    \        for (T r : g.R) add_x_minus_a(r + g.add_r);\n        g = slope_trick();\n\
    \    }\n    T operator()(T x) const {\n        T res = min_f;\n        for (T\
    \ l : L) res += std::max<T>(0, l + add_l - x);\n        for (T r : R) res += std::max<T>(0,\
    \ x - (r + add_r));\n        return res;\n    }\n\n  private:\n    T min_f, add_l,\
    \ add_r;\n    std::vector<T> L, R;\n    void push_l(T a) {\n        L.push_back(a\
    \ - add_l);\n        std::push_heap(L.begin(), L.end());\n    }\n    void push_r(T\
    \ a) {\n        R.push_back(a - add_r);\n        std::push_heap(R.begin(), R.end(),\
    \ std::greater<T>());\n    }\n    T pop_l() {\n        std::pop_heap(L.begin(),\
    \ L.end());\n        T a = L.back() + add_l;\n        L.pop_back();\n        return\
    \ a;\n    }\n    T pop_r() {\n        std::pop_heap(R.begin(), R.end(), std::greater<T>());\n\
    \        T a = R.back() + add_r;\n        R.pop_back();\n        return a;\n \
    \   }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <optional>\n#include <utility>\n#include <vector>\n\ntemplate <class\
    \ T> struct slope_trick {\n    slope_trick() : min_f(0), add_l(0), add_r(0) {}\n\
    \    T min() const { return min_f; }\n    std::pair<std::optional<T>, std::optional<T>>\
    \ argmin() const {\n        std::optional<T> l, r;\n        if (!L.empty()) l\
    \ = L.front() + add_l;\n        if (!R.empty()) r = R.front() + add_r;\n     \
    \   return {l, r};\n    }\n    void add(T a) { min_f += a; }\n    void add_x_minus_a(T\
    \ a) {\n        if (!L.empty()) min_f += std::max<T>(0, L.front() + add_l - a);\n\
    \        push_l(a);\n        push_r(pop_l());\n    }\n    void add_a_minus_x(T\
    \ a) {\n        if (!R.empty()) min_f += std::max<T>(0, a - (R.front() + add_r));\n\
    \        push_r(a);\n        push_l(pop_r());\n    }\n    void add_abs(T a) {\n\
    \        add_x_minus_a(a);\n        add_a_minus_x(a);\n    }\n    void prefix_min()\
    \ {\n        R.clear();\n        add_r = 0;\n    }\n    void suffix_min() {\n\
    \        L.clear();\n        add_l = 0;\n    }\n    void shift(T a) { shift(a,\
    \ a); }\n    void shift(T a, T b) {\n        assert(a <= b);\n        add_l +=\
    \ a;\n        add_r += b;\n    }\n    void merge(slope_trick& g) {\n        if\
    \ (L.size() + R.size() < g.L.size() + g.R.size()) std::swap(*this, g);\n     \
    \   min_f += g.min_f;\n        for (T l : g.L) add_a_minus_x(l + g.add_l);\n \
    \       for (T r : g.R) add_x_minus_a(r + g.add_r);\n        g = slope_trick();\n\
    \    }\n    T operator()(T x) const {\n        T res = min_f;\n        for (T\
    \ l : L) res += std::max<T>(0, l + add_l - x);\n        for (T r : R) res += std::max<T>(0,\
    \ x - (r + add_r));\n        return res;\n    }\n\n  private:\n    T min_f, add_l,\
    \ add_r;\n    std::vector<T> L, R;\n    void push_l(T a) {\n        L.push_back(a\
    \ - add_l);\n        std::push_heap(L.begin(), L.end());\n    }\n    void push_r(T\
    \ a) {\n        R.push_back(a - add_r);\n        std::push_heap(R.begin(), R.end(),\
    \ std::greater<T>());\n    }\n    T pop_l() {\n        std::pop_heap(L.begin(),\
    \ L.end());\n        T a = L.back() + add_l;\n        L.pop_back();\n        return\
    \ a;\n    }\n    T pop_r() {\n        std::pop_heap(R.begin(), R.end(), std::greater<T>());\n\
    \        T a = R.back() + add_r;\n        R.pop_back();\n        return a;\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/slope_trick.hpp
  requiredBy: []
  timestamp: '2026-10-30 20:38:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/slope_trick.test.cpp
documentation_of: datastructure/slope_trick.hpp
layout: document
title: Slope Trick
---

### 概要
- 傾きが整数ずつ変わる凸な区分線形関数 $f(x)$ を折れ点の集合で持ち、関数への演算と最小値の取得を行う。

### 使い方
- `slope_trick<T>()`: $f(x) = 0$ を作る。`T` は $x$ と $f(x)$ の型。
- `min()`: $\min_x f(x)$ を返す。
- `argmin()`: $f(x)$ が最小になる $x$ の区間 $[l, r]$ を `pair<optional<T>, optional<T>>` で返す。区間が左右に有界でない側は `std::nullopt`。
- `add(a)`: $f(x) \gets f(x) + a$ とする。
- `add_x_minus_a(a)`: $f(x) \gets f(x) + \max(0, x - a)$ とする。
- `add_a_minus_x(a)`: $f(x) \gets f(x) + \max(0, a - x)$ とする。
- `add_abs(a)`: $f(x) \gets f(x) + \lvert x - a \rvert$ とする。
- `prefix_min()`: $f(x) \gets \min_{y \le x} f(y)$ とする。
- `suffix_min()`: $f(x) \gets \min_{y \ge x} f(y)$ とする。
- `shift(a)`: $f(x) \gets f(x - a)$ とする。
- `shift(a, b)`: $f(x) \gets \min_{x - b \le y \le x - a} f(y)$ とする。
- `merge(g)`: $f(x) \gets f(x) + g(x)$ とし、`g` を $g(x) = 0$ にする。
- `operator()(x)`: $f(x)$ を返す。

### 制約
- `shift(a, b)`: $a \le b$

### 計算量
- 折れ点の総数を $N$ として
- `add_x_minus_a`, `add_a_minus_x`, `add_abs`: $\mathcal{O}(\log N)$
- `merge`: 全体で償却 $\mathcal{O}(N \log^2 N)$
- `operator()`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$
