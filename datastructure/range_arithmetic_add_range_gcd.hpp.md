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
  bundledCode: "#line 2 \"datastructure/range_arithmetic_add_range_gcd.hpp\"\n// \u6570\
    \u5217A\u306B\u5BFE\u3059\u308B2\u7A2E\u985E\u306E\u30AF\u30A8\u30EA\u3092\u51E6\
    \u7406\n// \u30AF\u30A8\u30EA1 : \u533A\u9593[l,r)\u306Bx\u3092\u52A0\u7B97(apply)\n\
    // \u30AF\u30A8\u30EA2 : \u533A\u9593[l,r)\u306EGCD\u3092\u53D6\u5F97(fold)\n\
    template <typename T>\nstruct RangeAddRangeGCD {\npublic:\n    RangeAddRangeGCD(int\
    \ n) : RangeAddRangeGCD(vector<T>(n, 0)) {\n    }\n    RangeAddRangeGCD(const\
    \ vector<T> &vec) : N((int)vec.size()) {\n        sz = 1;\n        while (sz <\
    \ N) sz <<= 1;\n        seg.resize(2 * sz);\n        for (int i = 0; i < N - 1;\
    \ i++) {\n            seg[i + sz] = vec[i + 1] - vec[i];\n        }\n        for\
    \ (int i = sz - 1; i >= 1; i--) {\n            seg[i] = gcd(seg[2 * i], seg[2\
    \ * i + 1]);\n        }\n        dseg.resize(2 * sz);\n        for (int i = 0;\
    \ i < N; i++) {\n            dseg[i + sz] = vec[i];\n        }\n    }\n\n    void\
    \ apply(int l, int r, T x) {\n        assert(0 <= l && l < r && r <= N);\n   \
    \     if (l) {\n            int now = l - 1 + sz;\n            seg[now] += x;\n\
    \            now >>= 1;\n            while (now) {\n                seg[now] =\
    \ gcd(seg[2 * now], seg[2 * now + 1]);\n                now >>= 1;\n         \
    \   }\n        }\n        if (r <= N - 1) {\n            int now = r - 1 + sz;\n\
    \            seg[now] -= x;\n            now >>= 1;\n            while (now) {\n\
    \                seg[now] = gcd(seg[2 * now], seg[2 * now + 1]);\n           \
    \     now >>= 1;\n            }\n        }\n        for (int a = l + sz, b = r\
    \ + sz; a < b; a >>= 1, b >>= 1) {\n            if (a & 1) dseg[a] += x, ++a;\n\
    \            if (b & 1) --b, dseg[b] += x;\n        }\n    }\n\n    T fold(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= N);\n        if (r - l ==\
    \ 1) return _get(l);\n        T tmp = 0;\n        for (int a = l + sz, b = r -\
    \ 1 + sz; a < b; a >>= 1, b >>= 1) {\n            if (a & 1) tmp = gcd(tmp, seg[a]),\
    \ ++a;\n            if (b & 1) --b, tmp = gcd(tmp, seg[b]);\n        }\n     \
    \   return gcd(tmp, _get(l));\n    }\n\nprivate:\n    int N, sz;\n    vector<T>\
    \ seg, dseg;\n\n    T _get(int x) {\n        T ret = 0;\n        x += sz;\n  \
    \      while (x) {\n            ret += dseg[x];\n            x >>= 1;\n      \
    \  }\n        return ret;\n    }\n};\n\ntemplate <typename T>\nstruct RangeArithmeticAddRangeGCD\
    \ : RangeAddRangeGCD<T> {\npublic:\n    RangeArithmeticAddRangeGCD(int n)\n  \
    \      : RangeArithmeticAddRangeGCD(vector<T>(n, 0)) {\n    }\n    RangeArithmeticAddRangeGCD(const\
    \ vector<T> &vec)\n        : RARG((int)vec.size() - 1), N((int)vec.size()) {\n\
    \        for (int i = 0; i < N - 1; i++)\n            RARG::apply(i, i + 1, vec[i\
    \ + 1] - vec[i]);\n        sz = 1;\n        while (sz < N) sz <<= 1;\n       \
    \ A.resize(2 * sz);\n        B.resize(2 * sz);\n        for (int i = 0; i < N;\
    \ i++) B[i + sz] = vec[i];\n    }\n\n    void apply(int l, int r, T a, T d) {\n\
    \        T b = a - d * l;\n        for (int x = l + sz, y = r + sz; x < y; x >>=\
    \ 1, y >>= 1) {\n            if (x & 1) A[x] += d, ++x;\n            if (y & 1)\
    \ --y, A[y] += d;\n        }\n        for (int x = l + sz, y = r + sz; x < y;\
    \ x >>= 1, y >>= 1) {\n            if (x & 1) B[x] += b, ++x;\n            if\
    \ (y & 1) --y, B[y] += b;\n        }\n        if (l) RARG::apply(l - 1, l, a);\n\
    \        if (r - l > 1) RARG::apply(l, r - 1, d);\n        if (r <= N - 1) RARG::apply(r\
    \ - 1, r, -a - (r - l - 1) * d);\n    }\n\n    T fold(int l, int r) {\n      \
    \  if (r - l == 1) return _get(l);\n        return gcd(_get(l), RARG::fold(l,\
    \ r - 1));\n    }\n\nprivate:\n    using RARG = RangeAddRangeGCD<T>;\n    int\
    \ N, sz;\n    vector<T> A, B;\n\n    T _get(int x) {\n        int now = x + sz;\n\
    \        T a = 0, ret = 0;\n        while (now) {\n            a += A[now];\n\
    \            ret += B[now];\n            now >>= 1;\n        }\n        return\
    \ ret + a * x;\n    }\n};\n"
  code: "#pragma once\n// \u6570\u5217A\u306B\u5BFE\u3059\u308B2\u7A2E\u985E\u306E\
    \u30AF\u30A8\u30EA\u3092\u51E6\u7406\n// \u30AF\u30A8\u30EA1 : \u533A\u9593[l,r)\u306B\
    x\u3092\u52A0\u7B97(apply)\n// \u30AF\u30A8\u30EA2 : \u533A\u9593[l,r)\u306EGCD\u3092\
    \u53D6\u5F97(fold)\ntemplate <typename T>\nstruct RangeAddRangeGCD {\npublic:\n\
    \    RangeAddRangeGCD(int n) : RangeAddRangeGCD(vector<T>(n, 0)) {\n    }\n  \
    \  RangeAddRangeGCD(const vector<T> &vec) : N((int)vec.size()) {\n        sz =\
    \ 1;\n        while (sz < N) sz <<= 1;\n        seg.resize(2 * sz);\n        for\
    \ (int i = 0; i < N - 1; i++) {\n            seg[i + sz] = vec[i + 1] - vec[i];\n\
    \        }\n        for (int i = sz - 1; i >= 1; i--) {\n            seg[i] =\
    \ gcd(seg[2 * i], seg[2 * i + 1]);\n        }\n        dseg.resize(2 * sz);\n\
    \        for (int i = 0; i < N; i++) {\n            dseg[i + sz] = vec[i];\n \
    \       }\n    }\n\n    void apply(int l, int r, T x) {\n        assert(0 <= l\
    \ && l < r && r <= N);\n        if (l) {\n            int now = l - 1 + sz;\n\
    \            seg[now] += x;\n            now >>= 1;\n            while (now) {\n\
    \                seg[now] = gcd(seg[2 * now], seg[2 * now + 1]);\n           \
    \     now >>= 1;\n            }\n        }\n        if (r <= N - 1) {\n      \
    \      int now = r - 1 + sz;\n            seg[now] -= x;\n            now >>=\
    \ 1;\n            while (now) {\n                seg[now] = gcd(seg[2 * now],\
    \ seg[2 * now + 1]);\n                now >>= 1;\n            }\n        }\n \
    \       for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {\n        \
    \    if (a & 1) dseg[a] += x, ++a;\n            if (b & 1) --b, dseg[b] += x;\n\
    \        }\n    }\n\n    T fold(int l, int r) {\n        assert(0 <= l && l <\
    \ r && r <= N);\n        if (r - l == 1) return _get(l);\n        T tmp = 0;\n\
    \        for (int a = l + sz, b = r - 1 + sz; a < b; a >>= 1, b >>= 1) {\n   \
    \         if (a & 1) tmp = gcd(tmp, seg[a]), ++a;\n            if (b & 1) --b,\
    \ tmp = gcd(tmp, seg[b]);\n        }\n        return gcd(tmp, _get(l));\n    }\n\
    \nprivate:\n    int N, sz;\n    vector<T> seg, dseg;\n\n    T _get(int x) {\n\
    \        T ret = 0;\n        x += sz;\n        while (x) {\n            ret +=\
    \ dseg[x];\n            x >>= 1;\n        }\n        return ret;\n    }\n};\n\n\
    template <typename T>\nstruct RangeArithmeticAddRangeGCD : RangeAddRangeGCD<T>\
    \ {\npublic:\n    RangeArithmeticAddRangeGCD(int n)\n        : RangeArithmeticAddRangeGCD(vector<T>(n,\
    \ 0)) {\n    }\n    RangeArithmeticAddRangeGCD(const vector<T> &vec)\n       \
    \ : RARG((int)vec.size() - 1), N((int)vec.size()) {\n        for (int i = 0; i\
    \ < N - 1; i++)\n            RARG::apply(i, i + 1, vec[i + 1] - vec[i]);\n   \
    \     sz = 1;\n        while (sz < N) sz <<= 1;\n        A.resize(2 * sz);\n \
    \       B.resize(2 * sz);\n        for (int i = 0; i < N; i++) B[i + sz] = vec[i];\n\
    \    }\n\n    void apply(int l, int r, T a, T d) {\n        T b = a - d * l;\n\
    \        for (int x = l + sz, y = r + sz; x < y; x >>= 1, y >>= 1) {\n       \
    \     if (x & 1) A[x] += d, ++x;\n            if (y & 1) --y, A[y] += d;\n   \
    \     }\n        for (int x = l + sz, y = r + sz; x < y; x >>= 1, y >>= 1) {\n\
    \            if (x & 1) B[x] += b, ++x;\n            if (y & 1) --y, B[y] += b;\n\
    \        }\n        if (l) RARG::apply(l - 1, l, a);\n        if (r - l > 1) RARG::apply(l,\
    \ r - 1, d);\n        if (r <= N - 1) RARG::apply(r - 1, r, -a - (r - l - 1) *\
    \ d);\n    }\n\n    T fold(int l, int r) {\n        if (r - l == 1) return _get(l);\n\
    \        return gcd(_get(l), RARG::fold(l, r - 1));\n    }\n\nprivate:\n    using\
    \ RARG = RangeAddRangeGCD<T>;\n    int N, sz;\n    vector<T> A, B;\n\n    T _get(int\
    \ x) {\n        int now = x + sz;\n        T a = 0, ret = 0;\n        while (now)\
    \ {\n            a += A[now];\n            ret += B[now];\n            now >>=\
    \ 1;\n        }\n        return ret + a * x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/range_arithmetic_add_range_gcd.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/range_arithmetic_add_range_gcd.hpp
layout: document
redirect_from:
- /library/datastructure/range_arithmetic_add_range_gcd.hpp
- /library/datastructure/range_arithmetic_add_range_gcd.hpp.html
title: datastructure/range_arithmetic_add_range_gcd.hpp
---
