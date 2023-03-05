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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/lazysegtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <iostream>\n\n#include \"atcoder/lazysegtree.hpp\"\n#include \"math/modint.hpp\"\
    \nusing mint = modint998244353;\nstruct S {\n    mint val;\n    int size;\n};\n\
    S op(S a, S b) {\n    return {a.val + b.val, a.size + b.size};\n}\nS e() {\n \
    \   return {0, 0};\n}\nstruct F {\n    mint b, c;\n};\nF id() {\n    return {1,\
    \ 0};\n}\nS mapping(F f, S x) {\n    return {f.b * x.val + f.c * x.size, x.size};\n\
    }\nF composition(F f, F g) {\n    return {f.b * g.b, f.b * g.c + f.c};\n}\n\n\
    int main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<S> a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        std::cin >> a[i].val;\n        a[i].size\
    \ = 1;\n    }\n    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>\
    \ segt(a);\n    while (q--) {\n        int t;\n        std::cin >> t;\n      \
    \  if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l >> r\
    \ >> b >> c;\n            segt.apply(l, r, {b, c});\n        }\n        if (t\
    \ == 1) {\n            int l, r;\n            std::cin >> l >> r;\n          \
    \  std::cout << segt.prod(l, r).val << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/range_affine_range_sum.test.cpp
- /verify/test/library-checker/range_affine_range_sum.test.cpp.html
title: test/library-checker/range_affine_range_sum.test.cpp
---
