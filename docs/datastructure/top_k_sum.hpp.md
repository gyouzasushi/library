---
title: Top K Sum
documentation_of: datastructure/top_k_sum.hpp
---

### 概要
- 多重集合を `Compare` 順に並べたときの先頭 $k$ 個の和を保つ。

### 使い方
- `top_k_sum<T, Compare = std::greater<T>>(k)`: 空の多重集合を作る。`std::greater` なら大きい方から $k$ 個の和、`std::less` なら小さい方から $k$ 個の和。
- `insert(x)`: `x` を 1 個追加する。
- `erase(x)`: `x` を 1 個削除する。`x` は含まれていなければならない。
- `set_k(k)`: $k$ を `k` に設定する。
- `k()`: $k$ を返す。
- `sum()`: 先頭 $k$ 個の和を返す。要素が $k$ 個未満なら全要素の和を返す。
- `size()`: 要素の個数を返す。

### 制約
- $0 \le k$
- `T` は `+=`, `-=`, `==` を持つ

### 計算量
- `insert`, `erase`: 償却 $\mathcal{O}(\log N)$
- `set_k`: 償却 $\mathcal{O}(\lvert k - k' \rvert \log N)$
- `k`, `sum`, `size`: $\mathcal{O}(1)$
