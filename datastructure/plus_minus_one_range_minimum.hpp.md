---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructure/static_range_minimum.hpp
    title: datastructure/static_range_minimum.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/lowest_common_ancestor.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/lca.test.cpp
    title: test/library-checker/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/plus_minus_one_range_minimum.hpp\"\n#include\
    \ <cmath>\n#include <vector>\n\n#line 3 \"datastructure/static_range_minimum.hpp\"\
    \nstruct StaticRMQ {\npublic:\n    void init(const std::vector<std::pair<int,\
    \ int>>& _v) {\n        _n = int(_v.size()), d.resize(_n), ceil_log2.resize(_n\
    \ + 1);\n        ceil_log2[0] = 0;\n        ceil_log2[1] = 0;\n        for (int\
    \ i = 2; i <= _n; i++) ceil_log2[i] = ceil_log2[i >> 1] + 1;\n        for (int\
    \ i = 0; i < _n; i++) {\n            d[i].resize(ceil_log2[_n] + 1);\n       \
    \     d[i][0] = _v[i];\n        }\n        for (int b = 0; b < ceil_log2[_n];\
    \ b++) {\n            for (int i = 0; i < _n; i++) {\n                if (i +\
    \ (1 << (b + 1)) > _n) break;\n                d[i][b + 1] = std::min(d[i][b],\
    \ d[i + (1 << b)][b]);\n            }\n        }\n    }\n    std::pair<int, int>\
    \ prod(int l, int r) {\n        if (!(l < r)) return PINF;\n        int b = ceil_log2[r\
    \ - l];\n        return std::min(d[l][b], d[r - (1 << b)][b]);\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<std::vector<std::pair<int, int>>> d;\n    std::vector<int>\
    \ ceil_log2;\n    const std::pair<int, int> PINF = {1 << 30, 1 << 30};\n};\n#line\
    \ 6 \"datastructure/plus_minus_one_range_minimum.hpp\"\nstruct PlusMinusOneRMQ\
    \ {\npublic:\n    void init(const std::vector<int>& _v) {\n        _n = int(_v.size());\n\
    \        v = _v;\n        s = std::max(1, int(std::log2(_n) / 2));\n        B\
    \ = (_n + s - 1) / s;\n        std::vector<std::pair<int, int>> _spt(B);\n   \
    \     pattern.resize(B);\n        for (int i = 0; i < _n; i += s) {\n        \
    \    int min_j = i;\n            int bit = 0;\n            for (int j = i; j <\
    \ std::min(_n, i + s); j++) {\n                if (v[j] < v[min_j]) min_j = j;\n\
    \                if (j + 1 < std::min(_n, i + s) && v[j] < v[j + 1])\n       \
    \             bit |= 1 << (j - i);\n            }\n            _spt[i / s] = {v[min_j],\
    \ min_j};\n            pattern[i / s] = bit;\n        }\n        sparse_table.init(_spt);\n\
    \n        lookup_table.resize(1 << (s - 1));\n        for (int bit = 0; bit <\
    \ (1 << (s - 1)); bit++) {\n            lookup_table[bit].resize(s + 1);\n   \
    \         for (int l = 0; l <= s; l++) {\n                lookup_table[bit][l].resize(s\
    \ + 1, INF);\n                int min_ = 0;\n                int min_i = l;\n\
    \                int sum = 0;\n                for (int r = l + 1; r <= s; r++)\
    \ {\n                    lookup_table[bit][l][r] = min_i;\n                  \
    \  sum += bit >> (r - 1) & 1 ? 1 : -1;\n                    if (sum < min_) {\n\
    \                        min_ = sum;\n                        min_i = r;\n   \
    \                 }\n                }\n            }\n        }\n    }\n    int\
    \ prod(int l, int r) {\n        int m1 = (l + s - 1) / s;\n        int m2 = r\
    \ / s;\n        int l1 = s * m1;\n        int r1 = s * m2;\n        if (m2 < m1)\
    \ {\n            return lookup_table[pattern[m2]][l - r1][r - r1] + r1;\n    \
    \    }\n        int ret = INF;\n        if (m1 > 0) {\n            ret = argmin(\n\
    \                ret, lookup_table[pattern[m1 - 1]][s - (l1 - l)][s] + l1 - s);\n\
    \        }\n        ret = argmin(ret, sparse_table.prod(m1, m2).second);\n   \
    \     if (m2 < B) {\n            ret = argmin(ret, lookup_table[pattern[m2]][0][r\
    \ - r1] + r1);\n        }\n        return ret;\n    }\n\nprivate:\n    int _n;\n\
    \    int s, B;\n    StaticRMQ sparse_table;\n    std::vector<std::vector<std::vector<int>>>\
    \ lookup_table;\n    std::vector<int> pattern, v;\n    const int INF = 1 << 30;\n\
    \    int argmin(int i, int j) {\n        if (i >= INF || j >= INF || v[i] == v[j])\
    \ return std::min(i, j);\n        return v[i] < v[j] ? i : j;\n    }\n};\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\n#include \"static_range_minimum.hpp\"\
    \nstruct PlusMinusOneRMQ {\npublic:\n    void init(const std::vector<int>& _v)\
    \ {\n        _n = int(_v.size());\n        v = _v;\n        s = std::max(1, int(std::log2(_n)\
    \ / 2));\n        B = (_n + s - 1) / s;\n        std::vector<std::pair<int, int>>\
    \ _spt(B);\n        pattern.resize(B);\n        for (int i = 0; i < _n; i += s)\
    \ {\n            int min_j = i;\n            int bit = 0;\n            for (int\
    \ j = i; j < std::min(_n, i + s); j++) {\n                if (v[j] < v[min_j])\
    \ min_j = j;\n                if (j + 1 < std::min(_n, i + s) && v[j] < v[j +\
    \ 1])\n                    bit |= 1 << (j - i);\n            }\n            _spt[i\
    \ / s] = {v[min_j], min_j};\n            pattern[i / s] = bit;\n        }\n  \
    \      sparse_table.init(_spt);\n\n        lookup_table.resize(1 << (s - 1));\n\
    \        for (int bit = 0; bit < (1 << (s - 1)); bit++) {\n            lookup_table[bit].resize(s\
    \ + 1);\n            for (int l = 0; l <= s; l++) {\n                lookup_table[bit][l].resize(s\
    \ + 1, INF);\n                int min_ = 0;\n                int min_i = l;\n\
    \                int sum = 0;\n                for (int r = l + 1; r <= s; r++)\
    \ {\n                    lookup_table[bit][l][r] = min_i;\n                  \
    \  sum += bit >> (r - 1) & 1 ? 1 : -1;\n                    if (sum < min_) {\n\
    \                        min_ = sum;\n                        min_i = r;\n   \
    \                 }\n                }\n            }\n        }\n    }\n    int\
    \ prod(int l, int r) {\n        int m1 = (l + s - 1) / s;\n        int m2 = r\
    \ / s;\n        int l1 = s * m1;\n        int r1 = s * m2;\n        if (m2 < m1)\
    \ {\n            return lookup_table[pattern[m2]][l - r1][r - r1] + r1;\n    \
    \    }\n        int ret = INF;\n        if (m1 > 0) {\n            ret = argmin(\n\
    \                ret, lookup_table[pattern[m1 - 1]][s - (l1 - l)][s] + l1 - s);\n\
    \        }\n        ret = argmin(ret, sparse_table.prod(m1, m2).second);\n   \
    \     if (m2 < B) {\n            ret = argmin(ret, lookup_table[pattern[m2]][0][r\
    \ - r1] + r1);\n        }\n        return ret;\n    }\n\nprivate:\n    int _n;\n\
    \    int s, B;\n    StaticRMQ sparse_table;\n    std::vector<std::vector<std::vector<int>>>\
    \ lookup_table;\n    std::vector<int> pattern, v;\n    const int INF = 1 << 30;\n\
    \    int argmin(int i, int j) {\n        if (i >= INF || j >= INF || v[i] == v[j])\
    \ return std::min(i, j);\n        return v[i] < v[j] ? i : j;\n    }\n};\n"
  dependsOn:
  - datastructure/static_range_minimum.hpp
  isVerificationFile: false
  path: datastructure/plus_minus_one_range_minimum.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/lca.test.cpp
documentation_of: datastructure/plus_minus_one_range_minimum.hpp
layout: document
redirect_from:
- /library/datastructure/plus_minus_one_range_minimum.hpp
- /library/datastructure/plus_minus_one_range_minimum.hpp.html
title: datastructure/plus_minus_one_range_minimum.hpp
---
