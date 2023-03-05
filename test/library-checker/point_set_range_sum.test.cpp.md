---
data:
  _extendedDependsOn: []
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
    \n#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
    \n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#line 5 \"atcoder/internal_type_traits.hpp\"\
    \n#include <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value ||\n       \
    \                           std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
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
    \ atcoder\n\n\n#line 5 \"test/library-checker/point_set_range_sum.test.cpp\"\n\
    int main() {\n    int n, q;\n    std::cin >> n >> q;\n    atcoder::fenwick_tree<long\
    \ long> ft(n);\n    for (int i = 0; i < n; i++) {\n        long long a;\n    \
    \    std::cin >> a;\n        ft.add(i, a - ft.sum(i, i + 1));\n    }\n    while\
    \ (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n   \
    \         int p;\n            long long x;\n            std::cin >> p >> x;\n\
    \            long long d = ft.sum(p, p + 1) + x;\n            ft.add(p, d - ft.sum(p,\
    \ p + 1));\n        }\n        if (t == 1) {\n            int l, r;\n        \
    \    std::cin >> l >> r;\n            std::cout << ft.sum(l, r) << '\\n';\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n\n#include \"atcoder/fenwicktree.hpp\"\nint main() {\n  \
    \  int n, q;\n    std::cin >> n >> q;\n    atcoder::fenwick_tree<long long> ft(n);\n\
    \    for (int i = 0; i < n; i++) {\n        long long a;\n        std::cin >>\
    \ a;\n        ft.add(i, a - ft.sum(i, i + 1));\n    }\n    while (q--) {\n   \
    \     int t;\n        std::cin >> t;\n        if (t == 0) {\n            int p;\n\
    \            long long x;\n            std::cin >> p >> x;\n            long long\
    \ d = ft.sum(p, p + 1) + x;\n            ft.add(p, d - ft.sum(p, p + 1));\n  \
    \      }\n        if (t == 1) {\n            int l, r;\n            std::cin >>\
    \ l >> r;\n            std::cout << ft.sum(l, r) << '\\n';\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/point_set_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 19:19:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/point_set_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_set_range_sum.test.cpp
- /verify/test/library-checker/point_set_range_sum.test.cpp.html
title: test/library-checker/point_set_range_sum.test.cpp
---
