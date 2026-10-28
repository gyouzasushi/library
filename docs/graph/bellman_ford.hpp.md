---
title: Bellman–Ford 法
documentation_of: graph/bellman_ford.hpp
---

### 概要
- Bellman–Ford 法で負辺を含むグラフの単一始点最短路を求める。

### 使い方
- `bellman_ford<T> bf(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(from, to, w)`: 重み `w` の有向辺を追加する。
- `solve(s)`: 頂点 `s` を始点として最短路を求める。
- `dist(v)`: `s` から `v` への最短距離。到達不能なら `std::numeric_limits<T>::max()`、下に有界でなければ `std::numeric_limits<T>::lowest()`。
- `prev(v)`: 最短路における `v` の直前の頂点。`s` と到達不能な頂点では `-1`。
- `reachable(v)`: `s` から `v` に到達可能か。
- `unbounded(v)`: `s` から負閉路を通って `v` に到達可能か。
- `has_negative_cycle()`: `s` から到達可能な負閉路があるか。
- `path(t)`: `s` から `t` への最短路の頂点列。到達不能か下に有界でなければ空。

### 制約
- $N \cdot \max |w|$ が `T` の範囲に収まる

### 計算量
- `solve`: $\mathcal{O}(NM)$
- `has_negative_cycle`, `path`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$

### 問題例
AOJ GRL_1_B - Single Source Shortest Path (Negative Edges)（[問題](https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B)）

```cpp
#include <iostream>

#include "graph/bellman_ford.hpp"
int main() {
    int n, m, r;
    std::cin >> n >> m >> r;
    bellman_ford<long long> bf(n);
    for (int i = 0; i < m; i++) {
        int s, t;
        long long d;
        std::cin >> s >> t >> d;
        bf.add_edge(s, t, d);
    }
    bf.solve(r);
    if (bf.has_negative_cycle()) {
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }
    for (int v = 0; v < n; v++) {
        if (bf.reachable(v)) {
            std::cout << bf.dist(v) << '\n';
        } else {
            std::cout << "INF\n";
        }
    }
}
```
