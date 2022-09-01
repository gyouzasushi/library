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
  bundledCode: "#line 2 \"datastructure/convex_hull.hpp\"\ntemplate <typename T>\n\
    struct ConvexHullTrick {\npublic:\n    ConvexHullTrick() {\n    }\n    struct\
    \ F {\n        T a, b;\n    };\n    void add_line(T a, T b) {\n        F f = {a,\
    \ b};\n        while (int(q.size()) >= 2 &&\n               check(q[int(q.size())\
    \ - 2], q[int(q.size()) - 1], f)) {\n            q.pop_back();\n        }\n  \
    \      q.push_back(f);\n    }\n    T get_min(T x) {\n        while (int(q.size())\
    \ >= 2 && f(q[0], x) >= f(q[1], x)) {\n            q.pop_front();\n        }\n\
    \        return f(q[0], x);\n    }\n\nprivate:\n    std::deque<F> q;\n    bool\
    \ check(F f1, F f2, F f3) {\n        return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b\
    \ - f1.b) * (f3.a - f2.a);\n    }\n    T f(F _f, T x) {\n        return _f.a *\
    \ x + _f.b;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct ConvexHullTrick {\npublic:\n\
    \    ConvexHullTrick() {\n    }\n    struct F {\n        T a, b;\n    };\n   \
    \ void add_line(T a, T b) {\n        F f = {a, b};\n        while (int(q.size())\
    \ >= 2 &&\n               check(q[int(q.size()) - 2], q[int(q.size()) - 1], f))\
    \ {\n            q.pop_back();\n        }\n        q.push_back(f);\n    }\n  \
    \  T get_min(T x) {\n        while (int(q.size()) >= 2 && f(q[0], x) >= f(q[1],\
    \ x)) {\n            q.pop_front();\n        }\n        return f(q[0], x);\n \
    \   }\n\nprivate:\n    std::deque<F> q;\n    bool check(F f1, F f2, F f3) {\n\
    \        return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);\n\
    \    }\n    T f(F _f, T x) {\n        return _f.a * x + _f.b;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/convex_hull.hpp
  requiredBy: []
  timestamp: '2022-09-01 13:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/convex_hull.hpp
layout: document
redirect_from:
- /library/datastructure/convex_hull.hpp
- /library/datastructure/convex_hull.hpp.html
title: datastructure/convex_hull.hpp
---
