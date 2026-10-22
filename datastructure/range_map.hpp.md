---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/range_map.test.cpp
    title: test/unit/range_map.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1601_2.test.cpp
    title: test/yukicoder/1601_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/range_map.hpp\"\n#include <cassert>\n#include\
    \ <iterator>\n#include <optional>\n#include <set>\ntemplate <class T, class S>\n\
    struct range_map {\npublic:\n    struct run {\n        T l, r;\n        S x;\n\
    \    };\n\nprivate:\n    struct cmp {\n        using is_transparent = void;\n\
    \        bool operator()(const run& a, const run& b) const {\n            return\
    \ a.l < b.l;\n        }\n        bool operator()(const run& a, const T& b) const\
    \ {\n            return a.l < b;\n        }\n        bool operator()(const T&\
    \ a, const run& b) const {\n            return a < b.l;\n        }\n    };\n\n\
    public:\n    using iterator = typename std::set<run, cmp>::const_iterator;\n \
    \   range_map() {\n    }\n    // p \u3092\u542B\u3080 run\u3002\u7121\u3051\u308C\
    \u3070 end()\n    iterator find(T p) const {\n        auto it = runs.upper_bound(p);\n\
    \        if (it == runs.begin()) return runs.end();\n        it--;\n        if\
    \ (it->r <= p) return runs.end();\n        return it;\n    }\n    bool contains(T\
    \ p) const {\n        return find(p) != runs.end();\n    }\n    void assign(T\
    \ l, T r, S x) {\n        assign(l, r, x, [](T, T, const S&) {}, [](T, T, const\
    \ S&) {});\n    }\n    // f: \u3067\u304D\u305F run \u3054\u3068\u306B\u547C\u3076\
    , g: \u6D88\u3048\u305F run \u3054\u3068\u306B\u547C\u3076\n    template <class\
    \ F, class G>\n    void assign(T l, T r, S x, const F& f, const G& g) {\n    \
    \    assert(l < r);\n        {\n            auto it = find(l);\n            if\
    \ (it != runs.end() && r <= it->r && it->x == x) return;\n        }\n        T\
    \ nl = l, nr = r;\n        std::optional<run> left, right;\n        auto first\
    \ = runs.upper_bound(l);\n        if (first != runs.begin()) {\n            auto\
    \ p = std::prev(first);\n            if (l < p->r) {\n                first =\
    \ p;\n                if (p->l < l) {\n                    if (p->x == x) {\n\
    \                        nl = p->l;\n                    } else {\n          \
    \              left = run{p->l, l, p->x};\n                    }\n           \
    \     }\n            } else if (p->r == l && p->x == x) {\n                first\
    \ = p;\n                nl = p->l;\n            }\n        }\n        if (first\
    \ != runs.end() && first != runs.begin() && first->l == l) {\n            auto\
    \ p = std::prev(first);\n            if (p->r == l && p->x == x) {\n         \
    \       first = p;\n                nl = p->l;\n            }\n        }\n   \
    \     auto last = runs.lower_bound(r);\n        if (last != runs.begin()) {\n\
    \            auto q = std::prev(last);\n            if (r < q->r) {\n        \
    \        if (q->x == x) {\n                    nr = q->r;\n                } else\
    \ {\n                    right = run{r, q->r, q->x};\n                }\n    \
    \        }\n        }\n        if (last != runs.end() && last->l == r && last->x\
    \ == x) {\n            nr = last->r;\n            last++;\n        }\n       \
    \ for (auto it = first; it != last;) {\n            g(it->l, it->r, it->x);\n\
    \            it = runs.erase(it);\n        }\n        if (left) {\n          \
    \  runs.insert(*left);\n            f(left->l, left->r, left->x);\n        }\n\
    \        runs.insert({nl, nr, x});\n        f(nl, nr, x);\n        if (right)\
    \ {\n            runs.insert(*right);\n            f(right->l, right->r, right->x);\n\
    \        }\n    }\n    void erase(T l, T r) {\n        erase(l, r, [](T, T, const\
    \ S&) {}, [](T, T, const S&) {});\n    }\n    template <class F, class G>\n  \
    \  void erase(T l, T r, const F& f, const G& g) {\n        assert(l < r);\n  \
    \      auto it = runs.upper_bound(l);\n        if (it != runs.begin() && l < std::prev(it)->r)\
    \ it--;\n        while (it != runs.end() && it->l < r) {\n            run cur\
    \ = *it;\n            g(cur.l, cur.r, cur.x);\n            it = runs.erase(it);\n\
    \            if (cur.l < l) {\n                runs.insert({cur.l, l, cur.x});\n\
    \                f(cur.l, l, cur.x);\n            }\n            if (r < cur.r)\
    \ {\n                runs.insert({r, cur.r, cur.x});\n                f(r, cur.r,\
    \ cur.x);\n            }\n        }\n    }\n    int size() const {\n        return\
    \ int(runs.size());\n    }\n    iterator begin() const {\n        return runs.begin();\n\
    \    }\n    iterator end() const {\n        return runs.end();\n    }\n\nprivate:\n\
    \    std::set<run, cmp> runs;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iterator>\n#include <optional>\n\
    #include <set>\ntemplate <class T, class S>\nstruct range_map {\npublic:\n   \
    \ struct run {\n        T l, r;\n        S x;\n    };\n\nprivate:\n    struct\
    \ cmp {\n        using is_transparent = void;\n        bool operator()(const run&\
    \ a, const run& b) const {\n            return a.l < b.l;\n        }\n       \
    \ bool operator()(const run& a, const T& b) const {\n            return a.l <\
    \ b;\n        }\n        bool operator()(const T& a, const run& b) const {\n \
    \           return a < b.l;\n        }\n    };\n\npublic:\n    using iterator\
    \ = typename std::set<run, cmp>::const_iterator;\n    range_map() {\n    }\n \
    \   // p \u3092\u542B\u3080 run\u3002\u7121\u3051\u308C\u3070 end()\n    iterator\
    \ find(T p) const {\n        auto it = runs.upper_bound(p);\n        if (it ==\
    \ runs.begin()) return runs.end();\n        it--;\n        if (it->r <= p) return\
    \ runs.end();\n        return it;\n    }\n    bool contains(T p) const {\n   \
    \     return find(p) != runs.end();\n    }\n    void assign(T l, T r, S x) {\n\
    \        assign(l, r, x, [](T, T, const S&) {}, [](T, T, const S&) {});\n    }\n\
    \    // f: \u3067\u304D\u305F run \u3054\u3068\u306B\u547C\u3076, g: \u6D88\u3048\
    \u305F run \u3054\u3068\u306B\u547C\u3076\n    template <class F, class G>\n \
    \   void assign(T l, T r, S x, const F& f, const G& g) {\n        assert(l < r);\n\
    \        {\n            auto it = find(l);\n            if (it != runs.end() &&\
    \ r <= it->r && it->x == x) return;\n        }\n        T nl = l, nr = r;\n  \
    \      std::optional<run> left, right;\n        auto first = runs.upper_bound(l);\n\
    \        if (first != runs.begin()) {\n            auto p = std::prev(first);\n\
    \            if (l < p->r) {\n                first = p;\n                if (p->l\
    \ < l) {\n                    if (p->x == x) {\n                        nl = p->l;\n\
    \                    } else {\n                        left = run{p->l, l, p->x};\n\
    \                    }\n                }\n            } else if (p->r == l &&\
    \ p->x == x) {\n                first = p;\n                nl = p->l;\n     \
    \       }\n        }\n        if (first != runs.end() && first != runs.begin()\
    \ && first->l == l) {\n            auto p = std::prev(first);\n            if\
    \ (p->r == l && p->x == x) {\n                first = p;\n                nl =\
    \ p->l;\n            }\n        }\n        auto last = runs.lower_bound(r);\n\
    \        if (last != runs.begin()) {\n            auto q = std::prev(last);\n\
    \            if (r < q->r) {\n                if (q->x == x) {\n             \
    \       nr = q->r;\n                } else {\n                    right = run{r,\
    \ q->r, q->x};\n                }\n            }\n        }\n        if (last\
    \ != runs.end() && last->l == r && last->x == x) {\n            nr = last->r;\n\
    \            last++;\n        }\n        for (auto it = first; it != last;) {\n\
    \            g(it->l, it->r, it->x);\n            it = runs.erase(it);\n     \
    \   }\n        if (left) {\n            runs.insert(*left);\n            f(left->l,\
    \ left->r, left->x);\n        }\n        runs.insert({nl, nr, x});\n        f(nl,\
    \ nr, x);\n        if (right) {\n            runs.insert(*right);\n          \
    \  f(right->l, right->r, right->x);\n        }\n    }\n    void erase(T l, T r)\
    \ {\n        erase(l, r, [](T, T, const S&) {}, [](T, T, const S&) {});\n    }\n\
    \    template <class F, class G>\n    void erase(T l, T r, const F& f, const G&\
    \ g) {\n        assert(l < r);\n        auto it = runs.upper_bound(l);\n     \
    \   if (it != runs.begin() && l < std::prev(it)->r) it--;\n        while (it !=\
    \ runs.end() && it->l < r) {\n            run cur = *it;\n            g(cur.l,\
    \ cur.r, cur.x);\n            it = runs.erase(it);\n            if (cur.l < l)\
    \ {\n                runs.insert({cur.l, l, cur.x});\n                f(cur.l,\
    \ l, cur.x);\n            }\n            if (r < cur.r) {\n                runs.insert({r,\
    \ cur.r, cur.x});\n                f(r, cur.r, cur.x);\n            }\n      \
    \  }\n    }\n    int size() const {\n        return int(runs.size());\n    }\n\
    \    iterator begin() const {\n        return runs.begin();\n    }\n    iterator\
    \ end() const {\n        return runs.end();\n    }\n\nprivate:\n    std::set<run,\
    \ cmp> runs;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_map.hpp
  requiredBy: []
  timestamp: '2026-10-19 22:21:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1601_2.test.cpp
  - test/unit/range_map.test.cpp
documentation_of: datastructure/range_map.hpp
layout: document
title: Range Map
---

### 概要
- 区間ごとに値を持つ map。

### 使い方
- `range_map<T, S>`: 座標の型 `T`、値の型 `S`。`S` は `==` で比較できる必要がある。
- `assign(l, r, x)`: $[l, r)$ の値を `x` にする。
- `assign(l, r, x, f, g)`: $[l, r)$ の値を `x` にする。削除された区間ごとに `g(l, r, x)`、追加された区間ごとに `f(l, r, x)` を呼ぶ。隣り合う区間の値が等しければ 1 つの区間にまとまる。
- `erase(l, r)`: $[l, r)$ の値を削除する。
- `erase(l, r, f, g)`: $[l, r)$ の値を削除する。コールバックは `assign` と同じ。
- `find(p)`: `p` を含む区間のイテレータ。存在しなければ `end()`。
- `contains(p)`: `p` を含む区間が存在するか。
- `size()`: 区間の個数。
- range-for で区間を昇順に列挙する。各要素は `l`, `r`, `x` を持つ。

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
