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
  bundledCode: "#line 2 \"graph/cell.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nstruct cell {\npublic:\n    // (dy, dx)\n\
    \    static constexpr std::array<std::pair<int, int>, 4> delta = {{{0, 1}, {1,\
    \ 0}, {0, -1}, {-1, 0}}};\n    static constexpr std::array<std::pair<int, int>,\
    \ 8> delta_8 = {\n        {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},\
    \ {-1, 0}, {-1, 1}}};\n\n    int y, x;\n    cell() : y(0), x(0) {\n    }\n   \
    \ cell(int y, int x) : y(y), x(x) {\n    }\n    // \u8F9E\u66F8\u9806\u3067 i\
    \ \u756A\u76EE\u306E\u30DE\u30B9\n    explicit cell(int i) {\n        assert(_set);\n\
    \        assert(0 <= i && i < size());\n        y = i / width() + _min_y;\n  \
    \      x = i % width() + _min_x;\n    }\n    static void set_bound(int height,\
    \ int width) {\n        set_bound(0, 0, height - 1, width - 1);\n    }\n    static\
    \ void set_bound(int min_y, int min_x, int max_y, int max_x) {\n        assert(min_y\
    \ <= max_y && min_x <= max_x);\n        _min_y = min_y;\n        _min_x = min_x;\n\
    \        _max_y = max_y;\n        _max_x = max_x;\n        _set = true;\n    }\n\
    \    static int height() {\n        assert(_set);\n        return _max_y - _min_y\
    \ + 1;\n    }\n    static int width() {\n        assert(_set);\n        return\
    \ _max_x - _min_x + 1;\n    }\n    static int size() {\n        return height()\
    \ * width();\n    }\n    static std::vector<cell> cells() {\n        assert(_set);\n\
    \        std::vector<cell> ret;\n        ret.reserve(size());\n        for (int\
    \ y = _min_y; y <= _max_y; y++) {\n            for (int x = _min_x; x <= _max_x;\
    \ x++) {\n                ret.emplace_back(y, x);\n            }\n        }\n\
    \        return ret;\n    }\n    bool is_valid() const {\n        return _min_y\
    \ <= y && y <= _max_y && _min_x <= x && x <= _max_x;\n    }\n    operator int()\
    \ const {\n        return (y - _min_y) * width() + (x - _min_x);\n    }\n    cell\
    \ operator+(std::pair<int, int> d) const {\n        return cell(y + d.first, x\
    \ + d.second);\n    }\n    cell operator-(std::pair<int, int> d) const {\n   \
    \     return cell(y - d.first, x - d.second);\n    }\n    bool operator==(const\
    \ cell& o) const {\n        return y == o.y && x == o.x;\n    }\n    bool operator!=(const\
    \ cell& o) const {\n        return !(*this == o);\n    }\n\n    template <int\
    \ K>\n    struct neighbor_view {\n        std::array<cell, K> a;\n        int\
    \ n;\n        const cell* begin() const {\n            return a.data();\n    \
    \    }\n        const cell* end() const {\n            return a.data() + n;\n\
    \        }\n        int size() const {\n            return n;\n        }\n   \
    \ };\n    neighbor_view<4> neighbors() const {\n        return collect<4>(delta);\n\
    \    }\n    neighbor_view<8> neighbors_8() const {\n        return collect<8>(delta_8);\n\
    \    }\n\nprivate:\n    static inline bool _set = false;\n    static inline int\
    \ _min_y, _min_x, _max_y, _max_x;\n    template <int K>\n    neighbor_view<K>\
    \ collect(const std::array<std::pair<int, int>, K>& ds) const {\n        neighbor_view<K>\
    \ ret;\n        ret.n = 0;\n        for (auto d : ds) {\n            cell v =\
    \ *this + d;\n            if (v.is_valid()) ret.a[ret.n++] = v;\n        }\n \
    \       return ret;\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nstruct cell {\npublic:\n    // (dy, dx)\n    static constexpr\
    \ std::array<std::pair<int, int>, 4> delta = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};\n\
    \    static constexpr std::array<std::pair<int, int>, 8> delta_8 = {\n       \
    \ {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}};\n\n\
    \    int y, x;\n    cell() : y(0), x(0) {\n    }\n    cell(int y, int x) : y(y),\
    \ x(x) {\n    }\n    // \u8F9E\u66F8\u9806\u3067 i \u756A\u76EE\u306E\u30DE\u30B9\
    \n    explicit cell(int i) {\n        assert(_set);\n        assert(0 <= i &&\
    \ i < size());\n        y = i / width() + _min_y;\n        x = i % width() + _min_x;\n\
    \    }\n    static void set_bound(int height, int width) {\n        set_bound(0,\
    \ 0, height - 1, width - 1);\n    }\n    static void set_bound(int min_y, int\
    \ min_x, int max_y, int max_x) {\n        assert(min_y <= max_y && min_x <= max_x);\n\
    \        _min_y = min_y;\n        _min_x = min_x;\n        _max_y = max_y;\n \
    \       _max_x = max_x;\n        _set = true;\n    }\n    static int height()\
    \ {\n        assert(_set);\n        return _max_y - _min_y + 1;\n    }\n    static\
    \ int width() {\n        assert(_set);\n        return _max_x - _min_x + 1;\n\
    \    }\n    static int size() {\n        return height() * width();\n    }\n \
    \   static std::vector<cell> cells() {\n        assert(_set);\n        std::vector<cell>\
    \ ret;\n        ret.reserve(size());\n        for (int y = _min_y; y <= _max_y;\
    \ y++) {\n            for (int x = _min_x; x <= _max_x; x++) {\n             \
    \   ret.emplace_back(y, x);\n            }\n        }\n        return ret;\n \
    \   }\n    bool is_valid() const {\n        return _min_y <= y && y <= _max_y\
    \ && _min_x <= x && x <= _max_x;\n    }\n    operator int() const {\n        return\
    \ (y - _min_y) * width() + (x - _min_x);\n    }\n    cell operator+(std::pair<int,\
    \ int> d) const {\n        return cell(y + d.first, x + d.second);\n    }\n  \
    \  cell operator-(std::pair<int, int> d) const {\n        return cell(y - d.first,\
    \ x - d.second);\n    }\n    bool operator==(const cell& o) const {\n        return\
    \ y == o.y && x == o.x;\n    }\n    bool operator!=(const cell& o) const {\n \
    \       return !(*this == o);\n    }\n\n    template <int K>\n    struct neighbor_view\
    \ {\n        std::array<cell, K> a;\n        int n;\n        const cell* begin()\
    \ const {\n            return a.data();\n        }\n        const cell* end()\
    \ const {\n            return a.data() + n;\n        }\n        int size() const\
    \ {\n            return n;\n        }\n    };\n    neighbor_view<4> neighbors()\
    \ const {\n        return collect<4>(delta);\n    }\n    neighbor_view<8> neighbors_8()\
    \ const {\n        return collect<8>(delta_8);\n    }\n\nprivate:\n    static\
    \ inline bool _set = false;\n    static inline int _min_y, _min_x, _max_y, _max_x;\n\
    \    template <int K>\n    neighbor_view<K> collect(const std::array<std::pair<int,\
    \ int>, K>& ds) const {\n        neighbor_view<K> ret;\n        ret.n = 0;\n \
    \       for (auto d : ds) {\n            cell v = *this + d;\n            if (v.is_valid())\
    \ ret.a[ret.n++] = v;\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cell.hpp
  requiredBy: []
  timestamp: '2026-10-19 19:51:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1160.test.cpp
  - test/aoj/0558.test.cpp
