---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial_coefficient.hpp
    title: math/binomial_coefficient.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/binomial_coefficient.hpp: line 50: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include <iostream>\n\n#include \"atcoder/modint\"\n#include \"math/binomial_coefficient.hpp\"\
    \nusing mint = atcoder::modint;\nusing binom = binomial_coefficient<mint>;\nmint\
    \ lucas(int n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    int m\
    \ = mint::mod();\n    mint ret = 1;\n    while (n > 0) {\n        ret *= binom::C(n\
    \ % m, k % m);\n        n /= m, k /= m;\n    }\n    return ret;\n}\nint main()\
    \ {\n    int T, m;\n    std::cin >> T >> m;\n    mint::set_mod(m);\n    while\
    \ (T--) {\n        int n, k;\n        std::cin >> n >> k;\n        std::cout <<\
    \ lucas(n, k).val() << '\\n';\n    }\n}"
  dependsOn:
  - math/binomial_coefficient.hpp
  - math/factorize.hpp
  isVerificationFile: true
  path: test/library-checker/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2026-05-18 11:14:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/binomial_coefficient_prime_mod.test.cpp
- /verify/test/library-checker/binomial_coefficient_prime_mod.test.cpp.html
title: test/library-checker/binomial_coefficient_prime_mod.test.cpp
---
