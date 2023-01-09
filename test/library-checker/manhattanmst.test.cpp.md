---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/unionfind.hpp
    title: datastructure/unionfind.hpp
  - icon: ':x:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/library-checker/manhattanmst.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include <iostream>\n\n#line\
    \ 2 \"datastructure/unionfind.hpp\"\n#include <algorithm>\n#include <vector>\n\
    struct UnionFind {\n    int n;\n    std::vector<int> data;\n    UnionFind(int\
    \ _n) : n(_n), data(_n, -1) {\n    }\n    int root(int x) {\n        return (data[x]\
    \ < 0) ? x : data[x] = root(data[x]);\n    }\n    bool unite(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if (x != y) {\n         \
    \   if (data[y] < data[x]) std::swap(x, y);\n            data[x] += data[y];\n\
    \            data[y] = x;\n        }\n        return x != y;\n    }\n    bool\
    \ find(int x, int y) {\n        return root(x) == root(y);\n    }\n    int size(int\
    \ x) {\n        return -data[root(x)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> root_buf(n), group_size(n);\n        for\
    \ (int i = 0; i < n; i++) {\n            root_buf[i] = root(i);\n            group_size[root_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> ret(n);\n        for (int i\
    \ = 0; i < n; i++) {\n            ret[i].reserve(group_size[i]);\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            ret[root_buf[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(\n                      ret.begin(),\
    \ ret.end(),\n                      [&](const std::vector<int>& v) { return v.empty();\
    \ }),\n                  ret.end());\n        return ret;\n    }\n};\n#line 3\
    \ \"graph/manhattan_mst.hpp\"\n#include <cassert>\n#include <map>\n#include <numeric>\n\
    #line 7 \"graph/manhattan_mst.hpp\"\ntemplate <typename T>\nstd::vector<std::tuple<int,\
    \ int, T>> manhattan_mst(std::vector<T> x,\n                                 \
    \                  std::vector<T> y) {\n    int n = x.size();\n    assert(int(x.size())\
    \ == n && int(y.size()) == n);\n    std::vector<int> id(n);\n    std::iota(id.begin(),\
    \ id.end(), 0);\n\n    std::vector<std::tuple<int, int, T>> ret;\n    for (int\
    \ gyouza = 0; gyouza < 2; gyouza++) {\n        for (int sushi = 0; sushi < 2;\
    \ sushi++) {\n            std::sort(id.begin(), id.end(), [&](int i, int j) {\n\
    \                if (y[i] == y[j]) {\n                    return x[i] < x[j];\n\
    \                }\n                return y[i] < y[j];\n            });\n   \
    \         std::map<T, int> mp;\n            for (int i : id) {\n             \
    \   if (auto it = mp.upper_bound(x[i]); it != mp.begin()) {\n                \
    \    int j = prev(it)->second;\n                    ret.emplace_back(i, j, abs(x[i]\
    \ - x[j]) + abs(y[i] - y[j]));\n                }\n                for (auto it\
    \ = mp.lower_bound(x[i]); it != mp.end();\n                     it = mp.erase(it))\
    \ {\n                    int j = it->second;\n                    if (x[i] + y[i]\
    \ <= x[j] + y[j]) break;\n                }\n                mp[x[i]] = i;\n \
    \           }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
    \ : y) y = -y;\n    }\n    sort(ret.begin(), ret.end(),\n         [](auto a, auto\
    \ b) { return std::get<2>(a) < std::get<2>(b); });\n    return ret;\n}\n#line\
    \ 6 \"test/library-checker/manhattanmst.test.cpp\"\nint main() {\n    int n;\n\
    \    std::cin >> n;\n    std::vector<long long> x(n), y(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n    }\n\n    UnionFind\
    \ uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int, int>> ans;\n\
    \    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (uf.unite(u, v))\
    \ {\n            sum += w;\n            ans.emplace_back(u, v);\n        }\n \
    \   }\n    std::cout << sum << '\\n';\n    for (auto [u, v] : ans) {\n       \
    \ std::cout << u << ' ' << v << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include\
    \ <iostream>\n\n#include \"datastructure/unionfind.hpp\"\n#include \"graph/manhattan_mst.hpp\"\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<long long> x(n),\
    \ y(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> x[i] >> y[i];\n\
    \    }\n\n    UnionFind uf(n);\n    long long sum = 0;\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (auto [u, v, w] : manhattan_mst(x, y)) {\n        if (uf.unite(u,\
    \ v)) {\n            sum += w;\n            ans.emplace_back(u, v);\n        }\n\
    \    }\n    std::cout << sum << '\\n';\n    for (auto [u, v] : ans) {\n      \
    \  std::cout << u << ' ' << v << '\\n';\n    }\n}"
  dependsOn:
  - datastructure/unionfind.hpp
  - graph/manhattan_mst.hpp
  isVerificationFile: true
  path: test/library-checker/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2023-01-09 23:28:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/manhattanmst.test.cpp
- /verify/test/library-checker/manhattanmst.test.cpp.html
title: test/library-checker/manhattanmst.test.cpp
---
