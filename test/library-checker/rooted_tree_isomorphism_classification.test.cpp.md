---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/subtree_classify.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u306B\u3088\u308B\u90E8\
      \u5206\u6728\u306E\u5206\u985E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/library-checker/rooted_tree_isomorphism_classification.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include <iostream>\n\n#line 2 \"graph/subtree_classify.hpp\"\n\n#include\
    \ <algorithm>\n#include <map>\n#include <vector>\nstd::vector<int> subtree_classify(std::vector<std::vector<int>>\
    \ g,\n                                  int root = 0) {\n    std::vector<int>\
    \ ret(g.size());\n    std::map<std::vector<int>, int> cache;\n    auto dfs = [&](auto\
    \ dfs, int u) -> int {\n        std::vector<int> hash;\n        hash.push_back(-1);\n\
    \        for (int v : g[u]) hash.push_back(dfs(dfs, v));\n        std::sort(hash.begin(),\
    \ hash.end());\n        hash.push_back(-1);\n        if (!cache.count(hash)) cache[hash]\
    \ = int(cache.size());\n        return ret[u] = cache[hash];\n    };\n    dfs(dfs,\
    \ root);\n    return ret;\n}\n#line 7 \"test/library-checker/rooted_tree_isomorphism_classification.test.cpp\"\
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
  timestamp: '2023-01-11 14:05:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/rooted_tree_isomorphism_classification.test.cpp
- /verify/test/library-checker/rooted_tree_isomorphism_classification.test.cpp.html
title: test/library-checker/rooted_tree_isomorphism_classification.test.cpp
---
