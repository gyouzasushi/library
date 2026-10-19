---
title: Range Map
documentation_of: datastructure/range_map.hpp
---

### 概要
- 区間代入の差分を run ごとに受け取る構造。値を「値が等しい極大な半開区間（run）の列」で持つ。

### 使い方
- `range_map<T, S>()`: 空で始める。`S` には `==` が必要。
- `assign(l, r, x)`: $[l, r)$ の値を `x` にする。
- `assign(l, r, x, f, g)`: 代入で消えた run ごとに `g(l, r, x)` を、できた run ごとに `f(l, r, x)` を呼ぶ。隣接する run の値が等しくなれば 1 つにまとまり、まとめる前の run は `g`、まとめた後の run は `f` に渡る。
- `erase(l, r)`, `erase(l, r, f, g)`: $[l, r)$ の値を消す。コールバックは `assign` と同じ。
- `find(p)`: `p` を含む run のイテレータ。無ければ `end()`。`it->l`, `it->r`, `it->x`。
- `contains(p)`: `p` に値があるか。
- `size()`: run の個数。
- range-for で `for (auto [l, r, x] : mp)` と列挙できる。

### 計算量
- `assign`, `erase`: 償却 $\mathcal{O}(\log N)$。コールバックの呼び出し回数は全体で $\mathcal{O}(N + Q)$。
- `find`, `contains`: $\mathcal{O}(\log N)$

### 問題例
ABC255 Ex - Range Harvest Query（[問題](https://atcoder.jp/contests/abc255/tasks/abc255_h)）

```cpp
#include <atcoder/modint>
#include <iostream>

#include "datastructure/range_map.hpp"
using mint = atcoder::modint998244353;
int main() {
    long long n;
    int q;
    std::cin >> n >> q;
    range_map<long long, long long> mp;
    mp.assign(1, n + 1, 0);
    auto sum = [](long long l, long long r) { return mint(r - l) * (l + r - 1) / 2; };
    while (q--) {
        long long d, l, r;
        std::cin >> d >> l >> r;
        mint ans = 0;
        mp.assign(
            l, r + 1, d,
            [&](long long l, long long r, long long x) { ans -= sum(l, r) * (d - x); },
            [&](long long l, long long r, long long x) { ans += sum(l, r) * (d - x); });
        std::cout << ans.val() << '\n';
    }
}
```

第六回PAST M - 等しい数（[問題](https://atcoder.jp/contests/past202104-open/tasks/past202104_m)）

```cpp
#include <iostream>
#include <map>

#include "datastructure/range_map.hpp"
int main() {
    int n;
    std::cin >> n;
    range_map<int, int> mp;
    long long ans = 0;
    std::map<int, long long> cnt;
    auto f = [&](int l, int r, int x) {
        ans -= cnt[x] * (cnt[x] - 1) / 2;
        cnt[x] += r - l;
        ans += cnt[x] * (cnt[x] - 1) / 2;
    };
    auto g = [&](int l, int r, int x) {
        ans -= cnt[x] * (cnt[x] - 1) / 2;
        cnt[x] -= r - l;
        ans += cnt[x] * (cnt[x] - 1) / 2;
    };
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        mp.assign(i, i + 1, a, f, g);
    }
    int q;
    std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        mp.assign(l, r + 1, x, f, g);
        std::cout << ans << '\n';
    }
}
```
