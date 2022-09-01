---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/sparse_table.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S)>\nstruct SparseTable {\npublic:\n    SparseTable() {\n    }\n    SparseTable(const\
    \ std::vector<S>& v)\n        : _n(int(v.size())), d(_n), ceil_log2(_n + 1) {\n\
    \        ceil_log2[0] = 0;\n        ceil_log2[1] = 0;\n        for (int i = 2;\
    \ i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] + 1;\n        for (int i = 0;\
    \ i < _n; i++) {\n            d[i].resize(ceil_log2[_n] + 1);\n            d[i][0]\
    \ = v[i];\n        }\n        for (int b = 0; b < ceil_log2[_n]; b++) {\n    \
    \        for (int i = 0; i < _n; i++) {\n                if (i + (1 << (b + 1))\
    \ > _n) break;\n                d[i][b + 1] = op(d[i][b], d[i + (1 << b)][b]);\n\
    \            }\n        }\n    }\n    S prod(int l, int r) {\n        assert(r\
    \ - l > 0);\n        int b = ceil_log2[r - l];\n        return op(d[l][b], d[r\
    \ - (1 << b)][b]);\n    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>>\
    \ d;\n    std::vector<int> ceil_log2;\n};\n"
  code: "#pragma once\ntemplate <class S, S (*op)(S, S)>\nstruct SparseTable {\npublic:\n\
    \    SparseTable() {\n    }\n    SparseTable(const std::vector<S>& v)\n      \
    \  : _n(int(v.size())), d(_n), ceil_log2(_n + 1) {\n        ceil_log2[0] = 0;\n\
    \        ceil_log2[1] = 0;\n        for (int i = 2; i <= _n; i++) ceil_log2[i]\
    \ = ceil_log2[i >> 1] + 1;\n        for (int i = 0; i < _n; i++) {\n         \
    \   d[i].resize(ceil_log2[_n] + 1);\n            d[i][0] = v[i];\n        }\n\
    \        for (int b = 0; b < ceil_log2[_n]; b++) {\n            for (int i = 0;\
    \ i < _n; i++) {\n                if (i + (1 << (b + 1)) > _n) break;\n      \
    \          d[i][b + 1] = op(d[i][b], d[i + (1 << b)][b]);\n            }\n   \
    \     }\n    }\n    S prod(int l, int r) {\n        assert(r - l > 0);\n     \
    \   int b = ceil_log2[r - l];\n        return op(d[l][b], d[r - (1 << b)][b]);\n\
    \    }\n\nprivate:\n    int _n;\n    std::vector<std::vector<S>> d;\n    std::vector<int>\
    \ ceil_log2;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/sparse_table.hpp
layout: document
redirect_from:
- /library/datastructure/sparse_table.hpp
- /library/datastructure/sparse_table.hpp.html
title: datastructure/sparse_table.hpp
---
