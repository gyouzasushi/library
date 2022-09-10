---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/segment_tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\n#include <algorithm>\n\
    #include <limits>\n\n#line 2 \"datastructure/segment_tree.hpp\"\n#include <cassert>\n\
    #include <vector>\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct SegmentTree\
    \ {\npublic:\n    SegmentTree() : SegmentTree(0) {\n    }\n    SegmentTree(int\
    \ n) : SegmentTree(std::vector<S>(n, e())) {\n    }\n    SegmentTree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n        size = 1 <<\
    \ log;\n        d = std::vector<S>(2 * size, e());\n        for (int i = 0; i\
    \ < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--)\
    \ {\n            update(i);\n        }\n    }\n\n    void set(int p, S x) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n  \
    \      for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n    }\n\
    \n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n \
    \       S sml = e(), smr = e();\n        l += size;\n        r += size;\n\n  \
    \      while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n      \
    \      if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod() {\n\
    \        return d[1];\n    }\n\n    template <bool (*f)(S)>\n    int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F>\n    int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](S x) { return f(x);\
    \ });\n    }\n    template <class F>\n    int min_left(int r, F f) {\n       \
    \ assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\nprivate:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n    int ceil_pow2(int n) {\n \
    \       int x = 0;\n        while ((1U << x) < (unsigned int)(n)) x++;\n     \
    \   return x;\n    }\n    void update(int k) {\n        d[k] = op(d[2 * k], d[2\
    \ * k + 1]);\n    }\n};\n#line 7 \"test/aoj/DSL_2_A.test.cpp\"\nnamespace PointUpdateRangeMin\
    \ {\nusing S = int;\nS op(S a, S b) {\n    return std::min(a, b);\n}\nS e() {\n\
    \    return std::numeric_limits<S>::max();\n}\nusing segt = SegmentTree<S, op,\
    \ e>;\n}  // namespace PointUpdateRangeMin\n#include <iostream>\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n\n    auto segt = PointUpdateRangeMin::segt(n);\n\
    \    while (q--) {\n        int com;\n        std::cin >> com;\n        if (com\
    \ == 0) {\n            int i, x;\n            std::cin >> i >> x;\n          \
    \  segt.set(i, x);\n        }\n        if (com == 1) {\n            int s, t;\n\
    \            std::cin >> s >> t;\n            std::cout << segt.prod(s, ++t) <<\
    \ '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <algorithm>\n#include <limits>\n\n#include \"datastructure/segment_tree.hpp\"\
    \nnamespace PointUpdateRangeMin {\nusing S = int;\nS op(S a, S b) {\n    return\
    \ std::min(a, b);\n}\nS e() {\n    return std::numeric_limits<S>::max();\n}\n\
    using segt = SegmentTree<S, op, e>;\n}  // namespace PointUpdateRangeMin\n#include\
    \ <iostream>\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\n    auto\
    \ segt = PointUpdateRangeMin::segt(n);\n    while (q--) {\n        int com;\n\
    \        std::cin >> com;\n        if (com == 0) {\n            int i, x;\n  \
    \          std::cin >> i >> x;\n            segt.set(i, x);\n        }\n     \
    \   if (com == 1) {\n            int s, t;\n            std::cin >> s >> t;\n\
    \            std::cout << segt.prod(s, ++t) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - datastructure/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-09-11 04:51:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
