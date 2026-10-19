---
title: Dijkstra 法
documentation_of: graph/dijkstra.hpp
---

### 概要
- Dijkstra 法で単一始点最短路を求める。

### 使い方
- `dijkstra<T> d(n)`: 頂点数 `n`、辺の重みの型 `T`。
- `add_edge(from, to, w)`: 重み `w` の有向辺を追加する。
- `solve(s)`: 頂点 `s` を始点として最短路を求める。
- `dist(v)`: `s` から `v` への最短距離。到達不能なら `std::numeric_limits<T>::max()`。
- `prev(v)`: 最短路における `v` の直前の頂点。`s` と到達不能な頂点では `-1`。
- `reachable(v)`: `s` から `v` に到達可能か。
- `path(t)`: `s` から `t` への最短路の頂点列。到達不能なら空。

### 計算量
- `solve`: $\mathcal{O}((N + M) \log N)$
- `path`: $\mathcal{O}(N)$
- その他: $\mathcal{O}(1)$

### 問題例
Library Checker - Shortest Path（[問題](https://judge.yosupo.jp/problem/shortest_path)）

```cpp
#include <iostream>

#include "graph/dijkstra.hpp"
int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    dijkstra<long long> d(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        d.add_edge(a, b, c);
    }
    d.solve(s);
    if (!d.reachable(t)) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::vector<int> path = d.path(t);
    std::cout << d.dist(t) << ' ' << path.size() - 1 << '\n';
    for (int i = 0; i + 1 < int(path.size()); i++) {
        std::cout << path[i] << ' ' << path[i + 1] << '\n';
    }
}
```
