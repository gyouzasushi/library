---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/semiring_plus_times.hpp
    title: 'Semiring: Plus Times'
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library-checker/matrix_product.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include <atcoder/modint>\n\
    #include <iostream>\n\n#line 2 \"math/matrix.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\n\
    template <class M>\nconcept semigroup = requires(typename M::S a, typename M::S\
    \ b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n};\ntemplate <class\
    \ M>\nconcept monoid = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename\
    \ M::S>;\n};\ntemplate <class A>\nconcept action = requires(typename A::F f, typename\
    \ A::F g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n  \
    \  { A::id() } -> std::same_as<typename A::F>;\n    { A::composition_commutative\
    \ } -> std::convertible_to<bool>;\n};\ntemplate <class A>\nconcept acted_monoid\
    \ = monoid<A> && action<A> && requires(typename A::S x, typename A::F f) {\n \
    \   { A::mapping(f, x) } -> std::same_as<typename A::S>;\n};\ntemplate <class\
    \ R>\nconcept semiring = requires(typename R::S a, typename R::S b) {\n    { R::add(a,\
    \ b) } -> std::same_as<typename R::S>;\n    { R::zero() } -> std::same_as<typename\
    \ R::S>;\n    { R::mul(a, b) } -> std::same_as<typename R::S>;\n    { R::one()\
    \ } -> std::same_as<typename R::S>;\n};\n#line 2 \"algebra/semiring_plus_times.hpp\"\
    \ntemplate <class T>\nstruct semiring_plus_times {\n    using S = T;\n    static\
    \ S add(S a, S b) {\n        return a + b;\n    }\n    static S zero() {\n   \
    \     return T(0);\n    }\n    static S mul(S a, S b) {\n        return a * b;\n\
    \    }\n    static S one() {\n        return T(1);\n    }\n};\n#line 8 \"math/matrix.hpp\"\
    \ntemplate <semiring R>\nstruct semiring_matrix {\n    using S = typename R::S;\n\
    \    semiring_matrix() : semiring_matrix(0, 0) {}\n    semiring_matrix(int h,\
    \ int w) : h(h), w(w), a(h, std::vector<S>(w, R::zero())) {}\n    explicit semiring_matrix(std::vector<std::vector<S>>\
    \ v) : h(int(v.size())), w(h ? int(v[0].size()) : 0), a(std::move(v)) {\n    \
    \    for (int i = 0; i < h; i++) assert(int(a[i].size()) == w);\n    }\n    static\
    \ semiring_matrix e(int n) {\n        semiring_matrix ret(n, n);\n        for\
    \ (int i = 0; i < n; i++) ret[i][i] = R::one();\n        return ret;\n    }\n\
    \    int height() const {\n        return h;\n    }\n    int width() const {\n\
    \        return w;\n    }\n    const std::vector<S>& operator[](int i) const {\n\
    \        return a[i];\n    }\n    std::vector<S>& operator[](int i) {\n      \
    \  return a[i];\n    }\n    friend semiring_matrix operator+(const semiring_matrix&\
    \ lhs, const semiring_matrix& rhs) {\n        assert(lhs.h == rhs.h && lhs.w ==\
    \ rhs.w);\n        semiring_matrix ret(lhs.h, lhs.w);\n        for (int i = 0;\
    \ i < lhs.h; i++) {\n            for (int j = 0; j < lhs.w; j++) ret[i][j] = R::add(lhs[i][j],\
    \ rhs[i][j]);\n        }\n        return ret;\n    }\n    friend semiring_matrix\
    \ operator*(const semiring_matrix& lhs, const semiring_matrix& rhs) {\n      \
    \  assert(lhs.w == rhs.h);\n        semiring_matrix ret(lhs.h, rhs.w);\n     \
    \   for (int i = 0; i < lhs.h; i++) {\n            for (int k = 0; k < lhs.w;\
    \ k++) {\n                for (int j = 0; j < rhs.w; j++) ret[i][j] = R::add(ret[i][j],\
    \ R::mul(lhs[i][k], rhs[k][j]));\n            }\n        }\n        return ret;\n\
    \    }\n    semiring_matrix& operator+=(const semiring_matrix& rhs) {\n      \
    \  return *this = *this + rhs;\n    }\n    semiring_matrix& operator*=(const semiring_matrix&\
    \ rhs) {\n        return *this = *this * rhs;\n    }\n    semiring_matrix pow(long\
    \ long k) const {\n        assert(h == w && k >= 0);\n        semiring_matrix\
    \ x = *this, ret = e(h);\n        while (k) {\n            if (k & 1) ret *= x;\n\
    \            x *= x;\n            k >>= 1;\n        }\n        return ret;\n \
    \   }\n    friend bool operator==(const semiring_matrix& lhs, const semiring_matrix&\
    \ rhs) {\n        return lhs.a == rhs.a;\n    }\n\nprivate:\n    int h, w;\n \
    \   std::vector<std::vector<S>> a;\n};\ntemplate <class T>\nusing matrix = semiring_matrix<semiring_plus_times<T>>;\n\
    #line 6 \"test/library-checker/matrix_product.test.cpp\"\nusing mint = atcoder::modint998244353;\n\
    int main() {\n    int n, m, k;\n    std::cin >> n >> m >> k;\n    matrix<mint>\
    \ a(n, m);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m;\
    \ j++) {\n            int x;\n            std::cin >> x;\n            a[i][j]\
    \ = mint::raw(x);\n        }\n    }\n    matrix<mint> b(m, k);\n    for (int i\
    \ = 0; i < m; i++) {\n        for (int j = 0; j < k; j++) {\n            int x;\n\
    \            std::cin >> x;\n            b[i][j] = mint::raw(x);\n        }\n\
    \    }\n    matrix c = a * b;\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j < k; j++) {\n            std::cout << c[i][j].val() << \" \\n\"\
    [j == k - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <atcoder/modint>\n#include <iostream>\n\n#include \"math/matrix.hpp\"\nusing\
    \ mint = atcoder::modint998244353;\nint main() {\n    int n, m, k;\n    std::cin\
    \ >> n >> m >> k;\n    matrix<mint> a(n, m);\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j = 0; j < m; j++) {\n            int x;\n            std::cin\
    \ >> x;\n            a[i][j] = mint::raw(x);\n        }\n    }\n    matrix<mint>\
    \ b(m, k);\n    for (int i = 0; i < m; i++) {\n        for (int j = 0; j < k;\
    \ j++) {\n            int x;\n            std::cin >> x;\n            b[i][j]\
    \ = mint::raw(x);\n        }\n    }\n    matrix c = a * b;\n    for (int i = 0;\
    \ i < n; i++) {\n        for (int j = 0; j < k; j++) {\n            std::cout\
    \ << c[i][j].val() << \" \\n\"[j == k - 1];\n        }\n    }\n}"
  dependsOn:
  - math/matrix.hpp
  - algebra/concept.hpp
  - algebra/semiring_plus_times.hpp
  isVerificationFile: true
  path: test/library-checker/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 22:22:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/matrix_product.test.cpp
- /verify/test/library-checker/matrix_product.test.cpp.html
title: test/library-checker/matrix_product.test.cpp
---