documentation_of: graph/cell.hpp
layout: document
title: "\u30B0\u30EA\u30C3\u30C9\u306E\u30DE\u30B9"
---

### 概要
- グリッドのマスを表す構造体。

### 使い方
- `cell::set_bound(height, width)`: 範囲を `[0, height)` $\times$ `[0, width)` にする。
- `cell::set_bound(min_y, min_x, max_y, max_x)`: 範囲を `[min_y, max_y]` $\times$ `[min_x, max_x]` にする。
- `cell::height()`, `cell::width()`, `cell::size()`: 範囲の高さ・幅・マス数。
- `cell(y, x)`: 座標からマスを作る。
- `cell(i)`: 辞書順で `i` 番目のマスを作る。
- `operator int()`: マスが辞書順で何番目かを返す。`d[v]` のように配列の添字にそのまま使える。
- `cell::cells()`: 全マスを辞書順で列挙する。
- `is_valid()`: 範囲内か判定する。
- `neighbors()`, `neighbors_8()`: 範囲内の 4 近傍・8 近傍。range-for で回す。
- `cell::delta`, `cell::delta_8`: 近傍への変位 `(dy, dx)` の `std::pair`。
- `u + d`, `u - d`: `(dy, dx)` だけ移動したマス。範囲外のマスも作れるので、必要なら `is_valid()` で確かめる。
- `==`, `!=`

```cpp
cell::set_bound(h, w);
std::vector<int> d(cell::size(), -1);
for (cell v : u.neighbors()) { ... }
for (auto [dy, dx] : cell::delta) {
    cell v = cell(u.y + dy * k, u.x + dx * k);
    if (!v.is_valid()) continue;
}
```
