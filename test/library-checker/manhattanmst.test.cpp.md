---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/library-checker/manhattanmst.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include <atcoder/dsu>\n\
    #include <iostream>\n\n#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#line 5 \"graph/manhattan_mst.hpp\"\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <vector>\n\n#line 1 \"atcoder/segtree.hpp\"\
    \n\n\n\n#line 7 \"atcoder/segtree.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U\
    \ << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n\
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int\
    \ bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 << x)))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n\
    }  // namespace atcoder\n\n\n#line 9 \"atcoder/segtree.hpp\"\n\nnamespace atcoder\
    \ {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n\
    \    segtree() : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = internal::ceil_pow2(_n);\n        size = 1 << log;\n      \
    \  d = std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(),\
    \ smr = e();\n        l += size;\n        r += size;\n\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1];\
    \ }\n\n    template <bool (*f)(S)> int max_right(int l) const {\n        return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        S sm = e();\n  \
    \      do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 11 \"graph/manhattan_mst.hpp\"\
    \nnamespace manhattan_mst_internal {\ntemplate <typename T>\nstruct S {\n    T\
    \ val;\n    int id;\n};\ntemplate <typename T>\nS<T> op(S<T> a, S<T> b) {\n  \
    \  return a.val < b.val ? a : b;\n}\ntemplate <typename T>\nS<T> e() {\n    return\
    \ {std::numeric_limits<T>::max(), -1};\n}\n}  // namespace manhattan_mst_internal\n\
    template <typename T>\nstd::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T>\
    \ x,\n                                                   std::vector<T> y) {\n\
    \    int n = x.size();\n    assert(int(x.size()) == n && int(y.size()) == n);\n\
    \    std::vector<int> id(n);\n    std::iota(id.begin(), id.end(), 0);\n    std::vector<int>\
    \ y_id(n);\n    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0;\
    \ a < 2; a++) {\n        for (int b = 0; b < 2; b++) {\n            for (int c\
    \ = 0; c < 2; c++) {\n                sort(id.begin(), id.end(), [&](int i, int\
    \ j) {\n                    if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n\
    \                        return i < j;\n                    if (y[i] - x[i] ==\
    \ y[j] - x[j]) return y[i] > y[j];\n                    return y[i] - x[i] < y[j]\
    \ - x[j];\n                });\n                std::vector<T> _y = y;\n     \
    \           std::sort(_y.begin(), _y.end());\n                for (int i = 0;\
    \ i < n; i++) {\n                    y_id[i] = std::lower_bound(_y.begin(), _y.end(),\
    \ y[i]) -\n                              _y.begin();\n                }\n    \
    \            atcoder::segtree<manhattan_mst_internal::S<T>,\n                \
    \                 manhattan_mst_internal::op<T>,\n                           \
    \      manhattan_mst_internal::e<T>>\n                    segt(n);\n         \
    \       for (int i : id) {\n                    manhattan_mst_internal::S<T> p\
    \ = segt.prod(y_id[i], n);\n                    if (p.id != -1) {\n          \
    \              ret.emplace_back(i, p.id, p.val - (x[i] + y[i]));\n           \
    \         }\n                    segt.set(y_id[i], {x[i] + y[i], i});\n      \
    \          }\n                std::swap(x, y);\n            }\n            for\
    \ (T &x : x) x = -x;\n        }\n        for (T &y : y) y = -y;\n    }\n    sort(ret.begin(),\
    \ ret.end(),\n         [](auto a, auto b) { return std::get<2>(a) < std::get<2>(b);\
    \ });\n    return ret;\n}\n#line 7 \"test/library-checker/manhattanmst.test.cpp\"\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> x(n),\
    \ y(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n\
    \    }\n\n    atcoder::dsu uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (!uf.same(u,\
    \ v)) {\n            uf.merge(u, v);\n            sum += w;\n            ans.emplace_back(u,\
    \ v);\n        }\n    }\n    std::cout << sum << '\\n';\n    for (auto [u, v]\
    \ : ans) {\n        std::cout << u << ' ' << v << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ <atcoder/dsu>\n#include <iostream>\n\n#include \"graph/manhattan_mst.hpp\"\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> x(n),\
    \ y(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n\
    \    }\n\n    atcoder::dsu uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (!uf.same(u,\
    \ v)) {\n            uf.merge(u, v);\n            sum += w;\n            ans.emplace_back(u,\
    \ v);\n        }\n    }\n    std::cout << sum << '\\n';\n    for (auto [u, v]\
    \ : ans) {\n        std::cout << u << ' ' << v << '\\n';\n    }\n}"
  dependsOn:
  - graph/manhattan_mst.hpp
  isVerificationFile: true
  path: test/library-checker/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2024-07-05 09:06:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/manhattanmst.test.cpp
- /verify/test/library-checker/manhattanmst.test.cpp.html
title: test/library-checker/manhattanmst.test.cpp
---
