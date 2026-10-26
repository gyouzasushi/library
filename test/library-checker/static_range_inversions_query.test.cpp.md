---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/library-checker/static_range_inversions_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 3 \"algorithm/mo.hpp\"\
    \n#include <cassert>\n#include <cmath>\n#include <cstdlib>\n#include <numeric>\n\
    #include <utility>\n#line 9 \"algorithm/mo.hpp\"\n\nstruct mo {\n    mo() = default;\n\
    \    int add(int l, int r) {\n        assert(0 <= l && l <= r);\n        lr.emplace_back(l,\
    \ r);\n        return (int)lr.size() - 1;\n    }\n    void run(auto add_left,\
    \ auto add_right, auto erase_left, auto erase_right,\n             auto out) const\
    \ {\n        int l = 0, r = 0;\n        for (int i : order()) {\n            while\
    \ (l > lr[i].first) add_left(--l);\n            while (r < lr[i].second) add_right(r++);\n\
    \            while (l < lr[i].first) erase_left(l++);\n            while (r >\
    \ lr[i].second) erase_right(--r);\n            out(i);\n        }\n    }\n   \
    \ void run(auto add, auto erase, auto out) const {\n        run(add, add, erase,\
    \ erase, out);\n    }\n\n  private:\n    std::vector<std::pair<int, int>> lr;\n\
    \    std::vector<int> order() const {\n        int q = lr.size();\n        if\
    \ (q == 0) return {};\n        int n = 1;\n        for (auto [l, r] : lr) n =\
    \ std::max(n, r);\n        int w = std::max(1, (int)(std::sqrt(3.0) * n / std::sqrt(2.0\
    \ * q)));\n        std::vector<int> ord(q);\n        std::iota(ord.begin(), ord.end(),\
    \ 0);\n        std::sort(ord.begin(), ord.end(), [&](int a, int b) {\n       \
    \     int ba = lr[a].first / w, bb = lr[b].first / w;\n            if (ba != bb)\
    \ return ba < bb;\n            return (ba & 1) ? lr[a].second > lr[b].second\n\
    \                            : lr[a].second < lr[b].second;\n        });\n   \
    \     auto cost = [&](int a, int b) {\n            return std::abs(lr[ord[a]].first\
    \ - lr[ord[b]].first) +\n                   std::abs(lr[ord[a]].second - lr[ord[b]].second);\n\
    \        };\n        auto improve = [&](int k) {\n            if (cost(k, k +\
    \ 2) + cost(k + 1, k + 3) <\n                cost(k, k + 1) + cost(k + 2, k +\
    \ 3))\n                std::swap(ord[k + 1], ord[k + 2]);\n            if (cost(k,\
    \ k + 3) + cost(k + 1, k + 4) <\n                cost(k, k + 1) + cost(k + 3,\
    \ k + 4))\n                std::swap(ord[k + 1], ord[k + 3]);\n        };\n  \
    \      for (int k = 0; k + 5 <= q; k++) improve(k);\n        for (int k = q -\
    \ 5; k >= 0; k--) improve(k);\n        return ord;\n    }\n};\n#line 1 \"atcoder/fenwicktree.hpp\"\
    \n\n\n\n#line 6 \"atcoder/fenwicktree.hpp\"\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 6 \"atcoder/internal_type_traits.hpp\"\n#include <type_traits>\n\
    \nnamespace atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class\
    \ T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 8 \"test/library-checker/static_range_inversions_query.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<int>\
    \ a(n);\n    for (auto& x : a) std::cin >> x;\n    std::vector<int> v = a;\n \
    \   std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(), v.end()),\
    \ v.end());\n    for (auto& x : a) x = std::lower_bound(v.begin(), v.end(), x)\
    \ - v.begin();\n    int m = v.size();\n    mo mo;\n    for (int i = 0; i < q;\
    \ i++) {\n        int l, r;\n        std::cin >> l >> r;\n        mo.add(l, r);\n\
    \    }\n    atcoder::fenwick_tree<int> ft(m);\n    long long inv = 0;\n    int\
    \ size = 0;\n    std::vector<long long> ans(q);\n    mo.run([&](int i) { inv +=\
    \ ft.sum(0, a[i]); ft.add(a[i], 1); size++; },\n           [&](int i) { inv +=\
    \ size - ft.sum(0, a[i] + 1); ft.add(a[i], 1); size++; },\n           [&](int\
    \ i) { ft.add(a[i], -1); size--; inv -= ft.sum(0, a[i]); },\n           [&](int\
    \ i) { ft.add(a[i], -1); size--; inv -= size - ft.sum(0, a[i] + 1); },\n     \
    \      [&](int k) { ans[k] = inv; });\n    for (auto x : ans) std::cout << x <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    algorithm/mo.hpp\"\n#include \"atcoder/fenwicktree.hpp\"\n\nint main() {\n   \
    \ int n, q;\n    std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (auto&\
    \ x : a) std::cin >> x;\n    std::vector<int> v = a;\n    std::sort(v.begin(),\
    \ v.end());\n    v.erase(std::unique(v.begin(), v.end()), v.end());\n    for (auto&\
    \ x : a) x = std::lower_bound(v.begin(), v.end(), x) - v.begin();\n    int m =\
    \ v.size();\n    mo mo;\n    for (int i = 0; i < q; i++) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        mo.add(l, r);\n    }\n    atcoder::fenwick_tree<int>\
    \ ft(m);\n    long long inv = 0;\n    int size = 0;\n    std::vector<long long>\
    \ ans(q);\n    mo.run([&](int i) { inv += ft.sum(0, a[i]); ft.add(a[i], 1); size++;\
    \ },\n           [&](int i) { inv += size - ft.sum(0, a[i] + 1); ft.add(a[i],\
    \ 1); size++; },\n           [&](int i) { ft.add(a[i], -1); size--; inv -= ft.sum(0,\
    \ a[i]); },\n           [&](int i) { ft.add(a[i], -1); size--; inv -= size - ft.sum(0,\
    \ a[i] + 1); },\n           [&](int k) { ans[k] = inv; });\n    for (auto x :\
    \ ans) std::cout << x << '\\n';\n}\n"
  dependsOn:
  - algorithm/mo.hpp
  isVerificationFile: true
  path: test/library-checker/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 21:19:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/static_range_inversions_query.test.cpp
- /verify/test/library-checker/static_range_inversions_query.test.cpp.html
title: test/library-checker/static_range_inversions_query.test.cpp
---
