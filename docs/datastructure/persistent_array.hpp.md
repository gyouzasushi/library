---
title: Persistent Array
documentation_of: datastructure/persistent_array.hpp
---

### 概要
- 1 点更新のたびに新しい版を作り、過去の版も参照できる配列。版は `int` の番号で扱う。

### 使い方
- `persistent_array<T>(n)`: 全要素 `T()` の長さ $n$ の配列を版 $0$ として作る。
- `persistent_array<T>(v)`: 配列 `v` を版 $0$ として作る。
- `size()`: 配列の長さを返す。
- `get(root, p)`: 版 `root` の `a[p]` を返す。
- `set(root, p, x)`: 版 `root` の `a[p]` を `x` に変えた新しい版を作り、その番号を返す。版 `root` は変わらない。

### 制約
- $0 \le p < n$

### 計算量
- 構築: $\mathcal{O}(n)$
- `get`, `set`: $\mathcal{O}(\log n)$。`set` 1 回でメモリが $\mathcal{O}(\log n)$ 増える。
