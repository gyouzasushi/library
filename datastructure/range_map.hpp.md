---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1601_2.test.cpp
    title: test/yukicoder/1601_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
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