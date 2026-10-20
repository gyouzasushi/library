---
title: 全方位木 DP (Rerooting)
documentation_of: graph/rerooting.hpp
---

### 概要
- 木の全頂点を根としたときの DP の値を $\mathcal O(N)$ で求める。
- 部分木の値の型 `T` と、子をまとめるモノイドの型 `M` を分けて指定する。

### 使い方
- 次の形の構造体 `R` を書き、`rerooting<R>` に渡す。

```cpp
struct R {
    using T = ...;  // 部分木の値
    using M = ...;  // 子をまとめるモノイド
    using E = ...;  // 辺に持たせるデータ。不要なら std::monostate
    using V = ...;  // 頂点に持たせるデータ。不要なら std::monostate
    static M put_edge(const T& x, const E& w, int u, int v);  // v 側の部分木の値 x を辺 (u, v) 経由で u へ持ち上げる
    static M merge(const M& a, const M& b);                   // モノイドの積。非可換でもよい
    static M e();                                             // 単位元
    static T put_vertex(const M& acc, const V& a, int v);     // 子をまとめた値 acc に頂点 v を足して部分木の値にする
};
```

- `rerooting<R>(n)`: $n$ 頂点で初期化する。頂点データは `V()`。
- `rerooting<R>(std::vector<V> a)`: 頂点データ `a` を持たせて初期化する。
- `add_edge(u, v, w = E())`: 辺を追加し、辺番号（追加順）を返す。
- `solve()`: 計算する。
- `dp(v)`: 全体を頂点 `v` を根として見たときの値。
- `agg(v)`: `dp(v)` を作る直前の、`v` の全隣接をまとめた `M` の値。
- `sub(u, v)`: 辺 $(u, v)$ を切ったときの `v` 側の部分木を `v` を根として見た値。
- `sub_by_edge(i, v)`: 辺 `i` を切ったときの `v` 側の部分木を `v` を根として見た値。
- `merge` の順序は各頂点の隣接を `add_edge` 順に並べたものに従う。

### 例
- 距離の総和: `T = M = {cnt, sum}`, `put_edge(x) = {x.cnt, x.sum + x.cnt}`, `merge` は成分ごとの和, `put_vertex(acc) = {acc.cnt + 1, acc.sum}`
- $\max_{j \ne i} (\mathrm{dist}(i, j) + d_j)$: `T = M = E = V = long long`, `put_edge(x, w) = x + w`, `merge = max`, `e = -∞`, `put_vertex(acc, d) = max(acc, d)`。答えは `agg(i)`
- 直径: `T` = 最大深さ, `M` = 深さの上位 2 つ。`T` と `M` が異なる例

### 計算量
- $\mathcal O(N)$ 回の `put_edge`, `merge`, `put_vertex` 呼び出し
