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
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    \n#include \"../math/modint.hpp\"\nint chromatic_number(std::vector<std::vector<bool>>\
    \ g) {\n    int n = g.size();\n    std::vector<int> bit(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        assert(int(g[i].size()) == n);\n        for (int j\
    \ = 0; j < n; j++) {\n            bit[i] |= g[i][j] << j;\n        }\n    }\n\
    \    int ret = n;\n    using mint = modint;\n    for (int mod : {1e9 + 7, 1e9\
    \ + 11, 1e9 + 21}) {\n        mint::set_mod(mod);\n        std::vector<mint> dp(1\
    \ << n), prod(1 << n, 1);\n        dp[0] = 1;\n        for (int s = 1; s < 1 <<\
    \ n; s++) {\n            int u = __builtin_ctz(s);\n            dp[s] = dp[s ^\
    \ (1 << u)] + dp[(s ^ (1 << u)) & ~bit[u]];\n        }\n        for (int i = 1;\
    \ i < ret; i++) {\n            mint sum = 0;\n            for (int j = 0; j <\
    \ 1 << n; j++) {\n                int s = j ^ (j >> 1);\n                prod[s]\
    \ *= dp[s];\n                sum += j & 1 ? prod[s] : -prod[s];\n            }\n\
    \            if (sum.val() != 0) ret = i;\n        }\n    }\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic_number.hpp
layout: document
title: "\u5F69\u8272\u6570"
---

### 概要
- グラフの彩色数を求める。
  
### 使い方
- `chromatic_number(g)`: 隣接行列 `g` で表されるグラフの彩色数を求める。

### 計算量
- $\mathcal O(2^N N)$