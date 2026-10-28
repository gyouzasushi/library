---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_rank
    links:
    - https://judge.yosupo.jp/problem/matrix_rank
  bundledCode: "#line 1 \"test/library-checker/matrix_rank.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_rank\"\n#include <atcoder/modint>\n\
    #include <iostream>\n#include <vector>\n\n#line 2 \"math/matrix.hpp\"\n#include\
    \ <cassert>\n#include <optional>\n#include <utility>\n#line 6 \"math/matrix.hpp\"\
    \n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\n\
    concept semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a,\
    \ b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid\
    \ = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class G>\nconcept group = monoid<G> && requires(typename G::S a)\
    \ {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class A>\n\
    concept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\n#line 2 \"algebra/semiring_plus_times.hpp\"\
    \ntemplate <class T>\nstruct semiring_plus_times {\n    using S = T;\n    static\
    \ S add(S a, S b) {\n        return a + b;\n    }\n    static S zero() {\n   \
    \     return T(0);\n    }\n    static S mul(S a, S b) {\n        return a * b;\n\
    \    }\n    static S one() {\n        return T(1);\n    }\n};\n#line 9 \"math/matrix.hpp\"\
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
    template <class T> T determinant(matrix<T> a) {\n    int n = a.height();\n   \
    \ assert(n == a.width());\n    T det = 1;\n    for (int c = 0; c < n; c++) {\n\
    \        int p = c;\n        while (p < n && a[p][c] == T(0)) p++;\n        if\
    \ (p == n) return 0;\n        if (p != c) {\n            std::swap(a[p], a[c]);\n\
    \            det = -det;\n        }\n        det *= a[c][c];\n        T inv =\
    \ T(1) / a[c][c];\n        for (int i = c + 1; i < n; i++) {\n            if (a[i][c]\
    \ == T(0)) continue;\n            T f = a[i][c] * inv;\n            for (int j\
    \ = c; j < n; j++) a[i][j] -= f * a[c][j];\n        }\n    }\n    return det;\n\
    }\ntemplate <class T> std::optional<matrix<T>> inverse(matrix<T> a) {\n    int\
    \ n = a.height();\n    assert(n == a.width());\n    matrix<T> b = matrix<T>::e(n);\n\
    \    for (int c = 0; c < n; c++) {\n        int p = c;\n        while (p < n &&\
    \ a[p][c] == T(0)) p++;\n        if (p == n) return std::nullopt;\n        std::swap(a[p],\
    \ a[c]);\n        std::swap(b[p], b[c]);\n        T inv = T(1) / a[c][c];\n  \
    \      for (int j = 0; j < n; j++) {\n            a[c][j] *= inv;\n          \
    \  b[c][j] *= inv;\n        }\n        for (int i = 0; i < n; i++) {\n       \
    \     if (i == c || a[i][c] == T(0)) continue;\n            T f = a[i][c];\n \
    \           for (int j = 0; j < n; j++) {\n                a[i][j] -= f * a[c][j];\n\
    \                b[i][j] -= f * b[c][j];\n            }\n        }\n    }\n  \
    \  return b;\n}\ntemplate <class T> int matrix_rank(matrix<T> a) {\n    int h\
    \ = a.height(), w = a.width(), r = 0;\n    for (int c = 0; c < w && r < h; c++)\
    \ {\n        int p = r;\n        while (p < h && a[p][c] == T(0)) p++;\n     \
    \   if (p == h) continue;\n        std::swap(a[p], a[r]);\n        T inv = T(1)\
    \ / a[r][c];\n        for (int i = r + 1; i < h; i++) {\n            if (a[i][c]\
    \ == T(0)) continue;\n            T f = a[i][c] * inv;\n            for (int j\
    \ = c; j < w; j++) a[i][j] -= f * a[r][j];\n        }\n        r++;\n    }\n \
    \   return r;\n}\ntemplate <class T> struct linear_system_solution {\n    std::vector<T>\
    \ x;\n    std::vector<std::vector<T>> kernel;\n};\ntemplate <class T> std::optional<linear_system_solution<T>>\
    \ solve_linear_system(matrix<T> a, std::vector<T> b) {\n    int h = a.height(),\
    \ w = a.width();\n    assert(int(b.size()) == h);\n    std::vector<int> pivot;\n\
    \    int r = 0;\n    for (int c = 0; c < w && r < h; c++) {\n        int p = r;\n\
    \        while (p < h && a[p][c] == T(0)) p++;\n        if (p == h) continue;\n\
    \        std::swap(a[p], a[r]);\n        std::swap(b[p], b[r]);\n        T inv\
    \ = T(1) / a[r][c];\n        for (int j = c; j < w; j++) a[r][j] *= inv;\n   \
    \     b[r] *= inv;\n        for (int i = 0; i < h; i++) {\n            if (i ==\
    \ r || a[i][c] == T(0)) continue;\n            T f = a[i][c];\n            for\
    \ (int j = c; j < w; j++) a[i][j] -= f * a[r][j];\n            b[i] -= f * b[r];\n\
    \        }\n        pivot.push_back(c);\n        r++;\n    }\n    for (int i =\
    \ r; i < h; i++) {\n        if (b[i] != T(0)) return std::nullopt;\n    }\n  \
    \  linear_system_solution<T> ret;\n    ret.x.assign(w, T(0));\n    for (int i\
    \ = 0; i < r; i++) ret.x[pivot[i]] = b[i];\n    std::vector<bool> is_pivot(w,\
    \ false);\n    for (int c : pivot) is_pivot[c] = true;\n    for (int f = 0; f\
    \ < w; f++) {\n        if (is_pivot[f]) continue;\n        std::vector<T> v(w,\
    \ T(0));\n        v[f] = T(1);\n        for (int i = 0; i < r; i++) v[pivot[i]]\
    \ = -a[i][f];\n        ret.kernel.push_back(std::move(v));\n    }\n    return\
    \ ret;\n}\n#line 7 \"test/library-checker/matrix_rank.test.cpp\"\nusing mint =\
    \ atcoder::modint998244353;\nint main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    matrix<mint> a(n, m);\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j < m; j++) {\n            int x;\n            std::cin >> x;\n\
    \            a[i][j] = x;\n        }\n    }\n    std::cout << matrix_rank(a) <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_rank\"\n#include\
    \ <atcoder/modint>\n#include <iostream>\n#include <vector>\n\n#include \"math/matrix.hpp\"\
    \nusing mint = atcoder::modint998244353;\nint main() {\n    int n, m;\n    std::cin\
    \ >> n >> m;\n    matrix<mint> a(n, m);\n    for (int i = 0; i < n; i++) {\n \
    \       for (int j = 0; j < m; j++) {\n            int x;\n            std::cin\
    \ >> x;\n            a[i][j] = x;\n        }\n    }\n    std::cout << matrix_rank(a)\
    \ << '\\n';\n}\n"
  dependsOn:
  - math/matrix.hpp
  - algebra/concept.hpp
  - algebra/semiring_plus_times.hpp
  isVerificationFile: true
  path: test/library-checker/matrix_rank.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 18:39:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/matrix_rank.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/matrix_rank.test.cpp
- /verify/test/library-checker/matrix_rank.test.cpp.html
title: test/library-checker/matrix_rank.test.cpp
---
