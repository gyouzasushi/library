---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL_2_H.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\n#include <algorithm>\n\
    #include <limits>\n\n#line 2 \"datastructure/lazy_segment_tree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\ntemplate <class S, S (*op)(S, S), S (*e)(), class\
    \ F, S (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nstruct\
    \ LazySegmentTree {\npublic:\n    LazySegmentTree() : LazySegmentTree(0) {\n \
    \   }\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<S>(n, e())) {\n\
    \    }\n    LazySegmentTree(const std::vector<S>& v) : _n(int(v.size())) {\n \
    \       log = ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr\
    \ = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ {\n        return d[1];\n    }\n\n    void apply(int p, F f) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n    \
    \    assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n   \
    \     l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int\
    \ l2 = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ f);\n                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G>\n    int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](S x) { return g(x);\
    \ });\n    }\n    template <class G>\n    int min_left(int r, G g) {\n       \
    \ assert(0 <= r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1)\
    \ >> i);\n        S sm = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n         \
    \       while (r < size) {\n                    push(r);\n                   \
    \ r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n             \
    \           sm = op(d[r], sm);\n                        r--;\n               \
    \     }\n                }\n                return r + 1 - size;\n           \
    \ }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n      \
    \  return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S> d;\n\
    \    std::vector<F> lz;\n    int ceil_pow2(int n) {\n        int x = 0;\n    \
    \    while ((1U << x) < (unsigned int)(n)) x++;\n        return x;\n    }\n  \
    \  void update(int k) {\n        d[k] = op(d[2 * k], d[2 * k + 1]);\n    }\n \
    \   void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if\
    \ (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n \
    \       all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n     \
    \   lz[k] = id();\n    }\n};\n#line 7 \"test/aoj/DSL_2_H.test.cpp\"\nnamespace\
    \ RangeAddRangeMin {\nusing T = long long;\nusing S = T;\nS op(S a, S b) {\n \
    \   return std::min(a, b);\n}\nS e() {\n    return std::numeric_limits<S>::max();\n\
    }\nusing F = T;\nS mapping(F f, S x) {\n    return x + f;\n}\nF composition(F\
    \ f, F g) {\n    return f + g;\n}\nF id() {\n    return 0;\n}\nusing segt = LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id>;\n}  // namespace RangeAddRangeMin\n#include\
    \ <iostream>\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    auto segt\
    \ = RangeAddRangeMin::segt(std::vector(n, 0ll));\n    while (q--) {\n        int\
    \ com;\n        std::cin >> com;\n        if (com == 0) {\n            int s,\
    \ t, x;\n            std::cin >> s >> t >> x;\n            t++;\n            segt.apply(s,\
    \ t, x);\n        }\n        if (com == 1) {\n            int s, t;\n        \
    \    std::cin >> s >> t;\n            t++;\n            std::cout << segt.prod(s,\
    \ t) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n#include <algorithm>\n#include <limits>\n\n#include \"datastructure/lazy_segment_tree.hpp\"\
    \nnamespace RangeAddRangeMin {\nusing T = long long;\nusing S = T;\nS op(S a,\
    \ S b) {\n    return std::min(a, b);\n}\nS e() {\n    return std::numeric_limits<S>::max();\n\
    }\nusing F = T;\nS mapping(F f, S x) {\n    return x + f;\n}\nF composition(F\
    \ f, F g) {\n    return f + g;\n}\nF id() {\n    return 0;\n}\nusing segt = LazySegmentTree<S,\
    \ op, e, F, mapping, composition, id>;\n}  // namespace RangeAddRangeMin\n#include\
    \ <iostream>\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    auto segt\
    \ = RangeAddRangeMin::segt(std::vector(n, 0ll));\n    while (q--) {\n        int\
    \ com;\n        std::cin >> com;\n        if (com == 0) {\n            int s,\
    \ t, x;\n            std::cin >> s >> t >> x;\n            t++;\n            segt.apply(s,\
    \ t, x);\n        }\n        if (com == 1) {\n            int s, t;\n        \
    \    std::cin >> s >> t;\n            t++;\n            std::cout << segt.prod(s,\
    \ t) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - datastructure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_H.test.cpp
  requiredBy: []
  timestamp: '2022-09-11 04:51:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H.test.cpp
- /verify/test/aoj/DSL_2_H.test.cpp.html
title: test/aoj/DSL_2_H.test.cpp
---
