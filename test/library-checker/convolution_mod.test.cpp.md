---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <iostream>\n\n#include \"atcoder/convolution.hpp\"\n#include \"math/modint.hpp\"\
    \nusing mint = modint998244353;\nint main() {\n    int n, m;\n    std::cin >>\
    \ n >> m;\n    std::vector<mint> a(n), b(m);\n    for (int i = 0; i < n; i++)\
    \ std::cin >> a[i];\n    for (int i = 0; i < m; i++) std::cin >> b[i];\n    std::vector<mint>\
    \ c = atcoder::convolution(a, b);\n    for (int i = 0; i <= (n - 1) + (m - 1);\
    \ i++) {\n        std::cout << c[i] << \" \\n\"[i == (n - 1) + (m - 1)];\n   \
    \ }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/convolution_mod.test.cpp
- /verify/test/library-checker/convolution_mod.test.cpp.html
title: test/library-checker/convolution_mod.test.cpp
---
