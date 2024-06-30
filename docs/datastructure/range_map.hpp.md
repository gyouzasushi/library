---
title: Range Map
documentation_of: datastructure/range_map.hpp
---

### 概要
- 各区間に値を持たせることができる、区間を set で管理するテクニック。
- すべて閉区間。
  
### 使い方
- `range_map(merge_adjacent_segment = true)`: コンストラクタ。区間 `[l, m]` と `[m + 1, r]` を `[l, r]` にマージしない場合は、`merge_adjacent_segment` を `false` にする。
- `get(p)`: `p` を含む区間のイテレータ（存在しない場合は `end()`）を返す。
- `get({l, r})`: 区間 `[l, r]` を完全に含む区間のイテレータ（存在しない場合は `end()`）を返す。
- `set({l, r}, x)`: 区間 `[l, r]` に値 `x` を持たせる。
- `set({l, r}, x, f, g)`: 区間 `[l, r]` に値 `x` を持たせる。そのとき、区間が追加されるたびに `f` を、区間が削除されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r, U x) -> void`。

### 問題例
ABC255 Ex - Range Harvest Query（[問題](https://atcoder.jp/contests/abc255/tasks/abc255_h)）（[提出](https://atcoder.jp/contests/abc255/submissions/55041993)）
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
    mp.set({0, n}, 0);
    while (q--) {
        long long d, l, r;
        std::cin >> d >> l >> r;
        mint ans = 0;
        mp.set(
            {l, r}, d,
            [&](long long l, long long r, long long x) {
                ans -= mint(r - l + 1) * (r + l) / 2 * (d - x);
            },
            [&](long long l, long long r, long long x) {
                ans += mint(r - l + 1) * (r + l) / 2 * (d - x);
            });
        std::cout << ans.val() << '\n';
    }
}
```
<br>

第六回PAST M - 等しい数（[問題](https://atcoder.jp/contests/past202104-open/tasks/past202104_m)）（[提出](https://atcoder.jp/contests/past202104-open/submissions/55042059)）

```cpp
#include <iostream>

#include "datastructure/range_map.hpp"
int main() {
    int n;
    std::cin >> n;
    range_map<int, long long> mp;
    long long ans = 0;
    std::map<int, long long> cnt;
    auto f = [&](long long l, long long r, long long x) {
        ans -= cnt[x] * (cnt[x] - 1) / 2;
        cnt[x] += r - l + 1;
        ans += cnt[x] * (cnt[x] - 1) / 2;
    };
    auto g = [&](long long l, long long r, long long x) {
        ans -= cnt[x] * (cnt[x] - 1) / 2;
        cnt[x] -= r - l + 1;
        ans += cnt[x] * (cnt[x] - 1) / 2;
    };
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        mp.set({i, i}, a, f, g);
    }
    int q;
    std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        mp.set({l, r}, x, f, g);
        std::cout << ans << '\n';
    }
}
```