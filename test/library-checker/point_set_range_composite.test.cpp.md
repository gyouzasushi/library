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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <iostream>\n\n#include \"atcoder/segtree.hpp\"\n#include \"math/modint.hpp\"\
    \n\nusing mint = modint998244353;\nstruct S {\n    mint a, b;\n    bool e;\n \
    \   mint val(int x) {\n        return a * x + b;\n    }\n};\nS op(S f, S g) {\n\
    \    if (f.e) return g;\n    if (g.e) return f;\n    return {g.a * f.a, g.a *\
    \ f.b + g.b};\n}\nS e() {\n    return {0, 0, true};\n}\nint main() {\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    std::vector<S> f(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        mint a, b;\n        std::cin >> a >> b;\n        f[i]\
    \ = {a, b};\n    }\n    atcoder::segtree<S, op, e> segt(f);\n    while (q--) {\n\
    \        int t;\n        std::cin >> t;\n        if (t == 0) {\n            int\
    \ p, c, d;\n            std::cin >> p >> c >> d;\n            segt.set(p, {c,\
    \ d});\n        }\n        if (t == 1) {\n            int l, r, x;\n         \
    \   std::cin >> l >> r >> x;\n            std::cout << segt.prod(l, r).val(x)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_set_range_composite.test.cpp
- /verify/test/library-checker/point_set_range_composite.test.cpp.html
title: test/library-checker/point_set_range_composite.test.cpp
---
