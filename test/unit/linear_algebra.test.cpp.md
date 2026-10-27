---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':question:'
    path: algebra/semiring_plus_times.hpp
    title: 'Semiring: Plus Times'
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/unit/linear_algebra.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <atcoder/modint>\n#include <cassert>\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n#include <vector>\n\n#line 3 \"math/matrix.hpp\"\
    \n#include <optional>\n#include <utility>\n#line 6 \"math/matrix.hpp\"\n\n#line\
    \ 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\nconcept\
    \ semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a, b)\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid =\
    \ semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
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
    \ ret;\n}\n#line 11 \"test/unit/linear_algebra.test.cpp\"\nusing mint = atcoder::modint998244353;\n\
    mint det_brute(const matrix<mint>& a) {\n    int n = a.height();\n    std::vector<int>\
    \ p(n);\n    std::iota(p.begin(), p.end(), 0);\n    mint ret = 0;\n    do {\n\
    \        mint term = 1;\n        for (int i = 0; i < n; i++) term *= a[i][p[i]];\n\
    \        int inv = 0;\n        for (int i = 0; i < n; i++)\n            for (int\
    \ j = i + 1; j < n; j++) inv += p[i] > p[j];\n        ret += inv & 1 ? -term :\
    \ term;\n    } while (std::next_permutation(p.begin(), p.end()));\n    return\
    \ ret;\n}\n// rank = largest k with a nonsingular k x k minor\nint rank_brute(const\
    \ matrix<mint>& a) {\n    int h = a.height(), w = a.width();\n    for (int k =\
    \ std::min(h, w); k >= 1; k--) {\n        for (int rs = 0; rs < (1 << h); rs++)\
    \ {\n            if (__builtin_popcount(rs) != k) continue;\n            for (int\
    \ cs = 0; cs < (1 << w); cs++) {\n                if (__builtin_popcount(cs) !=\
    \ k) continue;\n                matrix<mint> m(k, k);\n                int i =\
    \ 0;\n                for (int r = 0; r < h; r++) {\n                    if (!(rs\
    \ >> r & 1)) continue;\n                    int j = 0;\n                    for\
    \ (int c = 0; c < w; c++) {\n                        if (cs >> c & 1) m[i][j++]\
    \ = a[r][c];\n                    }\n                    i++;\n              \
    \  }\n                if (det_brute(m) != 0) return k;\n            }\n      \
    \  }\n    }\n    return 0;\n}\nstd::vector<mint> mul(const matrix<mint>& a, const\
    \ std::vector<mint>& x) {\n    std::vector<mint> y(a.height());\n    for (int\
    \ i = 0; i < a.height(); i++)\n        for (int j = 0; j < a.width(); j++) y[i]\
    \ += a[i][j] * x[j];\n    return y;\n}\nint main() {\n    std::mt19937 rng(2026);\n\
    \    auto rnd = [&](int h, int w, int small) {\n        matrix<mint> a(h, w);\n\
    \        for (int i = 0; i < h; i++)\n            for (int j = 0; j < w; j++)\
    \ a[i][j] = small ? int(rng() % 3) : int(rng());\n        return a;\n    };\n\
    \    for (int it = 0; it < 300; it++) {\n        int n = rng() % 6;\n        matrix<mint>\
    \ a = rnd(n, n, rng() % 2);\n        mint d = determinant(a);\n        assert(d\
    \ == det_brute(a));\n        auto inv = inverse(a);\n        assert(inv.has_value()\
    \ == (d != 0));\n        if (inv) {\n            assert(a * *inv == matrix<mint>::e(n));\n\
    \            assert(*inv * a == matrix<mint>::e(n));\n            assert(determinant(*inv)\
    \ * d == 1);\n        }\n        assert(matrix_rank(a) == rank_brute(a));\n  \
    \  }\n    for (int it = 0; it < 300; it++) {\n        int h = rng() % 5, w = rng()\
    \ % 5;\n        matrix<mint> a = rnd(h, w, rng() % 2);\n        assert(matrix_rank(a)\
    \ == rank_brute(a));\n        std::vector<mint> b(h);\n        bool consistent\
    \ = rng() % 2;\n        if (consistent) {\n            std::vector<mint> x0(w);\n\
    \            for (auto& v : x0) v = int(rng() % 5);\n            b = mul(a, x0);\n\
    \        } else {\n            for (auto& v : b) v = int(rng() % 3);\n       \
    \ }\n        auto s = solve_linear_system(a, b);\n        if (consistent) assert(s.has_value());\n\
    \        if (!s) {\n            // b not in column space: rank of [a | b] exceeds\
    \ rank of a\n            matrix<mint> ab(h, w + 1);\n            for (int i =\
    \ 0; i < h; i++) {\n                for (int j = 0; j < w; j++) ab[i][j] = a[i][j];\n\
    \                ab[i][w] = b[i];\n            }\n            assert(matrix_rank(ab)\
    \ == matrix_rank(a) + 1);\n            continue;\n        }\n        int r = matrix_rank(a);\n\
    \        assert(int(s->kernel.size()) == w - r);\n        assert(mul(a, s->x)\
    \ == b);\n        matrix<mint> k(int(s->kernel.size()), w);\n        for (int\
    \ i = 0; i < int(s->kernel.size()); i++) {\n            assert(mul(a, s->kernel[i])\
    \ == std::vector<mint>(h));\n            k[i] = s->kernel[i];\n        }\n   \
    \     assert(matrix_rank(k) == int(s->kernel.size()));\n    }\n    {\n       \
    \ // 0 x 0\n        matrix<mint> z(0, 0);\n        assert(determinant(z) == 1\
    \ && inverse(z).has_value() && matrix_rank(z) == 0);\n        auto s = solve_linear_system(z,\
    \ {});\n        assert(s && s->x.empty() && s->kernel.empty());\n        // 500\
    \ x 500 timing\n        matrix<mint> a = rnd(500, 500, 0);\n        determinant(a);\n\
    \        inverse(a);\n        matrix_rank(a);\n        solve_linear_system(a,\
    \ std::vector<mint>(500, 1));\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <atcoder/modint>\n#include <cassert>\n#include\
    \ <iostream>\n#include <numeric>\n#include <random>\n#include <vector>\n\n#include\
    \ \"math/matrix.hpp\"\nusing mint = atcoder::modint998244353;\nmint det_brute(const\
    \ matrix<mint>& a) {\n    int n = a.height();\n    std::vector<int> p(n);\n  \
    \  std::iota(p.begin(), p.end(), 0);\n    mint ret = 0;\n    do {\n        mint\
    \ term = 1;\n        for (int i = 0; i < n; i++) term *= a[i][p[i]];\n       \
    \ int inv = 0;\n        for (int i = 0; i < n; i++)\n            for (int j =\
    \ i + 1; j < n; j++) inv += p[i] > p[j];\n        ret += inv & 1 ? -term : term;\n\
    \    } while (std::next_permutation(p.begin(), p.end()));\n    return ret;\n}\n\
    // rank = largest k with a nonsingular k x k minor\nint rank_brute(const matrix<mint>&\
    \ a) {\n    int h = a.height(), w = a.width();\n    for (int k = std::min(h, w);\
    \ k >= 1; k--) {\n        for (int rs = 0; rs < (1 << h); rs++) {\n          \
    \  if (__builtin_popcount(rs) != k) continue;\n            for (int cs = 0; cs\
    \ < (1 << w); cs++) {\n                if (__builtin_popcount(cs) != k) continue;\n\
    \                matrix<mint> m(k, k);\n                int i = 0;\n         \
    \       for (int r = 0; r < h; r++) {\n                    if (!(rs >> r & 1))\
    \ continue;\n                    int j = 0;\n                    for (int c =\
    \ 0; c < w; c++) {\n                        if (cs >> c & 1) m[i][j++] = a[r][c];\n\
    \                    }\n                    i++;\n                }\n        \
    \        if (det_brute(m) != 0) return k;\n            }\n        }\n    }\n \
    \   return 0;\n}\nstd::vector<mint> mul(const matrix<mint>& a, const std::vector<mint>&\
    \ x) {\n    std::vector<mint> y(a.height());\n    for (int i = 0; i < a.height();\
    \ i++)\n        for (int j = 0; j < a.width(); j++) y[i] += a[i][j] * x[j];\n\
    \    return y;\n}\nint main() {\n    std::mt19937 rng(2026);\n    auto rnd = [&](int\
    \ h, int w, int small) {\n        matrix<mint> a(h, w);\n        for (int i =\
    \ 0; i < h; i++)\n            for (int j = 0; j < w; j++) a[i][j] = small ? int(rng()\
    \ % 3) : int(rng());\n        return a;\n    };\n    for (int it = 0; it < 300;\
    \ it++) {\n        int n = rng() % 6;\n        matrix<mint> a = rnd(n, n, rng()\
    \ % 2);\n        mint d = determinant(a);\n        assert(d == det_brute(a));\n\
    \        auto inv = inverse(a);\n        assert(inv.has_value() == (d != 0));\n\
    \        if (inv) {\n            assert(a * *inv == matrix<mint>::e(n));\n   \
    \         assert(*inv * a == matrix<mint>::e(n));\n            assert(determinant(*inv)\
    \ * d == 1);\n        }\n        assert(matrix_rank(a) == rank_brute(a));\n  \
    \  }\n    for (int it = 0; it < 300; it++) {\n        int h = rng() % 5, w = rng()\
    \ % 5;\n        matrix<mint> a = rnd(h, w, rng() % 2);\n        assert(matrix_rank(a)\
    \ == rank_brute(a));\n        std::vector<mint> b(h);\n        bool consistent\
    \ = rng() % 2;\n        if (consistent) {\n            std::vector<mint> x0(w);\n\
    \            for (auto& v : x0) v = int(rng() % 5);\n            b = mul(a, x0);\n\
    \        } else {\n            for (auto& v : b) v = int(rng() % 3);\n       \
    \ }\n        auto s = solve_linear_system(a, b);\n        if (consistent) assert(s.has_value());\n\
    \        if (!s) {\n            // b not in column space: rank of [a | b] exceeds\
    \ rank of a\n            matrix<mint> ab(h, w + 1);\n            for (int i =\
    \ 0; i < h; i++) {\n                for (int j = 0; j < w; j++) ab[i][j] = a[i][j];\n\
    \                ab[i][w] = b[i];\n            }\n            assert(matrix_rank(ab)\
    \ == matrix_rank(a) + 1);\n            continue;\n        }\n        int r = matrix_rank(a);\n\
    \        assert(int(s->kernel.size()) == w - r);\n        assert(mul(a, s->x)\
    \ == b);\n        matrix<mint> k(int(s->kernel.size()), w);\n        for (int\
    \ i = 0; i < int(s->kernel.size()); i++) {\n            assert(mul(a, s->kernel[i])\
    \ == std::vector<mint>(h));\n            k[i] = s->kernel[i];\n        }\n   \
    \     assert(matrix_rank(k) == int(s->kernel.size()));\n    }\n    {\n       \
    \ // 0 x 0\n        matrix<mint> z(0, 0);\n        assert(determinant(z) == 1\
    \ && inverse(z).has_value() && matrix_rank(z) == 0);\n        auto s = solve_linear_system(z,\
    \ {});\n        assert(s && s->x.empty() && s->kernel.empty());\n        // 500\
    \ x 500 timing\n        matrix<mint> a = rnd(500, 500, 0);\n        determinant(a);\n\
    \        inverse(a);\n        matrix_rank(a);\n        solve_linear_system(a,\
    \ std::vector<mint>(500, 1));\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - math/matrix.hpp
  - algebra/concept.hpp
  - algebra/semiring_plus_times.hpp
  isVerificationFile: true
  path: test/unit/linear_algebra.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 18:39:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/linear_algebra.test.cpp
layout: document
redirect_from:
- /verify/test/unit/linear_algebra.test.cpp
- /verify/test/unit/linear_algebra.test.cpp.html
title: test/unit/linear_algebra.test.cpp
---
