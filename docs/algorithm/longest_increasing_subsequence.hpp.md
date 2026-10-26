---
title: Longest Increasing Subsequence
documentation_of: algorithm/longest_increasing_subsequence.hpp
---

### 概要
- 数列の最長増加部分列 (LIS) の長さと、各要素が LIS に使われ得るかを求める。LIS は添字の列として扱う。

### 使い方
- `longest_increasing_subsequence<T, Compare = std::less<T>>(a, comp = {})`: 数列 `a` について構築する。`comp(x, y)` が真のとき `x` の後に `y` を置ける。
- `length()`: LIS の長さを返す。
- `position(i)`: `a[i]` を使う LIS があればその中での `a[i]` の位置 (0-indexed)、なければ $-1$ を返す。
- `candidates(j)`: LIS の `j` 番目になり得る添字を昇順に並べた列を返す。値は降順。
- `indices()`: 添字の辞書順最小の LIS を返す。

### 制約
- `position`: $0 \le i < \lvert a \rvert$
- `candidates`: $0 \le j <$ `length()`

### 計算量
- 構築: $\mathcal{O}(n \log n)$
- `length`, `position`, `candidates`: $\mathcal{O}(1)$
- `indices`: $\mathcal{O}(n)$
