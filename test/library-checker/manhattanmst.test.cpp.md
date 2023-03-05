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
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include\
    \ <iostream>\n\n#include \"datastructure/unionfind.hpp\"\n#include \"graph/manhattan_mst.hpp\"\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> x(n),\
    \ y(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n\
    \    }\n\n    UnionFind uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (uf.unite(u,\
    \ v)) {\n            sum += w;\n            ans.emplace_back(u, v);\n        }\n\
    \    }\n    std::cout << sum << '\\n';\n    for (auto [u, v] : ans) {\n      \
    \  std::cout << u << ' ' << v << '\\n';\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/manhattanmst.test.cpp
- /verify/test/library-checker/manhattanmst.test.cpp.html
title: test/library-checker/manhattanmst.test.cpp
---
