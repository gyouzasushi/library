---
title: Quotient Blocks
documentation_of: math/quotient_blocks.hpp
---

### 概要
- $\lfloor n / i \rfloor$ が等しい $i$ の区間に $[1, n]$ を分ける。

### 使い方
- `quotient_blocks(n)`: $i \in [l, r)$ で $\lfloor n / i \rfloor = q$ となる `{l, r, q}` の列を `l` の昇順で返す。

### 制約
- $0 \le n$

### 計算量
- $\mathcal{O}(\sqrt{n})$
