---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/tree_diameter.hpp
    title: Tree Diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\
    \n#include <iostream>\n\n#line 2 \"graph/tree_diameter.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\ntemplate <class T>\n\
    struct tree_diameter {\npublic:\n    tree_diameter() : tree_diameter(0) {\n  \
    \  }\n    explicit tree_diameter(int n) : _n(n), g(n) {\n    }\n    void add_edge(int\
    \ u, int v, T w = 1) {\n        assert(0 <= u && u < _n);\n        assert(0 <=\
    \ v && v < _n);\n        g[u].emplace_back(v, w);\n        g[v].emplace_back(u,\
    \ w);\n    }\n    void build() {\n        assert(_n >= 1);\n        std::vector<int>\
    \ par;\n        std::vector<T> d;\n        search(0, d, par);\n        _u = int(std::ranges::max_element(d)\
    \ - d.begin());\n        search(_u, d, par);\n        _v = int(std::ranges::max_element(d)\
    \ - d.begin());\n        _length = d[_v];\n        _path.clear();\n        for\
    \ (int x = _v; x != -1; x = par[x]) _path.push_back(x);\n        std::ranges::reverse(_path);\n\
    \    }\n    T length() const {\n        return _length;\n    }\n    std::pair<int,\
    \ int> ends() const {\n        return {_u, _v};\n    }\n    const std::vector<int>&\
    \ path() const {\n        return _path;\n    }\n\nprivate:\n    int _n, _u = -1,\
    \ _v = -1;\n    T _length = T(0);\n    std::vector<std::vector<std::pair<int,\
    \ T>>> g;\n    std::vector<int> _path;\n    void search(int s, std::vector<T>&\
    \ d, std::vector<int>& par) const {\n        d.assign(_n, T(0));\n        par.assign(_n,\
    \ -1);\n        std::vector<int> st = {s};\n        par[s] = s;\n        while\
    \ (!st.empty()) {\n            int x = st.back();\n            st.pop_back();\n\
    \            for (auto [y, w] : g[x]) {\n                if (par[y] != -1) continue;\n\
    \                par[y] = x;\n                d[y] = d[x] + w;\n             \
    \   st.push_back(y);\n            }\n        }\n        par[s] = -1;\n    }\n\
    };\n#line 5 \"test/aoj/GRL_5_A.test.cpp\"\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    tree_diameter<long long> d(n);\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        int s, t;\n        long long w;\n        std::cin >> s >> t >> w;\n\
    \        d.add_edge(s, t, w);\n    }\n    d.build();\n    std::cout << d.length()\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\n#include\
    \ <iostream>\n\n#include \"graph/tree_diameter.hpp\"\nint main() {\n    int n;\n\
    \    std::cin >> n;\n    tree_diameter<long long> d(n);\n    for (int i = 0; i\
    \ < n - 1; i++) {\n        int s, t;\n        long long w;\n        std::cin >>\
    \ s >> t >> w;\n        d.add_edge(s, t, w);\n    }\n    d.build();\n    std::cout\
    \ << d.length() << '\\n';\n}\n"
  dependsOn:
  - graph/tree_diameter.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
