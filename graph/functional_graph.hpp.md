---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/functional_graph.test.cpp
    title: test/unit/functional_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/functional_graph.hpp\"\n#include <bit>\n#include <cassert>\n\
    #include <vector>\nstruct functional_graph {\npublic:\n    functional_graph()\
    \ : functional_graph(std::vector<int>()) {\n    }\n    explicit functional_graph(std::vector<int>\
    \ f)\n        : _n(int(f.size())),\n          _f(std::move(f)),\n          _root(_n,\
    \ -1),\n          _depth(_n, 0),\n          _component(_n, -1),\n          _pos(_n,\
    \ -1),\n          _children(_n) {\n        for (int v = 0; v < _n; v++) assert(0\
    \ <= _f[v] && _f[v] < _n);\n        std::vector<int> state(_n, 0);\n        for\
    \ (int s = 0; s < _n; s++) {\n            if (state[s]) continue;\n          \
    \  int v = s;\n            while (state[v] == 0) {\n                state[v] =\
    \ 1;\n                v = _f[v];\n            }\n            if (state[v] == 1)\
    \ {\n                int k = int(_cycles.size());\n                std::vector<int>\
    \ cyc;\n                int u = v;\n                do {\n                   \
    \ cyc.push_back(u);\n                    _root[u] = u;\n                    _component[u]\
    \ = k;\n                    _pos[u] = int(cyc.size()) - 1;\n                 \
    \   u = _f[u];\n                } while (u != v);\n                _cycles.push_back(std::move(cyc));\n\
    \            }\n            for (int u = s; state[u] == 1; u = _f[u]) state[u]\
    \ = 2;\n        }\n        for (int v = 0; v < _n; v++) {\n            if (_root[v]\
    \ != v) _children[_f[v]].push_back(v);\n        }\n        std::vector<int> order;\n\
    \        order.reserve(_n);\n        for (const std::vector<int>& cyc : _cycles)\
    \ {\n            for (int v : cyc) order.push_back(v);\n        }\n        int\
    \ max_depth = 0;\n        for (int i = 0; i < _n; i++) {\n            int v =\
    \ order[i];\n            for (int c : _children[v]) {\n                _root[c]\
    \ = _root[v];\n                _depth[c] = _depth[v] + 1;\n                _component[c]\
    \ = _component[v];\n                order.push_back(c);\n                if (max_depth\
    \ < _depth[c]) max_depth = _depth[c];\n            }\n        }\n        int log\
    \ = std::bit_width((unsigned)max_depth);\n        _up.assign(log, std::vector<int>(_n));\n\
    \        for (int j = 0; j < log; j++) {\n            for (int v = 0; v < _n;\
    \ v++) {\n                _up[j][v] = j == 0 ? _f[v] : _up[j - 1][_up[j - 1][v]];\n\
    \            }\n        }\n    }\n    int jump(int v, long long k) const {\n \
    \       assert(0 <= v && v < _n);\n        assert(0 <= k);\n        if (k < _depth[v])\
    \ {\n            for (int j = 0; k; j++, k >>= 1) {\n                if (k & 1)\
    \ v = _up[j][v];\n            }\n            return v;\n        }\n        k -=\
    \ _depth[v];\n        const std::vector<int>& cyc = _cycles[_component[v]];\n\
    \        int len = int(cyc.size());\n        return cyc[(_pos[_root[v]] + k %\
    \ len) % len];\n    }\n    bool on_cycle(int v) const {\n        assert(0 <= v\
    \ && v < _n);\n        return _root[v] == v;\n    }\n    int root(int v) const\
    \ {\n        assert(0 <= v && v < _n);\n        return _root[v];\n    }\n    int\
    \ depth(int v) const {\n        assert(0 <= v && v < _n);\n        return _depth[v];\n\
    \    }\n    int component(int v) const {\n        assert(0 <= v && v < _n);\n\
    \        return _component[v];\n    }\n    const std::vector<int>& cycle(int v)\
    \ const {\n        assert(0 <= v && v < _n);\n        return _cycles[_component[v]];\n\
    \    }\n    const std::vector<std::vector<int>>& cycles() const {\n        return\
    \ _cycles;\n    }\n    const std::vector<int>& children(int v) const {\n     \
    \   assert(0 <= v && v < _n);\n        return _children[v];\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> _f, _root, _depth, _component, _pos;\n    std::vector<std::vector<int>>\
    \ _children, _cycles, _up;\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\nstruct\
    \ functional_graph {\npublic:\n    functional_graph() : functional_graph(std::vector<int>())\
    \ {\n    }\n    explicit functional_graph(std::vector<int> f)\n        : _n(int(f.size())),\n\
    \          _f(std::move(f)),\n          _root(_n, -1),\n          _depth(_n, 0),\n\
    \          _component(_n, -1),\n          _pos(_n, -1),\n          _children(_n)\
    \ {\n        for (int v = 0; v < _n; v++) assert(0 <= _f[v] && _f[v] < _n);\n\
    \        std::vector<int> state(_n, 0);\n        for (int s = 0; s < _n; s++)\
    \ {\n            if (state[s]) continue;\n            int v = s;\n           \
    \ while (state[v] == 0) {\n                state[v] = 1;\n                v =\
    \ _f[v];\n            }\n            if (state[v] == 1) {\n                int\
    \ k = int(_cycles.size());\n                std::vector<int> cyc;\n          \
    \      int u = v;\n                do {\n                    cyc.push_back(u);\n\
    \                    _root[u] = u;\n                    _component[u] = k;\n \
    \                   _pos[u] = int(cyc.size()) - 1;\n                    u = _f[u];\n\
    \                } while (u != v);\n                _cycles.push_back(std::move(cyc));\n\
    \            }\n            for (int u = s; state[u] == 1; u = _f[u]) state[u]\
    \ = 2;\n        }\n        for (int v = 0; v < _n; v++) {\n            if (_root[v]\
    \ != v) _children[_f[v]].push_back(v);\n        }\n        std::vector<int> order;\n\
    \        order.reserve(_n);\n        for (const std::vector<int>& cyc : _cycles)\
    \ {\n            for (int v : cyc) order.push_back(v);\n        }\n        int\
    \ max_depth = 0;\n        for (int i = 0; i < _n; i++) {\n            int v =\
    \ order[i];\n            for (int c : _children[v]) {\n                _root[c]\
    \ = _root[v];\n                _depth[c] = _depth[v] + 1;\n                _component[c]\
    \ = _component[v];\n                order.push_back(c);\n                if (max_depth\
    \ < _depth[c]) max_depth = _depth[c];\n            }\n        }\n        int log\
    \ = std::bit_width((unsigned)max_depth);\n        _up.assign(log, std::vector<int>(_n));\n\
    \        for (int j = 0; j < log; j++) {\n            for (int v = 0; v < _n;\
    \ v++) {\n                _up[j][v] = j == 0 ? _f[v] : _up[j - 1][_up[j - 1][v]];\n\
    \            }\n        }\n    }\n    int jump(int v, long long k) const {\n \
    \       assert(0 <= v && v < _n);\n        assert(0 <= k);\n        if (k < _depth[v])\
    \ {\n            for (int j = 0; k; j++, k >>= 1) {\n                if (k & 1)\
    \ v = _up[j][v];\n            }\n            return v;\n        }\n        k -=\
    \ _depth[v];\n        const std::vector<int>& cyc = _cycles[_component[v]];\n\
    \        int len = int(cyc.size());\n        return cyc[(_pos[_root[v]] + k %\
    \ len) % len];\n    }\n    bool on_cycle(int v) const {\n        assert(0 <= v\
    \ && v < _n);\n        return _root[v] == v;\n    }\n    int root(int v) const\
    \ {\n        assert(0 <= v && v < _n);\n        return _root[v];\n    }\n    int\
    \ depth(int v) const {\n        assert(0 <= v && v < _n);\n        return _depth[v];\n\
    \    }\n    int component(int v) const {\n        assert(0 <= v && v < _n);\n\
    \        return _component[v];\n    }\n    const std::vector<int>& cycle(int v)\
    \ const {\n        assert(0 <= v && v < _n);\n        return _cycles[_component[v]];\n\
    \    }\n    const std::vector<std::vector<int>>& cycles() const {\n        return\
    \ _cycles;\n    }\n    const std::vector<int>& children(int v) const {\n     \
    \   assert(0 <= v && v < _n);\n        return _children[v];\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> _f, _root, _depth, _component, _pos;\n    std::vector<std::vector<int>>\
    \ _children, _cycles, _up;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2026-10-22 22:21:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/functional_graph.test.cpp
