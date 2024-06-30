---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1601_2.test.cpp
    title: test/yukicoder/1601_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/range_map.hpp\"\n#include <map>\n#include\
    \ <vector>\ntemplate <typename T, typename S>\nstruct range_map {\npublic:\n \
    \   range_map(bool merge_adjacent = true) : _merge_adjacent(merge_adjacent) {\n\
    \    }\n    typename std::map<T, std::pair<T, S>>::const_iterator get(T p) const\
    \ {\n        auto it = values.upper_bound(p);\n        if (it == values.begin())\
    \ return values.end();\n        if (std::prev(it)->second.first < p) return values.end();\n\
    \        return std::prev(it);\n    }\n    typename std::map<T, std::pair<T, S>>::const_iterator\
    \ get(\n        std::pair<T, T> range) const {\n        auto [l, r] = range;\n\
    \        auto it = get(l);\n        if (it == values.end()) return values.end();\n\
    \        if (it->second.first < r) return values.end();\n        return it;\n\
    \    }\n    void set(std::pair<T, T> range, S x) {\n        set(range, x, [](T,\
    \ T, S) {}, [](T, T, S) {});\n    }\n    template <class op_insert, class op_erase>\n\
    \    void set(std::pair<T, T> range, S x, const op_insert &f,\n             const\
    \ op_erase &g) {\n        auto [l, r] = range;\n        auto it_l = values.upper_bound(l);\n\
    \        if (it_l != values.begin() &&\n            l - T(_merge_adjacent) <=\
    \ std::prev(it_l)->second.first) {\n            it_l--;\n        }\n        auto\
    \ it_r = values.upper_bound(r + T(_merge_adjacent));\n        std::vector<std::tuple<T,\
    \ T, S>> restore;\n        restore.reserve(3);\n        if (it_l != values.end()\
    \ && it_l->first < l) {\n            if (it_l->second.second != x) {\n       \
    \         restore.emplace_back(it_l->first, l - 1, it_l->second.second);\n   \
    \         } else {\n                l = it_l->first;\n            }\n        }\n\
    \        if (it_l != it_r && r < std::prev(it_r)->second.first) {\n          \
    \  if (std::prev(it_r)->second.second != x) {\n                restore.emplace_back(r\
    \ + 1, std::prev(it_r)->second.first,\n                                     std::prev(it_r)->second.second);\n\
    \            } else {\n                r = std::prev(it_r)->second.first;\n  \
    \          }\n        }\n        restore.emplace_back(l, r, x);\n        for (auto\
    \ it = it_l; it != it_r; it = values.erase(it)) {\n            g(it->first, it->second.first,\
    \ it->second.second);\n        }\n        for (auto [l, r, x] : restore) {\n \
    \           values[l] = {r, x};\n            f(l, r, x);\n        }\n    }\n \
    \   typename std::map<std::pair<T, T>, S>::const_iterator begin() const {\n  \
    \      return values.begin();\n    }\n    typename std::map<std::pair<T, T>, S>::const_iterator\
    \ end() const {\n        return values.end();\n    }\n\nprotected:\n    std::map<T,\
    \ std::pair<T, S>> values;\n    bool _merge_adjacent;\n};\n"
  code: "#pragma once\n#include <map>\n#include <vector>\ntemplate <typename T, typename\
    \ S>\nstruct range_map {\npublic:\n    range_map(bool merge_adjacent = true) :\
    \ _merge_adjacent(merge_adjacent) {\n    }\n    typename std::map<T, std::pair<T,\
    \ S>>::const_iterator get(T p) const {\n        auto it = values.upper_bound(p);\n\
    \        if (it == values.begin()) return values.end();\n        if (std::prev(it)->second.first\
    \ < p) return values.end();\n        return std::prev(it);\n    }\n    typename\
    \ std::map<T, std::pair<T, S>>::const_iterator get(\n        std::pair<T, T> range)\
    \ const {\n        auto [l, r] = range;\n        auto it = get(l);\n        if\
    \ (it == values.end()) return values.end();\n        if (it->second.first < r)\
    \ return values.end();\n        return it;\n    }\n    void set(std::pair<T, T>\
    \ range, S x) {\n        set(range, x, [](T, T, S) {}, [](T, T, S) {});\n    }\n\
    \    template <class op_insert, class op_erase>\n    void set(std::pair<T, T>\
    \ range, S x, const op_insert &f,\n             const op_erase &g) {\n       \
    \ auto [l, r] = range;\n        auto it_l = values.upper_bound(l);\n        if\
    \ (it_l != values.begin() &&\n            l - T(_merge_adjacent) <= std::prev(it_l)->second.first)\
    \ {\n            it_l--;\n        }\n        auto it_r = values.upper_bound(r\
    \ + T(_merge_adjacent));\n        std::vector<std::tuple<T, T, S>> restore;\n\
    \        restore.reserve(3);\n        if (it_l != values.end() && it_l->first\
    \ < l) {\n            if (it_l->second.second != x) {\n                restore.emplace_back(it_l->first,\
    \ l - 1, it_l->second.second);\n            } else {\n                l = it_l->first;\n\
    \            }\n        }\n        if (it_l != it_r && r < std::prev(it_r)->second.first)\
    \ {\n            if (std::prev(it_r)->second.second != x) {\n                restore.emplace_back(r\
    \ + 1, std::prev(it_r)->second.first,\n                                     std::prev(it_r)->second.second);\n\
    \            } else {\n                r = std::prev(it_r)->second.first;\n  \
    \          }\n        }\n        restore.emplace_back(l, r, x);\n        for (auto\
    \ it = it_l; it != it_r; it = values.erase(it)) {\n            g(it->first, it->second.first,\
    \ it->second.second);\n        }\n        for (auto [l, r, x] : restore) {\n \
    \           values[l] = {r, x};\n            f(l, r, x);\n        }\n    }\n \
    \   typename std::map<std::pair<T, T>, S>::const_iterator begin() const {\n  \
    \      return values.begin();\n    }\n    typename std::map<std::pair<T, T>, S>::const_iterator\
    \ end() const {\n        return values.end();\n    }\n\nprotected:\n    std::map<T,\
    \ std::pair<T, S>> values;\n    bool _merge_adjacent;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_map.hpp
  requiredBy: []
  timestamp: '2024-06-30 18:54:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1601_2.test.cpp
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
ABC255 Ex - Range Harvest Query（[問題リンク](https://atcoder.jp/contests/abc255/tasks/abc255_h)）

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
<br>

第六回PAST M - 等しい数（[問題リンク](https://atcoder.jp/contests/past202104-open/tasks/past202104_m)）

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