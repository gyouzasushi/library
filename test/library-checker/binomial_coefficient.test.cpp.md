---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial_coefficient_arbitrary_mod.hpp
    title: Binomial Coefficient (Arbitrary Mod)
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient
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
    \ math/binomial_coefficient_arbitrary_mod.hpp: line 8: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\
    #include \"math/binomial_coefficient_arbitrary_mod.hpp\"\n\n#include <iostream>\n\
    int main() {\n    int t, m;\n    std::cin >> t >> m;\n    using binom = binomial_coefficient_arbitrary_mod<>;\n\
    \    binom::set_mod(m);\n    while (t--) {\n        long long n, k;\n        std::cin\
    \ >> n >> k;\n        std::cout << binom::C(n, k) << '\\n';\n    }\n}"
  dependsOn:
  - math/binomial_coefficient_arbitrary_mod.hpp
  - math/factorize.hpp
  isVerificationFile: true
  path: test/library-checker/binomial_coefficient.test.cpp
  requiredBy: []
  timestamp: '2026-05-18 11:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/binomial_coefficient.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/binomial_coefficient.test.cpp
- /verify/test/library-checker/binomial_coefficient.test.cpp.html
title: test/library-checker/binomial_coefficient.test.cpp
---
