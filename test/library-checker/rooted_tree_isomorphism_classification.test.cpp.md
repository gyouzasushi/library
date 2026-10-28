---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/subtree_classify.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u306B\u3088\u308B\u90E8\
      \u5206\u6728\u306E\u5206\u985E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/library-checker/rooted_tree_isomorphism_classification.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include <iostream>\n\n#line 2 \"graph/subtree_classify.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <vector>\nstd::vector<int> subtree_classify(const\
    \ std::vector<std::vector<int>>& g, int root = 0) {\n    int n = int(g.size());\n\
    \    assert(0 <= root && root < n);\n    std::vector<int> par(n, -1), order;\n\
    \    order.reserve(n);\n    order.push_back(root);\n    par[root] = root;\n  \
    \  for (int i = 0; i < int(order.size()); i++) {\n        int u = order[i];\n\
    \        for (int v : g[u]) {\n            if (v == par[u]) continue;\n      \
    \      assert(par[v] == -1);\n            par[v] = u;\n            order.push_back(v);\n\
    \        }\n    }\n    assert(int(order.size()) == n);\n    std::vector<int> ret(n);\n\
    \    std::map<std::vector<int>, int> id;\n    std::vector<int> key;\n    for (int\
    \ i = n - 1; i >= 0; i--) {\n        int u = order[i];\n        key.clear();\n\
    \        for (int v : g[u]) {\n            if (v != par[u]) key.push_back(ret[v]);\n\
    \        }\n        std::ranges::sort(key);\n        ret[u] = id.try_emplace(key,\
    \ int(id.size())).first->second;\n    }\n    return ret;\n}\n#line 7 \"test/library-checker/rooted_tree_isomorphism_classification.test.cpp\"\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        std::cin >>\
    \ p;\n        g[p].push_back(i);\n    }\n\n    std::vector<int> a = subtree_classify(g);\n\
    \    int k = *std::max_element(a.begin(), a.end()) + 1;\n    std::cout << k <<\
    \ '\\n';\n    for (int i = 0; i < n; i++) {\n        std::cout << a[i] << \" \\\
    n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include <iostream>\n\n#include \"graph/subtree_classify.hpp\"\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<std::vector<int>> g(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int p;\n        std::cin >> p;\n \
    \       g[p].push_back(i);\n    }\n\n    std::vector<int> a = subtree_classify(g);\n\
    \    int k = *std::max_element(a.begin(), a.end()) + 1;\n    std::cout << k <<\
    \ '\\n';\n    for (int i = 0; i < n; i++) {\n        std::cout << a[i] << \" \\\
    n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - graph/subtree_classify.hpp
  isVerificationFile: true
  path: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
  requiredBy: []
  timestamp: '2026-10-28 21:58:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/rooted_tree_isomorphism_classification.test.cpp
- /verify/test/library-checker/rooted_tree_isomorphism_classification.test.cpp.html
title: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
---
