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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <vector>\n\n#include\
    \ \"atcoder/segtree.hpp\"\ntemplate <typename T>\nstruct manhattan_mst_S {\n \
    \   T val;\n    int id;\n};\ntemplate <typename T>\nmanhattan_mst_S<T> manhattan_mst_op(manhattan_mst_S<T>\
    \ a,\n                                    manhattan_mst_S<T> b) {\n    return\
    \ a.val < b.val ? a : b;\n}\ntemplate <typename T>\nmanhattan_mst_S<T> manhattan_mst_e()\
    \ {\n    return {std::numeric_limits<T>::max(), -1};\n}\ntemplate <typename T>\n\
    std::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,\n       \
    \                                            std::vector<T> y) {\n    int n =\
    \ x.size();\n    assert(int(x.size()) == n && int(y.size()) == n);\n    std::vector<int>\
    \ id(n);\n    std::iota(id.begin(), id.end(), 0);\n    std::vector<int> y_id(n);\n\
    \    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0; a < 2; a++)\
    \ {\n        for (int b = 0; b < 2; b++) {\n            for (int c = 0; c < 2;\
    \ c++) {\n                sort(id.begin(), id.end(), [&](int i, int j) {\n   \
    \                 if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n          \
    \              return i < j;\n                    if (y[i] - x[i] == y[j] - x[j])\
    \ return y[i] > y[j];\n                    return y[i] - x[i] < y[j] - x[j];\n\
    \                });\n                std::vector<T> _y = y;\n               \
    \ std::sort(_y.begin(), _y.end());\n                for (int i = 0; i < n; i++)\
    \ {\n                    y_id[i] = std::lower_bound(_y.begin(), _y.end(), y[i])\
    \ -\n                              _y.begin();\n                }\n          \
    \      atcoder::segtree<manhattan_mst_S<T>, manhattan_mst_op<T>,\n           \
    \                      manhattan_mst_e<T>>\n                    segt(n);\n   \
    \             for (int i : id) {\n                    manhattan_mst_S<T> p = segt.prod(y_id[i],\
    \ n);\n                    if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan MST
---

### 概要
- 2次元平面上にある $N$ 個の点に対して、2点間の距離をマンハッタン距離で定義したときの最小全域木を求める。
  
### 使い方
- `manhattan_mst(x, y)`: 最小全域木に含まれ得る $O(N)$ 本の辺 `(u, v, w)` を、重みの昇順で返す。 