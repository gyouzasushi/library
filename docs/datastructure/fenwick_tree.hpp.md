---
title: Fenwick Tree
documentation_of: datastructure/fenwick_tree.hpp
---

### 概要
- ACL の Fenwick Tree + lower_bound / upper_bound。
  
### 使い方
- `lower_bound(x)`: `sum(0, i) >= x` となる最小の `i` を求める。
- `upper_bound(x)`: `sum(0, i) > x` となる最小の `i` を求める。
- 他は [ACL のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/fenwicktree.html)を参照。