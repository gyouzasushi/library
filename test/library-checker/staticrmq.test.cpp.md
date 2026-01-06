---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library-checker/staticrmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\n#line\
    \ 2 \"datastructure/sparse_table.hpp\"\n#include <cassert>\n#include <vector>\n\
    template <class S, S (*op)(S, S)>\nstruct SparseTable {\npublic:\n    SparseTable()\
    \ {\n    }\n    SparseTable(const std::vector<S>& v)\n        : _n(int(v.size())),\
    \ d(_n), ceil_log2(_n + 1) {\n        ceil_log2[0] = 0;\n        ceil_log2[1]\
    \ = 0;\n        for (int i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1]\
    \ + 1;\n        for (int i = 0; i < _n; i++) {\n            d[i].resize(ceil_log2[_n]\
    \ + 1);\n            d[i][0] = v[i];\n        }\n        for (int b = 0; b < ceil_log2[_n];\
    \ b++) {\n            for (int i = 0; i < _n; i++) {\n                if (i +\
    \ (1 << (b + 1)) > _n) break;\n                d[i][b + 1] = op(d[i][b], d[i +\
    \ (1 << b)][b]);\n            }\n        }\n    }\n    S prod(int l, int r) {\n\
    \        assert(r - l > 0);\n        int b = ceil_log2[r - l];\n        return\
    \ op(d[l][b], d[r - (1 << b)][b]);\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>>\
    \ d;\n    std::vector<int> ceil_log2;\n};\n#line 5 \"test/library-checker/staticrmq.test.cpp\"\
    \nusing S = int;\nS op(S a, S b) {\n    return std::min(a, b);\n}\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<S> a(n);\n    for\
    \ (int i = 0; i < n; i++) std::cin >> a[i];\n    SparseTable<S, op> s(a);\n  \
    \  while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << s.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    \n#include \"datastructure/sparse_table.hpp\"\nusing S = int;\nS op(S a, S b)\
    \ {\n    return std::min(a, b);\n}\nint main() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n    std::vector<S> a(n);\n    for (int i = 0; i < n; i++) std::cin\
    \ >> a[i];\n    SparseTable<S, op> s(a);\n    while (q--) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        std::cout << s.prod(l, r) << '\\n';\n  \
    \  }\n}"
  dependsOn:
  - datastructure/sparse_table.hpp
  isVerificationFile: true
  path: test/library-checker/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 19:05:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/staticrmq.test.cpp
- /verify/test/library-checker/staticrmq.test.cpp.html
title: test/library-checker/staticrmq.test.cpp
---
