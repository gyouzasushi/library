---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/fenwick_tree.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library-checker/point_set_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <iostream>\n\
    \n#line 2 \"datastructure/fenwick_tree.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <type_traits>\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class\
    \ T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type, std::false_type>::type;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type, std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t,\n                              unsigned __int128>;\n\
    \ntemplate <class T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                  is_signed_int128<T>::value ||\n      \
    \                            is_unsigned_int128<T>::value,\n                 \
    \             std::true_type, std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int =\n    typename std::conditional<(is_integral<T>::value &&\n\
    \                               std::is_signed<T>::value) ||\n               \
    \                   is_signed_int128<T>::value,\n                            \
    \  std::true_type, std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int\
    \ =\n    typename std::conditional<(is_integral<T>::value &&\n               \
    \                std::is_unsigned<T>::value) ||\n                            \
    \      is_unsigned_int128<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing to_unsigned = typename\
    \ std::conditional<\n    is_signed_int128<T>::value, make_unsigned_int128<T>,\n\
    \    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,\n\
    \                              std::common_type<T>>::type>::type;\n\n#else\n\n\
    template <class T>\nusing is_integral = typename std::is_integral<T>;\n\ntemplate\
    \ <class T>\nusing is_signed_int =\n    typename std::conditional<is_integral<T>::value\
    \ && std::is_signed<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <class T>\nusing to_unsigned =\n    typename\
    \ std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,\n         \
    \                     std::common_type<T>>::type;\n\n#endif\n\ntemplate <class\
    \ T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T>\nusing to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n#line 88 \"datastructure/fenwick_tree.hpp\"\n#include\
    \ <vector>\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate\
    \ <class T>\nstruct FenwickTree {\n    using U = internal::to_unsigned_t<T>;\n\
    \npublic:\n    FenwickTree() : _n(0) {\n    }\n    FenwickTree(int n) : _n(n),\
    \ data(n) {\n    }\n\n    void add(int p, T x) {\n        assert(0 <= p && p <\
    \ _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] += U(x);\n\
    \            p += p & -p;\n        }\n    }\n\n    void set(int p, T x) {\n  \
    \      assert(0 <= p && p < _n);\n        T d = x - sum(p, p + 1);\n        add(p,\
    \ d);\n    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        return sum(r) - sum(l);\n    }\n\n    int lower_bound(T x)\
    \ {\n        int i = 0;\n        for (int k = 1 << (std::__lg(_n) + 1); k > 0;\
    \ k >>= 1) {\n            if (i + k - 1 < _n && data[i + k - 1] < U(x)) {\n  \
    \              x -= data[i + k - 1];\n                i += k;\n            }\n\
    \        }\n        return i;\n    }\n\n    int upper_bound(T x) {\n        int\
    \ i = 0;\n        for (int k = 1 << (std::__lg(_n) + 1); k > 0; k >>= 1) {\n \
    \           if (i + k - 1 < _n && data[i + k - 1] <= U(x)) {\n               \
    \ x -= data[i + k - 1];\n                i += k;\n            }\n        }\n \
    \       return i;\n    }\n\nprivate:\n    int _n;\n    std::vector<U> data;\n\
    \    U sum(int r) {\n        U s = 0;\n        while (r > 0) {\n            s\
    \ += data[r - 1];\n            r -= r & -r;\n        }\n        return s;\n  \
    \  }\n};\n#line 5 \"test/library-checker/point_set_range_sum.test.cpp\"\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    FenwickTree<long long> ft(n);\n\
    \    for (int i = 0; i < n; i++) {\n        long long a;\n        std::cin >>\
    \ a;\n        ft.set(i, a);\n    }\n    while (q--) {\n        int t;\n      \
    \  std::cin >> t;\n        if (t == 0) {\n            int p;\n            long\
    \ long x;\n            std::cin >> p >> x;\n            long long d = ft.sum(p,\
    \ p + 1) + x;\n            ft.set(p, d);\n        }\n        if (t == 1) {\n \
    \           int l, r;\n            std::cin >> l >> r;\n            std::cout\
    \ << ft.sum(l, r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n\n#include \"../../datastructure/fenwick_tree.hpp\"\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    FenwickTree<long long>\
    \ ft(n);\n    for (int i = 0; i < n; i++) {\n        long long a;\n        std::cin\
    \ >> a;\n        ft.set(i, a);\n    }\n    while (q--) {\n        int t;\n   \
    \     std::cin >> t;\n        if (t == 0) {\n            int p;\n            long\
    \ long x;\n            std::cin >> p >> x;\n            long long d = ft.sum(p,\
    \ p + 1) + x;\n            ft.set(p, d);\n        }\n        if (t == 1) {\n \
    \           int l, r;\n            std::cin >> l >> r;\n            std::cout\
    \ << ft.sum(l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - datastructure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/library-checker/point_set_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-09-10 18:25:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/point_set_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_set_range_sum.test.cpp
- /verify/test/library-checker/point_set_range_sum.test.cpp.html
title: test/library-checker/point_set_range_sum.test.cpp
---
