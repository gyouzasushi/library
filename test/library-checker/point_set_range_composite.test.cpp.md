---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library-checker/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <atcoder/modint>\n#include <atcoder/segtree>\n#include <iostream>\n\
    using mint = atcoder::modint998244353;\nstruct S {\n    mint a, b;\n    bool e;\n\
    \    mint val(int x) {\n        return a * x + b;\n    }\n};\nS op(S f, S g) {\n\
    \    if (f.e) return g;\n    if (g.e) return f;\n    return {g.a * f.a, g.a *\
    \ f.b + g.b};\n}\nS e() {\n    return {0, 0, true};\n}\nint main() {\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    std::vector<S> f(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        f[i]\
    \ = {mint::raw(a), mint::raw(b)};\n    }\n    atcoder::segtree<S, op, e> segt(f);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, c, d;\n            std::cin >> p >> c >> d;\n        \
    \    segt.set(p, {c, d});\n        }\n        if (t == 1) {\n            int l,\
    \ r, x;\n            std::cin >> l >> r >> x;\n            std::cout << segt.prod(l,\
    \ r).val(x).val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <atcoder/modint>\n#include <atcoder/segtree>\n#include <iostream>\n\
    using mint = atcoder::modint998244353;\nstruct S {\n    mint a, b;\n    bool e;\n\
    \    mint val(int x) {\n        return a * x + b;\n    }\n};\nS op(S f, S g) {\n\
    \    if (f.e) return g;\n    if (g.e) return f;\n    return {g.a * f.a, g.a *\
    \ f.b + g.b};\n}\nS e() {\n    return {0, 0, true};\n}\nint main() {\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    std::vector<S> f(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        f[i]\
    \ = {mint::raw(a), mint::raw(b)};\n    }\n    atcoder::segtree<S, op, e> segt(f);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, c, d;\n            std::cin >> p >> c >> d;\n        \
    \    segt.set(p, {c, d});\n        }\n        if (t == 1) {\n            int l,\
    \ r, x;\n            std::cin >> l >> r >> x;\n            std::cout << segt.prod(l,\
    \ r).val(x).val() << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 14:30:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/point_set_range_composite.test.cpp
- /verify/test/library-checker/point_set_range_composite.test.cpp.html
title: test/library-checker/point_set_range_composite.test.cpp
---
