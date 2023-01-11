---
title: 根付き木の同型性による部分木の分類
documentation_of: graph/subtree_classify.hpp
---

### 概要
- $N$ 頂点の根付き木について、ある頂点を根とする（全部で $N$ 個の）部分木を、根付き木の同型性で分類する。
  
### 使い方
- `subtree_classify(g, root = 0)`: 次の条件を満たす整数列 `a` を求める。
  - 部分木の種類数を $K$ としたとき、$0\leq a_i \lt N$
  - 頂点 `i`、 頂点 `j` を根とする部分木が同型 $\iff$ $a_i = a_j$

### 計算量
- $\mathcal{O}(N \log N)$