---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558.test.cpp
    title: test/aoj/0558.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1160.test.cpp
    title: test/aoj/1160.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/grid.hpp\"\n#include <vector>\nstruct grid {\npublic:\n\
    \    int y, x;\n    grid() {\n    }\n    grid(int y, int x) : y(y), x(x) {\n \
    \   }\n    static void set_bound(int height, int width) {\n        _min_y = 0;\n\
    \        _min_x = 0;\n        _max_y = height - 1;\n        _max_x = width - 1;\n\
    \    }\n    static void set_bound(int min_y, int min_x, int max_y, int max_x)\
    \ {\n        _min_y = min_y;\n        _min_x = min_x;\n        _max_y = max_y;\n\
    \        _max_x = max_x;\n    }\n    static std::vector<grid> grids() {\n    \
    \    std::vector<grid> ret;\n        for (int y = _min_y; y <= _max_y; y++) {\n\
    \            for (int x = _min_x; x <= _max_x; x++) {\n                ret.emplace_back(y,\
    \ x);\n            }\n        }\n        return ret;\n    }\n    static grid from(int\
    \ i) {\n        return grid(i / (_max_x - _min_x + 1) + _min_y,\n            \
    \        i % (_max_x - _min_x + 1) + _min_x);\n    }\n    bool is_valid() {\n\
    \        return _min_y <= y && y <= _max_y && _min_x <= x && x <= _max_x;\n  \
    \  }\n    std::vector<grid> neighbors() {\n        std::vector<grid> ret;\n  \
    \      for (auto [dy, dx] : grid::delta) {\n            if (grid(y + dy, x + dx).is_valid())\
    \ {\n                ret.emplace_back(y + dy, x + dx);\n            }\n      \
    \  }\n        return ret;\n    }\n    std::vector<grid> neighbors_8() {\n    \
    \    std::vector<grid> ret;\n        for (auto [dy, dx] : grid::delta_8) {\n \
    \           if (grid(y + dy, x + dx).is_valid()) {\n                ret.emplace_back(y\
    \ + dy, x + dx);\n            }\n        }\n        return ret;\n    }\n    operator\
    \ int() const {\n        return (y - _min_y) * (_max_x - _min_x + 1) + (x - _min_x);\n\
    \    }\n\nprivate:\n    static inline int _min_y, _min_x, _max_y, _max_x;\n  \
    \  static inline const std::vector<std::pair<int, int>> delta = {\n        {0,\
    \ 1}, {1, 0}, {0, -1}, {-1, 0}};\n    static inline const std::vector<std::pair<int,\
    \ int>> delta_8 = {\n        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},\
    \ {-1, 0}, {-1, 1}};\n};\n"
  code: "#pragma once\n#include <vector>\nstruct grid {\npublic:\n    int y, x;\n\
    \    grid() {\n    }\n    grid(int y, int x) : y(y), x(x) {\n    }\n    static\
    \ void set_bound(int height, int width) {\n        _min_y = 0;\n        _min_x\
    \ = 0;\n        _max_y = height - 1;\n        _max_x = width - 1;\n    }\n   \
    \ static void set_bound(int min_y, int min_x, int max_y, int max_x) {\n      \
    \  _min_y = min_y;\n        _min_x = min_x;\n        _max_y = max_y;\n       \
    \ _max_x = max_x;\n    }\n    static std::vector<grid> grids() {\n        std::vector<grid>\
    \ ret;\n        for (int y = _min_y; y <= _max_y; y++) {\n            for (int\
    \ x = _min_x; x <= _max_x; x++) {\n                ret.emplace_back(y, x);\n \
    \           }\n        }\n        return ret;\n    }\n    static grid from(int\
    \ i) {\n        return grid(i / (_max_x - _min_x + 1) + _min_y,\n            \
    \        i % (_max_x - _min_x + 1) + _min_x);\n    }\n    bool is_valid() {\n\
    \        return _min_y <= y && y <= _max_y && _min_x <= x && x <= _max_x;\n  \
    \  }\n    std::vector<grid> neighbors() {\n        std::vector<grid> ret;\n  \
    \      for (auto [dy, dx] : grid::delta) {\n            if (grid(y + dy, x + dx).is_valid())\
    \ {\n                ret.emplace_back(y + dy, x + dx);\n            }\n      \
    \  }\n        return ret;\n    }\n    std::vector<grid> neighbors_8() {\n    \
    \    std::vector<grid> ret;\n        for (auto [dy, dx] : grid::delta_8) {\n \
    \           if (grid(y + dy, x + dx).is_valid()) {\n                ret.emplace_back(y\
    \ + dy, x + dx);\n            }\n        }\n        return ret;\n    }\n    operator\
    \ int() const {\n        return (y - _min_y) * (_max_x - _min_x + 1) + (x - _min_x);\n\
    \    }\n\nprivate:\n    static inline int _min_y, _min_x, _max_y, _max_x;\n  \
    \  static inline const std::vector<std::pair<int, int>> delta = {\n        {0,\
    \ 1}, {1, 0}, {0, -1}, {-1, 0}};\n    static inline const std::vector<std::pair<int,\
    \ int>> delta_8 = {\n        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},\
    \ {-1, 0}, {-1, 1}};\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/grid.hpp
  requiredBy: []
  timestamp: '2023-01-18 16:13:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1160.test.cpp
  - test/aoj/0558.test.cpp
documentation_of: graph/grid.hpp
layout: document
title: "\u30B0\u30EA\u30C3\u30C9"
---

### 概要
- グリッドを扱うのに便利な構造体。
  
### 使い方
- `grid::set_bound(height, width)`: `[0, height)` $\times$ `[0, width)` で初期化する。
- `grid::set_bound(min_y, min_x, max_y, max_x)`: `[min_y, max_y]` $\times$ `[min_x, max_x]` で初期化する。 
- `grid::grids()`: すべてのグリッドを辞書順で列挙する。
- `grid::from(i)`: 辞書順で `i` 番目のグリッドを求める。
- `operator int()`: グリッドが辞書順で何番目かを求める。
- `neighbors()`: グリッドの4近傍であって、範囲内のものを列挙する。
- `neighbors_8()`: グリッドの8近傍であって、範囲内のものを列挙する。