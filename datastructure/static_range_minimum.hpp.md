---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructure/plus_minus_one_range_minimum.hpp
    title: datastructure/plus_minus_one_range_minimum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/static_range_minimum.hpp\"\n#include <vector>\n\
    struct StaticRMQ {\npublic:\n    void init(const std::vector<std::pair<int, int>>&\
    \ _v) {\n        _n = int(_v.size()), d.resize(_n), ceil_log2.resize(_n + 1);\n\
    \        ceil_log2[0] = 0;\n        ceil_log2[1] = 0;\n        for (int i = 2;\
    \ i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] + 1;\n        for (int i = 0;\
    \ i < _n; i++) {\n            d[i].resize(ceil_log2[_n] + 1);\n            d[i][0]\
    \ = _v[i];\n        }\n        for (int b = 0; b < ceil_log2[_n]; b++) {\n   \
    \         for (int i = 0; i < _n; i++) {\n                if (i + (1 << (b + 1))\
    \ > _n) break;\n                d[i][b + 1] = std::min(d[i][b], d[i + (1 << b)][b]);\n\
    \            }\n        }\n    }\n    std::pair<int, int> prod(int l, int r) {\n\
    \        if (!(l < r)) return PINF;\n        int b = ceil_log2[r - l];\n     \
    \   return std::min(d[l][b], d[r - (1 << b)][b]);\n    }\n\nprivate:\n    int\
    \ _n;\n    std::vector<std::vector<std::pair<int, int>>> d;\n    std::vector<int>\
    \ ceil_log2;\n    const std::pair<int, int> PINF = {1 << 30, 1 << 30};\n};\n"
  code: "#pragma once\n#include <vector>\nstruct StaticRMQ {\npublic:\n    void init(const\
    \ std::vector<std::pair<int, int>>& _v) {\n        _n = int(_v.size()), d.resize(_n),\
    \ ceil_log2.resize(_n + 1);\n        ceil_log2[0] = 0;\n        ceil_log2[1] =\
    \ 0;\n        for (int i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] +\
    \ 1;\n        for (int i = 0; i < _n; i++) {\n            d[i].resize(ceil_log2[_n]\
    \ + 1);\n            d[i][0] = _v[i];\n        }\n        for (int b = 0; b <\
    \ ceil_log2[_n]; b++) {\n            for (int i = 0; i < _n; i++) {\n        \
    \        if (i + (1 << (b + 1)) > _n) break;\n                d[i][b + 1] = std::min(d[i][b],\
    \ d[i + (1 << b)][b]);\n            }\n        }\n    }\n    std::pair<int, int>\
    \ prod(int l, int r) {\n        if (!(l < r)) return PINF;\n        int b = ceil_log2[r\
    \ - l];\n        return std::min(d[l][b], d[r - (1 << b)][b]);\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<std::vector<std::pair<int, int>>> d;\n    std::vector<int>\
    \ ceil_log2;\n    const std::pair<int, int> PINF = {1 << 30, 1 << 30};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/static_range_minimum.hpp
  requiredBy:
  - datastructure/plus_minus_one_range_minimum.hpp
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/static_range_minimum.hpp
layout: document
redirect_from:
- /library/datastructure/static_range_minimum.hpp
- /library/datastructure/static_range_minimum.hpp.html
title: datastructure/static_range_minimum.hpp
---
