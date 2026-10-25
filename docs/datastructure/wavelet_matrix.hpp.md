---
title: Wavelet Matrix
documentation_of: datastructure/wavelet_matrix.hpp
---

### 概要
- 静的な配列に対し、区間内で値が範囲に入る要素の個数・重み和・$k$ 番目の値を求める。

### 使い方
- `wavelet_matrix<T>(a)`: 配列 `a` で構築する。
- `wavelet_matrix<T, S>(a, w)`: 配列 `a` と重み `w` で構築する。
- `size()`: `a` の長さを返す。
- `count(l, r, upper)`: $l \le i < r$ かつ `a[i] < upper` となる `i` の個数を返す。
- `count(l, r, lower, upper)`: $l \le i < r$ かつ `lower <= a[i] < upper` となる `i` の個数を返す。
- `kth_smallest(l, r, k)`: `a[l], ..., a[r - 1]` を昇順に並べたときの `k` 番目 (0-indexed) を返す。
- `kth_largest(l, r, k)`: `a[l], ..., a[r - 1]` を降順に並べたときの `k` 番目 (0-indexed) を返す。
- `prev_value(l, r, upper)`: `a[l], ..., a[r - 1]` のうち `upper` 未満の最大値を返す。無ければ `std::nullopt`。
- `next_value(l, r, lower)`: `a[l], ..., a[r - 1]` のうち `lower` 以上の最小値を返す。無ければ `std::nullopt`。
- `sum(l, r, upper)`: $l \le i < r$ かつ `a[i] < upper` となる `i` の重みの和を返す。`S` を指定したときのみ。
- `sum(l, r, lower, upper)`: $l \le i < r$ かつ `lower <= a[i] < upper` となる `i` の重みの和を返す。`S` を指定したときのみ。
- `sum_smallest(l, r, k)`: $l \le i < r$ の要素を `(a[i], i)` の昇順に並べたときの先頭 `k` 個の重みの和を返す。`S` を指定したときのみ。

### 制約
- `T` は `<` で比較できる
- `S` は `+`, `-` ができる
- $0 \le l \le r \le n$
- `kth_smallest`, `kth_largest`: $0 \le k < r - l$
- `sum_smallest`: $0 \le k \le r - l$

### 計算量
- $\sigma$ を `a` の値の種類数として
- 構築: $\mathcal{O}(N \log N)$
- 各クエリ: $\mathcal{O}(\log \sigma)$
