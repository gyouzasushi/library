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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"atcoder/convolution.hpp\"\nstd::vector<bool> wildcard_matching(std::string\
    \ s, std::string t) {\n    int n = s.size(), m = t.size();\n    assert(m > 0);\n\
    \    assert(n >= m);\n    std::vector<long long> a1(n), a2(n), a3(n);\n    for\
    \ (int i = 0; i < n; i++) {\n        a1[i] = s[i] == '?' ? 0 : 1;\n        a2[i]\
    \ = a1[i] * (s[i] == '?' ? 0 : (long long)s[i]);\n        a3[i] = a2[i] * (s[i]\
    \ == '?' ? 0 : (long long)s[i]);\n    }\n    std::vector<long long> b1(m), b2(m),\
    \ b3(m);\n    for (int i = 0; i < m; i++) {\n        b1[i] = t[i] == '?' ? 0 :\
    \ 1;\n        b2[i] = b1[i] * (t[i] == '?' ? 0 : (long long)t[i]);\n        b3[i]\
    \ = b2[i] * (t[i] == '?' ? 0 : (long long)t[i]);\n    }\n    auto f = [](const\
    \ std::vector<long long> &a, std::vector<long long> &b) {\n        std::reverse(b.begin(),\
    \ b.end());\n        std::vector<long long> c = atcoder::convolution_ll(a, b);\n\
    \        return std::vector<long long>(c.begin() + b.size() - 1, c.end());\n \
    \   };\n    std::vector<long long> c1 = f(a3, b1);\n    std::vector<long long>\
    \ c2 = f(a2, b2);\n    std::vector<long long> c3 = f(a1, b3);\n    std::vector<bool>\
    \ ret(n - m + 1);\n    for (int i = 0; i < n - m + 1; i++) {\n        ret[i] =\
    \ c1[i] - c2[i] * 2 + c3[i] == 0;\n    }\n    return ret;\n}\n\nstd::vector<bool>\
    \ wildcard_matching_lower(std::string s, std::string t) {\n    int n = s.size(),\
    \ m = t.size();\n    assert(m > 0);\n    assert(n >= m);\n    std::vector<long\
    \ long> a1(n), a2(n), a3(n);\n    for (int i = 0; i < n; i++) {\n        a1[i]\
    \ = s[i] == '?' ? 0 : 1;\n        a2[i] = a1[i] * (s[i] == '?' ? 0 : (long long)(s[i]\
    \ - 'a' + 1));\n        a3[i] = a2[i] * (s[i] == '?' ? 0 : (long long)(s[i] -\
    \ 'a' + 1));\n    }\n    std::vector<long long> b1(m), b2(m), b3(m);\n    for\
    \ (int i = 0; i < m; i++) {\n        b1[i] = t[i] == '?' ? 0 : 1;\n        b2[i]\
    \ = b1[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'a' + 1));\n        b3[i] =\
    \ b2[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'a' + 1));\n    }\n    auto f\
    \ = [](const std::vector<long long> &a, std::vector<long long> &b) {\n       \
    \ std::reverse(b.begin(), b.end());\n        std::vector c = atcoder::convolution(a,\
    \ b);\n        return std::vector<long long>(c.begin() + b.size() - 1, c.end());\n\
    \    };\n    std::vector<long long> c1 = f(a3, b1);\n    std::vector<long long>\
    \ c2 = f(a2, b2);\n    std::vector<long long> c3 = f(a1, b3);\n    std::vector<bool>\
    \ ret(n - m + 1);\n    for (int i = 0; i < n - m + 1; i++) {\n        ret[i] =\
    \ c1[i] - c2[i] * 2 + c3[i] == 0;\n    }\n    return ret;\n}\n\nstd::vector<bool>\
    \ wildcard_matching_upper(std::string s, std::string t) {\n    int n = s.size(),\
    \ m = t.size();\n    assert(m > 0);\n    assert(n >= m);\n    std::vector<long\
    \ long> a1(n), a2(n), a3(n);\n    for (int i = 0; i < n; i++) {\n        a1[i]\
    \ = s[i] == '?' ? 0 : 1;\n        a2[i] = a1[i] * (s[i] == '?' ? 0 : (long long)(s[i]\
    \ - 'A' + 1));\n        a3[i] = a2[i] * (s[i] == '?' ? 0 : (long long)(s[i] -\
    \ 'A' + 1));\n    }\n    std::vector<long long> b1(m), b2(m), b3(m);\n    for\
    \ (int i = 0; i < m; i++) {\n        b1[i] = t[i] == '?' ? 0 : 1;\n        b2[i]\
    \ = b1[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'A' + 1));\n        b3[i] =\
    \ b2[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'A' + 1));\n    }\n    auto f\
    \ = [](const std::vector<long long> &a, std::vector<long long> &b) {\n       \
    \ std::reverse(b.begin(), b.end());\n        std::vector c = atcoder::convolution(a,\
    \ b);\n        return std::vector<long long>(c.begin() + b.size() - 1, c.end());\n\
    \    };\n    std::vector<long long> c1 = f(a3, b1);\n    std::vector<long long>\
    \ c2 = f(a2, b2);\n    std::vector<long long> c3 = f(a1, b3);\n    std::vector<bool>\
    \ ret(n - m + 1);\n    for (int i = 0; i < n - m + 1; i++) {\n        ret[i] =\
    \ c1[i] - c2[i] * 2 + c3[i] == 0;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/wildcard_matching.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/wildcard_matching.hpp
layout: document
title: Wildcard Matching
---

### 概要
- 2つのワイルドカード付き文字列をスライドさせて、各箇所について一致するかどうかを調べる。
- 定数倍高速化の余地あり → 畳み込んだ後の配列の要素は $N\sigma^2$ 程度の大きさになるが、これが収まる限りで $\mathrm{mod}$ を小さくとることで `convolution` の回数を減らすことができる。
  
### 使い方
- `wildcard_matching(s, t)`:長さ $\|s\| - \|t\| + 1$ の配列 `ret` を返す。`ret[i]` は、'?' をワイルドカードとして `s.substr(i, t.size())` と `t` がマッチするかを表す。