documentation_of: graph/functional_graph.hpp
layout: document
title: Functional Graph
---

### 概要
- 各頂点 $v$ から $f(v)$ へ辺を張った有向グラフ。

### 使い方
- `functional_graph(f)`: `f[v]` を頂点 `v` の行き先として構築する。
- `jump(v, k)`: 頂点 `v` から `k` 回進んだ頂点を返す。
- `on_cycle(v)`: 頂点 `v` がサイクル上にあるかを返す。
- `root(v)`: 頂点 `v` から進んで最初に着くサイクル上の頂点を返す。
- `depth(v)`: 頂点 `v` から `root(v)` までの歩数を返す。
- `component(v)`: 頂点 `v` が属する連結成分の番号を返す。`cycles()` の添字と一致する。
- `cycle(v)`: 頂点 `v` が属する連結成分のサイクルを $f$ の向きに並べた列を返す。
- `cycles()`: 全てのサイクルを返す。
- `children(v)`: `f[u] = v` かつ `u` がサイクル上にない頂点 `u` の列を返す。

### 制約
- $0 \le f[v] < n$
- $0 \le k \le 10^{18}$

### 計算量
- 構築: $\mathcal{O}(n \log n)$
- `jump`: $\mathcal{O}(\log n)$
- その他: $\mathcal{O}(1)$
