---
title: Wildcard Matching
documentation_of: string/wildcard_matching.hpp
---

### 概要
- ワイルドカードを含む 2 つの列について、一方をずらして重ねた各位置で一致するかを求める。

### 使い方
- `wildcard_matching(s, t, wildcard = '?')`: 長さ $\lvert s \rvert - \lvert t \rvert + 1$ の列 `res` を返す。`res[i]` は $s_{i}, \ldots, s_{i + \lvert t \rvert - 1}$ と $t$ が各位置で等しいか少なくとも一方が `wildcard` かを表す。`s`, `t` は `std::string` または `std::vector<T>`。$\lvert t \rvert > \lvert s \rvert$ なら空。

### 制約
- $\lvert s \rvert + \lvert t \rvert - 1 \le 2^{24}$
- `wildcard` 以外の値の種類数を $k$ として $\lvert t \rvert k^4 < 9 \times 10^{18}$

### 計算量
- $N = \lvert s \rvert + \lvert t \rvert$ として $\mathcal{O}(N \log N)$
