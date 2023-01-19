---
title: Range Map
documentation_of: datastructure/range_map.hpp
---

### 概要
- 各区間に値を持たせることができる、区間を set で管理するテクニック。
- すべて閉区間。
  
### 使い方
- `range_map(merge_adjacent_segment = true)`: コンストラクタ。区間 `[l, m]` と `[m + 1, r]` を `[l, r]` にマージしない場合は、`merge_adjacent_segment` を `false` にする。
- `insert(l, r, x)`: 区間 `[l, r]` を挿入し、値 `x` を持たせる。
- `insert(l, r, x, f, g)`: 区間 `[l, r]` を挿入し、値 `x` を持たせる。そのとき、区間が削除されるたびに `f` を、区間が追加されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r, U x) -> void`。
- `erase(l, r)`: 区間 `[l, r]` を削除。
- `erase(l, r, f, g)`: 区間 `[l, r]` を削除。そのとき、区間が削除されるたびに `f` を、区間が追加されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r, U x) -> void`。
- `contains(l, r)`: `[l, r]` を完全に覆う区間がある場合、それを返す。
- `ranges()`: すべての区間とそれに対応する値 `(l, r, x)` を列挙する。

### 問題例
ABC255 Ex - Range Harvest Query（[リンク](https://atcoder.jp/contests/abc255/tasks/abc255_h)）
<details>
<summary>コード</summary>

```cpp
#include <iostream>
#include "datastructure/range_map.hpp"
#include "math/modint.hpp"
using mint = modint998244353;
int main() {
    long long n;
    int q;
    std::cin >> n >> q;
    range_map<long long, long long> mp;
    mp.insert(1, n, 0);
    while (q--) {
        long long d, l, r;
        std::cin >> d >> l >> r;
        mint ans = 0;
        mp.erase(
            l, r,
            [&](long long l, long long r, long long x) {
                ans += mint(r - l + 1) * (r + l) / 2 * (d - x);
            },
            [&](long long l, long long r, long long x) {
                ans -= mint(r - l + 1) * (r + l) / 2 * (d - x);
            });
        std::cout << ans << '\n';
        mp.insert(l, r, d);
    }
}
```
</details>
<br>

第六回PAST M - 等しい数（[リンク](https://atcoder.jp/contests/past202104-open/tasks/past202104_m)）
<details>
<summary>コード</summary>

```cpp
#include <iostream>

#include "datastructure/range_map.hpp"
int main() {
    int n;
    std::cin >> n;
    range_map<long long, int> mp(false);
    std::map<int, long long> cnt;
    long long ans = 0;
    auto f = [&](long long l, long long r, long long x) {
        ans -= cnt[x] * (cnt[x] - 1) / 2;
        cnt[x] -= r - l + 1;
        ans += cnt[x] * (cnt[x] - 1) / 2;
    };
    auto g = [&](long long l, long long r, long long x) {
        ans -= cnt[x] * (cnt[x] - 1) / 2;
        cnt[x] += r - l + 1;
        ans += cnt[x] * (cnt[x] - 1) / 2;
    };
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        mp.insert(i, i, a, f, g);
    }
    int q;
    std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        mp.insert(l, r, x, f, g);
        std::cout << ans << '\n';
    }
}
```
</details>