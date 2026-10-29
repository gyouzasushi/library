---
title: "Acted Monoid: Range Chmin Chmax Add Range Sum"
documentation_of: algebra/range_chmin_chmax_add_range_sum.hpp
---

### 概要
- 区間 chmin・chmax・加算・代入と、区間の和・最小値・最大値。`segtree_beats<range_chmin_chmax_add_range_sum<T>>` のように使う。

### 使い方
- `S = {T sum, min, max, min2, max2; int minc, maxc, len; bool fail}`, `F = {T add, chmin, chmax}`
- `from(v)`: 値 `v` 1 個分の要素を返す。初期化や一点更新ではこれで `S` を作る。
- `chmin(x)`: `a[i]` を `min(a[i], x)` にする作用を返す。
- `chmax(x)`: `a[i]` を `max(a[i], x)` にする作用を返す。
- `add(x)`: `a[i]` を `a[i] + x` にする作用を返す。
- `assign(x)`: `a[i]` を `x` にする作用を返す。
- `prod(l, r).sum`, `.min`, `.max` が区間の和、最小値、最大値。

### 制約
- 途中の値と和が `T` の範囲に収まる

### 計算量
- `apply`, `prod`: 償却 $\mathcal{O}(\log^2 N)$

### 問題例
Library Checker - Range Chmin Chmax Add Range Sum（[問題](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)）

```cpp
#include <iostream>

#include "algebra/range_chmin_chmax_add_range_sum.hpp"
#include "datastructure/segtree_beats.hpp"
int main() {
    using A = range_chmin_chmax_add_range_sum<long long>;
    int n, q;
    std::cin >> n >> q;
    std::vector<A::S> a(n);
    for (auto& x : a) {
        long long v;
        std::cin >> v;
        x = A::from(v);
    }
    segtree_beats<A> seg(a);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 3) {
            std::cout << seg.prod(l, r).sum << '\n';
            continue;
        }
        long long b;
        std::cin >> b;
        if (t == 0) seg.apply(l, r, A::chmin(b));
        if (t == 1) seg.apply(l, r, A::chmax(b));
        if (t == 2) seg.apply(l, r, A::add(b));
    }
}
```
