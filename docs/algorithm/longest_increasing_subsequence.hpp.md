---
title: 最長増加部分列(LIS)
documentation_of: algorithm/longest_increasing_subsequence.hpp
---

### 概要
- 最長増加部分列(LIS)をひとつ求める。
### 使い方
- `longeset_incresing_subsequence(a)`: 数列 $\mathrm a$ の(狭義)最長増加部分列のうち辞書順最小であるものの**添字**を求める。
- `longeset_incresing_subsequence(a, comp)`: 比較関数を `comp` としたときの最長増加部分列のうち辞書順最小であるものの**添字**を求める。

    (例) 広義の最長増加部分列を求めるには、`comp = [](T x,T y) { return x <= y;}` (または `comp = std::less_equal<T>()` )のようにする。
### 計算量
- $\mathcal O(N\log N)$