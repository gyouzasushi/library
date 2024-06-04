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
  bundledCode: "#line 2 \"math/modint.hpp\"\n#include <atcoder/modint.hpp>\n#include\
    \ <iostream>\nnamespace atcoder {\ntemplate <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n\
    \                                                std::nullptr_t> = nullptr>\n\
    std::istream& operator>>(std::istream& is, T& v) {\n    long long x;\n    is >>\
    \ x;\n    v = x;\n    return is;\n}\ntemplate <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n\
    \                                                std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& v) {\n    os << v.val();\n\
    \    return os;\n}\n}  // namespace atcoder\n"
  code: "#pragma once\n#include <atcoder/modint.hpp>\n#include <iostream>\nnamespace\
    \ atcoder {\ntemplate <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n\
    \                                                std::nullptr_t> = nullptr>\n\
    std::istream& operator>>(std::istream& is, T& v) {\n    long long x;\n    is >>\
    \ x;\n    v = x;\n    return is;\n}\ntemplate <typename T, typename std::enable_if_t<internal::is_modint<T>::value,\n\
    \                                                std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& v) {\n    os << v.val();\n\
    \    return os;\n}\n}  // namespace atcoder"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2024-05-30 15:02:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
title: modint
---

### 概要
- ACL の modint + 入出力。
  
### 使い方
- [ACL のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/modint.html)を参照。