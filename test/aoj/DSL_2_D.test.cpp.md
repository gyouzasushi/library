---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/dual_segment_tree.hpp
    title: Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\
    \n\n#include <iostream>\n\n#line 1 \"datastructure/dual_segment_tree.hpp\"\n#include\
    \ <vector>\ntemplate <class F, F (*composition)(F, F), F (*id)()>\nstruct DualSegmentTree\
    \ {\npublic:\n    DualSegmentTree() {\n    }\n    DualSegmentTree(int n, bool\
    \ is_commutative = false)\n        : is_commutative(is_commutative) {\n      \
    \  size = 1;\n        height = 0;\n        while (size < n) size <<= 1, height++;\n\
    \        lz.assign(2 * size, id());\n    }\n    void apply(int l, int r, const\
    \ F &f) {\n        l += size;\n        r += size - 1;\n        if (!is_commutative)\
    \ thrust(l);\n        if (!is_commutative) thrust(r);\n        r++;\n        while\
    \ (l < r) {\n            if (l & 1) lz[l] = composition(f, lz[l]), ++l;\n    \
    \        if (r & 1) --r, lz[r] = composition(f, lz[r]);\n            l >>= 1,\
    \ r >>= 1;\n        }\n    }\n    F get(int p) {\n        if (is_commutative)\
    \ {\n            F ret = id();\n            p += size;\n            while (p >\
    \ 0) {\n                ret = composition(lz[p], ret);\n                p >>=\
    \ 1;\n            }\n            return ret;\n        } else {\n            thrust(p\
    \ += size);\n            return lz[p];\n        }\n    }\n\nprivate:\n    int\
    \ size, height;\n    std::vector<F> lz;\n    bool is_commutative;\n    inline\
    \ void propagate(int k) {\n        lz[2 * k + 0] = composition(lz[k], lz[2 * k\
    \ + 0]);\n        lz[2 * k + 1] = composition(lz[k], lz[2 * k + 1]);\n       \
    \ lz[k] = id();\n    }\n    inline void thrust(int k) {\n        for (int i =\
    \ height; i > 0; i--) propagate(k >> i);\n    }\n};\n#line 6 \"test/aoj/DSL_2_D.test.cpp\"\
    \n\nusing F = int;\nF composition(F a, F b) {\n    return a;\n}\nF id() {\n  \
    \  return -1;\n}\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    DualSegmentTree<F,\
    \ composition, id> segt(n, false);\n    segt.apply(0, n, 2147483647);\n    while\
    \ (q--) {\n        int type;\n        std::cin >> type;\n        if (type == 0)\
    \ {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n        \
    \    segt.apply(l, ++r, x);\n        }\n        if (type == 1) {\n           \
    \ int i;\n            std::cin >> i;\n            std::cout << segt.get(i) <<\
    \ '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\n\n\
    #include <iostream>\n\n#include \"datastructure/dual_segment_tree.hpp\"\n\nusing\
    \ F = int;\nF composition(F a, F b) {\n    return a;\n}\nF id() {\n    return\
    \ -1;\n}\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    DualSegmentTree<F,\
    \ composition, id> segt(n, false);\n    segt.apply(0, n, 2147483647);\n    while\
    \ (q--) {\n        int type;\n        std::cin >> type;\n        if (type == 0)\
    \ {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n        \
    \    segt.apply(l, ++r, x);\n        }\n        if (type == 1) {\n           \
    \ int i;\n            std::cin >> i;\n            std::cout << segt.get(i) <<\
    \ '\\n';\n        }\n    }\n}"
  dependsOn:
  - datastructure/dual_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 17:58:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.test.cpp
- /verify/test/aoj/DSL_2_D.test.cpp.html
title: test/aoj/DSL_2_D.test.cpp
---
