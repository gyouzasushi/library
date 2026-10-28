---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/semiring_max_plus.hpp
    title: 'Semiring: Max Plus'
  - icon: ':heavy_check_mark:'
    path: algebra/semiring_min_plus.hpp
    title: 'Semiring: Min Plus'
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/matrix.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <atcoder/modint>\n#include <cassert>\n#include <iostream>\n#include\
    \ <limits>\n#include <random>\n#include <vector>\n\n#line 2 \"algebra/semiring_max_plus.hpp\"\
    \n#include <algorithm>\n#line 4 \"algebra/semiring_max_plus.hpp\"\ntemplate <class\
    \ T>\nstruct semiring_max_plus {\n    using S = T;\n    static S add(S a, S b)\
    \ {\n        return std::max(a, b);\n    }\n    static S zero() {\n        return\
    \ std::numeric_limits<T>::lowest();\n    }\n    static S mul(S a, S b) {\n   \
    \     if (a == zero() || b == zero()) return zero();\n        return a + b;\n\
    \    }\n    static S one() {\n        return T(0);\n    }\n};\n#line 4 \"algebra/semiring_min_plus.hpp\"\
    \ntemplate <class T>\nstruct semiring_min_plus {\n    using S = T;\n    static\
    \ S add(S a, S b) {\n        return std::min(a, b);\n    }\n    static S zero()\
    \ {\n        return std::numeric_limits<T>::max();\n    }\n    static S mul(S\
    \ a, S b) {\n        if (a == zero() || b == zero()) return zero();\n        return\
    \ a + b;\n    }\n    static S one() {\n        return T(0);\n    }\n};\n#line\
    \ 3 \"math/matrix.hpp\"\n#include <optional>\n#include <utility>\n#line 6 \"math/matrix.hpp\"\
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
    \ ret;\n}\n#line 12 \"test/unit/matrix.test.cpp\"\nusing mint = atcoder::modint998244353;\n\
    int main() {\n    std::mt19937 rng(7959);\n    for (int trial = 0; trial < 50;\
    \ trial++) {\n        int n = 1 + rng() % 5, m = 1 + rng() % 5, k = 1 + rng()\
    \ % 5;\n        matrix<mint> a(n, m), b(m, k), c(n, m);\n        for (int i =\
    \ 0; i < n; i++)\n            for (int j = 0; j < m; j++) a[i][j] = rng(), c[i][j]\
    \ = rng();\n        for (int i = 0; i < m; i++)\n            for (int j = 0; j\
    \ < k; j++) b[i][j] = rng();\n        auto ab = a * b;\n        assert(ab.height()\
    \ == n && ab.width() == k);\n        for (int i = 0; i < n; i++) {\n         \
    \   for (int j = 0; j < k; j++) {\n                mint s = 0;\n             \
    \   for (int l = 0; l < m; l++) s += a[i][l] * b[l][j];\n                assert(ab[i][j]\
    \ == s);\n            }\n        }\n        auto ac = a + c;\n        for (int\
    \ i = 0; i < n; i++)\n            for (int j = 0; j < m; j++) assert(ac[i][j]\
    \ == a[i][j] + c[i][j]);\n        auto d = a;\n        d += c;\n        assert(d\
    \ == ac);\n        matrix<mint> sq(n, n);\n        for (int i = 0; i < n; i++)\n\
    \            for (int j = 0; j < n; j++) sq[i][j] = rng() % 3;\n        int e\
    \ = rng() % 6;\n        auto naive = matrix<mint>::e(n);\n        for (int t =\
    \ 0; t < e; t++) naive *= sq;\n        assert(sq.pow(e) == naive);\n        assert(sq\
    \ * matrix<mint>::e(n) == sq);\n    }\n    for (int trial = 0; trial < 50; trial++)\
    \ {\n        using R = semiring_min_plus<long long>;\n        const long long\
    \ inf = R::zero();\n        int n = 1 + rng() % 5;\n        semiring_matrix<R>\
    \ g(n, n);\n        for (int i = 0; i < n; i++)\n            for (int j = 0; j\
    \ < n; j++)\n                if (rng() % 2) g[i][j] = rng() % 10;\n        int\
    \ k = rng() % 6;\n        std::vector<std::vector<long long>> dp(n, std::vector<long\
    \ long>(n, inf));\n        for (int i = 0; i < n; i++) dp[i][i] = 0;\n       \
    \ for (int t = 0; t < k; t++) {\n            std::vector<std::vector<long long>>\
    \ nx(n, std::vector<long long>(n, inf));\n            for (int i = 0; i < n; i++)\n\
    \                for (int j = 0; j < n; j++)\n                    if (dp[i][j]\
    \ != inf)\n                        for (int l = 0; l < n; l++)\n             \
    \               if (g[j][l] != inf) nx[i][l] = std::min(nx[i][l], dp[i][j] + g[j][l]);\n\
    \            dp = nx;\n        }\n        assert(g.pow(k) == semiring_matrix<R>(dp));\n\
    \    }\n    {\n        using R = semiring_max_plus<long long>;\n        semiring_matrix<R>\
    \ g(std::vector<std::vector<long long>>{{R::zero(), 3}, {5, R::zero()}});\n  \
    \      auto g2 = g * g;\n        assert(g2[0][0] == 8 && g2[1][1] == 8 && g2[0][1]\
    \ == R::zero());\n        assert(semiring_matrix<R>::e(2)[0][1] == R::zero() &&\
    \ semiring_matrix<R>::e(2)[0][0] == 0);\n    }\n    {\n        matrix<int> z;\n\
    \        assert(z.height() == 0 && z.width() == 0);\n        assert(matrix<int>(0,\
    \ 0).pow(5) == matrix<int>());\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <atcoder/modint>\n#include <cassert>\n#include <iostream>\n#include\
    \ <limits>\n#include <random>\n#include <vector>\n\n#include \"algebra/semiring_max_plus.hpp\"\
    \n#include \"algebra/semiring_min_plus.hpp\"\n#include \"math/matrix.hpp\"\nusing\
    \ mint = atcoder::modint998244353;\nint main() {\n    std::mt19937 rng(7959);\n\
    \    for (int trial = 0; trial < 50; trial++) {\n        int n = 1 + rng() % 5,\
    \ m = 1 + rng() % 5, k = 1 + rng() % 5;\n        matrix<mint> a(n, m), b(m, k),\
    \ c(n, m);\n        for (int i = 0; i < n; i++)\n            for (int j = 0; j\
    \ < m; j++) a[i][j] = rng(), c[i][j] = rng();\n        for (int i = 0; i < m;\
    \ i++)\n            for (int j = 0; j < k; j++) b[i][j] = rng();\n        auto\
    \ ab = a * b;\n        assert(ab.height() == n && ab.width() == k);\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int j = 0; j < k; j++) {\n     \
    \           mint s = 0;\n                for (int l = 0; l < m; l++) s += a[i][l]\
    \ * b[l][j];\n                assert(ab[i][j] == s);\n            }\n        }\n\
    \        auto ac = a + c;\n        for (int i = 0; i < n; i++)\n            for\
    \ (int j = 0; j < m; j++) assert(ac[i][j] == a[i][j] + c[i][j]);\n        auto\
    \ d = a;\n        d += c;\n        assert(d == ac);\n        matrix<mint> sq(n,\
    \ n);\n        for (int i = 0; i < n; i++)\n            for (int j = 0; j < n;\
    \ j++) sq[i][j] = rng() % 3;\n        int e = rng() % 6;\n        auto naive =\
    \ matrix<mint>::e(n);\n        for (int t = 0; t < e; t++) naive *= sq;\n    \
    \    assert(sq.pow(e) == naive);\n        assert(sq * matrix<mint>::e(n) == sq);\n\
    \    }\n    for (int trial = 0; trial < 50; trial++) {\n        using R = semiring_min_plus<long\
    \ long>;\n        const long long inf = R::zero();\n        int n = 1 + rng()\
    \ % 5;\n        semiring_matrix<R> g(n, n);\n        for (int i = 0; i < n; i++)\n\
    \            for (int j = 0; j < n; j++)\n                if (rng() % 2) g[i][j]\
    \ = rng() % 10;\n        int k = rng() % 6;\n        std::vector<std::vector<long\
    \ long>> dp(n, std::vector<long long>(n, inf));\n        for (int i = 0; i < n;\
    \ i++) dp[i][i] = 0;\n        for (int t = 0; t < k; t++) {\n            std::vector<std::vector<long\
    \ long>> nx(n, std::vector<long long>(n, inf));\n            for (int i = 0; i\
    \ < n; i++)\n                for (int j = 0; j < n; j++)\n                   \
    \ if (dp[i][j] != inf)\n                        for (int l = 0; l < n; l++)\n\
    \                            if (g[j][l] != inf) nx[i][l] = std::min(nx[i][l],\
    \ dp[i][j] + g[j][l]);\n            dp = nx;\n        }\n        assert(g.pow(k)\
    \ == semiring_matrix<R>(dp));\n    }\n    {\n        using R = semiring_max_plus<long\
    \ long>;\n        semiring_matrix<R> g(std::vector<std::vector<long long>>{{R::zero(),\
    \ 3}, {5, R::zero()}});\n        auto g2 = g * g;\n        assert(g2[0][0] ==\
    \ 8 && g2[1][1] == 8 && g2[0][1] == R::zero());\n        assert(semiring_matrix<R>::e(2)[0][1]\
    \ == R::zero() && semiring_matrix<R>::e(2)[0][0] == 0);\n    }\n    {\n      \
    \  matrix<int> z;\n        assert(z.height() == 0 && z.width() == 0);\n      \
    \  assert(matrix<int>(0, 0).pow(5) == matrix<int>());\n    }\n    std::cout <<\
    \ \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - algebra/semiring_max_plus.hpp
  - algebra/semiring_min_plus.hpp
  - math/matrix.hpp
  - algebra/concept.hpp
  - algebra/semiring_plus_times.hpp
  isVerificationFile: true
  path: test/unit/matrix.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 18:39:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/unit/matrix.test.cpp
- /verify/test/unit/matrix.test.cpp.html
title: test/unit/matrix.test.cpp
---
