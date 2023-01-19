---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/range_set.hpp
    title: Range Set
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2880.test.cpp
    title: test/aoj/2880.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1601.test.cpp
    title: test/yukicoder/1601.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/range_map.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <map>\n#include <optional>\n#include <vector>\ntemplate\
    \ <typename T, typename U>\nstruct range_map {\npublic:\n    range_map(bool merge_adjacent_segment\
    \ = true)\n        : merge_adjacent_segment(merge_adjacent_segment) {\n    }\n\
    \    void clear() {\n        mp.clear();\n    }\n    size_t size() {\n       \
    \ return mp.size();\n    }\n    std::optional<std::pair<T, T>> contains(T l, T\
    \ r) {\n        assert(l <= r);\n        auto it = mp.upper_bound(l);\n      \
    \  if (it == mp.begin()) return std::nullopt;\n        it--;\n        if (it->first\
    \ > l) return std::nullopt;\n        if (r > it->second.first) return std::nullopt;\n\
    \        return std::make_pair(it->first, it->second.first);\n    }\n    std::optional<std::pair<T,\
    \ T>> contains(T p) {\n        return is_covered(p, p);\n    }\n    void insert(T\
    \ l, T r, U x) {\n        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n\
    \        auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n      \
    \  if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first >=\n\
    \                l - int(merge_adjacent_segment)) {\n                it_l--;\n\
    \            }\n        };\n        bool has_value_0 = false, has_value_1 = false;\n\
    \        T l_0, l_1, r_1, r_2;\n        U x_0, x_1, x_2;\n        if (it_l !=\
    \ mp.end()) {\n            has_value_0 = true;\n            l_0 = it_l->first;\n\
    \            x_0 = it_l->second.second;\n        }\n        {\n            l_1\
    \ = l, r_1 = r;\n            x_1 = x;\n        }\n        if (it_r != mp.begin())\
    \ {\n            has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n\
    \            x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n        }\n        if (has_value_0\
    \ && x_0 == x_1) {\n            l_1 = std::min(l_0, l_1);\n        } else if (has_value_0\
    \ && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n        }\n        if\
    \ (has_value_1 && x_1 == x_2) {\n            r_1 = std::max(r_1, r_2);\n     \
    \   } else if (has_value_1 && r_1 < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n\
    \        }\n        mp[l_1] = {r_1, x_1};\n    }\n    template <class op_erase,\
    \ class op_insert>\n    void insert(T l, T r, U x, const op_erase &f, const op_insert\
    \ &g) {\n        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n   \
    \     auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n        if\
    \ (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first >=\n \
    \               l - int(merge_adjacent_segment)) {\n                it_l--;\n\
    \            }\n        };\n        bool has_value_0 = false, has_value_1 = false;\n\
    \        T l_0, l_1, r_1, r_2;\n        U x_0, x_1, x_2;\n        if (it_l !=\
    \ mp.end()) {\n            has_value_0 = true;\n            l_0 = it_l->first;\n\
    \            x_0 = it_l->second.second;\n        }\n        {\n            l_1\
    \ = l, r_1 = r;\n            x_1 = x;\n        }\n        if (it_r != mp.begin())\
    \ {\n            has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n\
    \            x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n            f(it->first, it->second.first,\
    \ it->second.second);\n        }\n        if (has_value_0 && x_0 == x_1) {\n \
    \           l_1 = std::min(l_0, l_1);\n        } else if (has_value_0 && l_0 <\
    \ l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n            g(l_0, l_1 - 1, x_0);\n\
    \        }\n        if (has_value_1 && x_1 == x_2) {\n            r_1 = std::max(r_1,\
    \ r_2);\n        } else if (has_value_1 && r_1 < r_2) {\n            mp[r_1 +\
    \ 1] = {r_2, x_2};\n            g(r_1 + 1, r_2, x_2);\n        }\n        mp[l_1]\
    \ = {r_1, x_1};\n        g(l_1, r_1, x_1);\n    }\n    void erase(T l, T r) {\n\
    \        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n        auto\
    \ it_r = mp.upper_bound(r);\n        if (it_l != mp.begin()) {\n            if\
    \ (std::prev(it_l)->second.first >= l) {\n                it_l--;\n          \
    \  }\n        }\n        bool has_value_0 = false, has_value_1 = false;\n    \
    \    T l_0, l_1, r_1, r_2;\n        U x_0, x_2;\n        if (it_l != mp.end())\
    \ {\n            has_value_0 = true;\n            l_0 = it_l->first;\n       \
    \     x_0 = it_l->second.second;\n        }\n        {\n            l_1 = l;\n\
    \            r_1 = r;\n        }\n        if (it_r != mp.begin()) {\n        \
    \    has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n \
    \           x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n        }\n        if (has_value_0\
    \ && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n        }\n        if\
    \ (has_value_1 && r_1 < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n      \
    \  }\n    }\n    template <class op_erase, class op_insert>\n    void erase(T\
    \ l, T r, const op_erase &f, const op_insert &g) {\n        assert(l <= r);\n\
    \        auto it_l = mp.upper_bound(l);\n        auto it_r = mp.upper_bound(r);\n\
    \        if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first\
    \ >= l) {\n                it_l--;\n            }\n        }\n        bool has_value_0\
    \ = false, has_value_1 = false;\n        T l_0, l_1, r_1, r_2;\n        U x_0,\
    \ x_2;\n        if (it_l != mp.end()) {\n            has_value_0 = true;\n   \
    \         l_0 = it_l->first;\n            x_0 = it_l->second.second;\n       \
    \ }\n        {\n            l_1 = l;\n            r_1 = r;\n        }\n      \
    \  if (it_r != mp.begin()) {\n            has_value_1 = true;\n            r_2\
    \ = std::prev(it_r)->second.first;\n            x_2 = std::prev(it_r)->second.second;\n\
    \        }\n        for (auto it = it_l; it != it_r; it = mp.erase(it)) {\n  \
    \          f(it->first, it->second.first, it->second.second);\n        }\n   \
    \     if (has_value_0 && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n\
    \            g(l_0, l_1 - 1, x_0);\n        }\n        if (has_value_1 && r_1\
    \ < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n            g(r_1 + 1, r_2,\
    \ x_2);\n        }\n    }\n    std::vector<std::tuple<T, T, U>> ranges() {\n \
    \       std::vector<std::tuple<T, T, U>> ret;\n        for (auto it = mp.begin();\
    \ it != mp.end(); it++) {\n            ret.emplace_back(it->first, it->second.first,\
    \ it->second.second);\n        }\n        return ret;\n    }\n\nprotected:\n \
    \   bool merge_adjacent_segment;\n    std::map<T, std::pair<T, U>> mp;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <optional>\n#include <vector>\ntemplate <typename T, typename U>\nstruct\
    \ range_map {\npublic:\n    range_map(bool merge_adjacent_segment = true)\n  \
    \      : merge_adjacent_segment(merge_adjacent_segment) {\n    }\n    void clear()\
    \ {\n        mp.clear();\n    }\n    size_t size() {\n        return mp.size();\n\
    \    }\n    std::optional<std::pair<T, T>> contains(T l, T r) {\n        assert(l\
    \ <= r);\n        auto it = mp.upper_bound(l);\n        if (it == mp.begin())\
    \ return std::nullopt;\n        it--;\n        if (it->first > l) return std::nullopt;\n\
    \        if (r > it->second.first) return std::nullopt;\n        return std::make_pair(it->first,\
    \ it->second.first);\n    }\n    std::optional<std::pair<T, T>> contains(T p)\
    \ {\n        return is_covered(p, p);\n    }\n    void insert(T l, T r, U x) {\n\
    \        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n        auto\
    \ it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n        if (it_l !=\
    \ mp.begin()) {\n            if (std::prev(it_l)->second.first >=\n          \
    \      l - int(merge_adjacent_segment)) {\n                it_l--;\n         \
    \   }\n        };\n        bool has_value_0 = false, has_value_1 = false;\n  \
    \      T l_0, l_1, r_1, r_2;\n        U x_0, x_1, x_2;\n        if (it_l != mp.end())\
    \ {\n            has_value_0 = true;\n            l_0 = it_l->first;\n       \
    \     x_0 = it_l->second.second;\n        }\n        {\n            l_1 = l, r_1\
    \ = r;\n            x_1 = x;\n        }\n        if (it_r != mp.begin()) {\n \
    \           has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n\
    \            x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n        }\n        if (has_value_0\
    \ && x_0 == x_1) {\n            l_1 = std::min(l_0, l_1);\n        } else if (has_value_0\
    \ && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n        }\n        if\
    \ (has_value_1 && x_1 == x_2) {\n            r_1 = std::max(r_1, r_2);\n     \
    \   } else if (has_value_1 && r_1 < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n\
    \        }\n        mp[l_1] = {r_1, x_1};\n    }\n    template <class op_erase,\
    \ class op_insert>\n    void insert(T l, T r, U x, const op_erase &f, const op_insert\
    \ &g) {\n        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n   \
    \     auto it_r = mp.upper_bound(r + int(merge_adjacent_segment));\n        if\
    \ (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first >=\n \
    \               l - int(merge_adjacent_segment)) {\n                it_l--;\n\
    \            }\n        };\n        bool has_value_0 = false, has_value_1 = false;\n\
    \        T l_0, l_1, r_1, r_2;\n        U x_0, x_1, x_2;\n        if (it_l !=\
    \ mp.end()) {\n            has_value_0 = true;\n            l_0 = it_l->first;\n\
    \            x_0 = it_l->second.second;\n        }\n        {\n            l_1\
    \ = l, r_1 = r;\n            x_1 = x;\n        }\n        if (it_r != mp.begin())\
    \ {\n            has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n\
    \            x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n            f(it->first, it->second.first,\
    \ it->second.second);\n        }\n        if (has_value_0 && x_0 == x_1) {\n \
    \           l_1 = std::min(l_0, l_1);\n        } else if (has_value_0 && l_0 <\
    \ l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n            g(l_0, l_1 - 1, x_0);\n\
    \        }\n        if (has_value_1 && x_1 == x_2) {\n            r_1 = std::max(r_1,\
    \ r_2);\n        } else if (has_value_1 && r_1 < r_2) {\n            mp[r_1 +\
    \ 1] = {r_2, x_2};\n            g(r_1 + 1, r_2, x_2);\n        }\n        mp[l_1]\
    \ = {r_1, x_1};\n        g(l_1, r_1, x_1);\n    }\n    void erase(T l, T r) {\n\
    \        assert(l <= r);\n        auto it_l = mp.upper_bound(l);\n        auto\
    \ it_r = mp.upper_bound(r);\n        if (it_l != mp.begin()) {\n            if\
    \ (std::prev(it_l)->second.first >= l) {\n                it_l--;\n          \
    \  }\n        }\n        bool has_value_0 = false, has_value_1 = false;\n    \
    \    T l_0, l_1, r_1, r_2;\n        U x_0, x_2;\n        if (it_l != mp.end())\
    \ {\n            has_value_0 = true;\n            l_0 = it_l->first;\n       \
    \     x_0 = it_l->second.second;\n        }\n        {\n            l_1 = l;\n\
    \            r_1 = r;\n        }\n        if (it_r != mp.begin()) {\n        \
    \    has_value_1 = true;\n            r_2 = std::prev(it_r)->second.first;\n \
    \           x_2 = std::prev(it_r)->second.second;\n        }\n        for (auto\
    \ it = it_l; it != it_r; it = mp.erase(it)) {\n        }\n        if (has_value_0\
    \ && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n        }\n        if\
    \ (has_value_1 && r_1 < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n      \
    \  }\n    }\n    template <class op_erase, class op_insert>\n    void erase(T\
    \ l, T r, const op_erase &f, const op_insert &g) {\n        assert(l <= r);\n\
    \        auto it_l = mp.upper_bound(l);\n        auto it_r = mp.upper_bound(r);\n\
    \        if (it_l != mp.begin()) {\n            if (std::prev(it_l)->second.first\
    \ >= l) {\n                it_l--;\n            }\n        }\n        bool has_value_0\
    \ = false, has_value_1 = false;\n        T l_0, l_1, r_1, r_2;\n        U x_0,\
    \ x_2;\n        if (it_l != mp.end()) {\n            has_value_0 = true;\n   \
    \         l_0 = it_l->first;\n            x_0 = it_l->second.second;\n       \
    \ }\n        {\n            l_1 = l;\n            r_1 = r;\n        }\n      \
    \  if (it_r != mp.begin()) {\n            has_value_1 = true;\n            r_2\
    \ = std::prev(it_r)->second.first;\n            x_2 = std::prev(it_r)->second.second;\n\
    \        }\n        for (auto it = it_l; it != it_r; it = mp.erase(it)) {\n  \
    \          f(it->first, it->second.first, it->second.second);\n        }\n   \
    \     if (has_value_0 && l_0 < l_1) {\n            mp[l_0] = {l_1 - 1, x_0};\n\
    \            g(l_0, l_1 - 1, x_0);\n        }\n        if (has_value_1 && r_1\
    \ < r_2) {\n            mp[r_1 + 1] = {r_2, x_2};\n            g(r_1 + 1, r_2,\
    \ x_2);\n        }\n    }\n    std::vector<std::tuple<T, T, U>> ranges() {\n \
    \       std::vector<std::tuple<T, T, U>> ret;\n        for (auto it = mp.begin();\
    \ it != mp.end(); it++) {\n            ret.emplace_back(it->first, it->second.first,\
    \ it->second.second);\n        }\n        return ret;\n    }\n\nprotected:\n \
    \   bool merge_adjacent_segment;\n    std::map<T, std::pair<T, U>> mp;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_map.hpp
  requiredBy:
  - datastructure/range_set.hpp
  timestamp: '2023-01-19 19:46:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1601.test.cpp
  - test/aoj/2880.test.cpp
documentation_of: datastructure/range_map.hpp
layout: document
title: Range Map
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