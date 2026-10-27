---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/persistent_array.hpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library-checker/persistent_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"datastructure/persistent_array.hpp\"\n#include\
    \ <cassert>\n#line 4 \"datastructure/persistent_array.hpp\"\ntemplate <class T>\
    \ struct persistent_array {\npublic:\n    explicit persistent_array(int n) : persistent_array(std::vector<T>(n))\
    \ {\n    }\n    explicit persistent_array(const std::vector<T>& v) : _n(int(v.size()))\
    \ {\n        nodes.reserve(2 * _n);\n        if (_n > 0) build(v, 0, _n);\n  \
    \  }\n    int size() const {\n        return _n;\n    }\n    T get(int root, int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        int cur = root, l = 0,\
    \ r = _n;\n        while (r - l > 1) {\n            int mid = (l + r) / 2;\n \
    \           if (p < mid) {\n                cur = nodes[cur].l, r = mid;\n   \
    \         } else {\n                cur = nodes[cur].r, l = mid;\n           \
    \ }\n        }\n        return nodes[cur].val;\n    }\n    int set(int root, int\
    \ p, const T& x) {\n        assert(0 <= p && p < _n);\n        int res = copy(root);\n\
    \        int cur = res, l = 0, r = _n;\n        while (r - l > 1) {\n        \
    \    int mid = (l + r) / 2;\n            if (p < mid) {\n                int nxt\
    \ = copy(nodes[cur].l);\n                nodes[cur].l = nxt;\n               \
    \ cur = nxt, r = mid;\n            } else {\n                int nxt = copy(nodes[cur].r);\n\
    \                nodes[cur].r = nxt;\n                cur = nxt, l = mid;\n  \
    \          }\n        }\n        nodes[cur].val = x;\n        return res;\n  \
    \  }\n\nprivate:\n    struct node {\n        int l, r;\n        T val;\n    };\n\
    \    int _n;\n    std::vector<node> nodes;\n    int copy(int v) {\n        nodes.push_back(nodes[v]);\n\
    \        return int(nodes.size()) - 1;\n    }\n    int build(const std::vector<T>&\
    \ v, int l, int r) {\n        if (r - l == 1) {\n            nodes.push_back({-1,\
    \ -1, v[l]});\n            return int(nodes.size()) - 1;\n        }\n        int\
    \ mid = (l + r) / 2;\n        int res = int(nodes.size());\n        nodes.push_back({-1,\
    \ -1, T()});\n        int lc = build(v, l, mid);\n        int rc = build(v, mid,\
    \ r);\n        nodes[res].l = lc, nodes[res].r = rc;\n        return res;\n  \
    \  }\n};\n#line 6 \"test/library-checker/persistent_unionfind.test.cpp\"\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    persistent_array<int>\
    \ a(std::vector<int>(n, -1));\n    auto leader = [&](int root, int v) {\n    \
    \    while (a.get(root, v) >= 0) v = a.get(root, v);\n        return v;\n    };\n\
    \    std::vector<int> roots(q + 1);\n    roots[0] = 0;\n    for (int i = 0; i\
    \ < q; i++) {\n        int t, k, u, v;\n        std::cin >> t >> k >> u >> v;\n\
    \        int root = roots[k + 1];\n        if (t == 0) {\n            u = leader(root,\
    \ u), v = leader(root, v);\n            if (u != v) {\n                int su\
    \ = -a.get(root, u), sv = -a.get(root, v);\n                if (su < sv) std::swap(u,\
    \ v), std::swap(su, sv);\n                root = a.set(root, u, -(su + sv));\n\
    \                root = a.set(root, v, u);\n            }\n            roots[i\
    \ + 1] = root;\n        } else {\n            roots[i + 1] = root;\n         \
    \   std::cout << (leader(root, u) == leader(root, v) ? 1 : 0) << '\\n';\n    \
    \    }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include <iostream>\n#include <vector>\n\n#include \"datastructure/persistent_array.hpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    persistent_array<int>\
    \ a(std::vector<int>(n, -1));\n    auto leader = [&](int root, int v) {\n    \
    \    while (a.get(root, v) >= 0) v = a.get(root, v);\n        return v;\n    };\n\
    \    std::vector<int> roots(q + 1);\n    roots[0] = 0;\n    for (int i = 0; i\
    \ < q; i++) {\n        int t, k, u, v;\n        std::cin >> t >> k >> u >> v;\n\
    \        int root = roots[k + 1];\n        if (t == 0) {\n            u = leader(root,\
    \ u), v = leader(root, v);\n            if (u != v) {\n                int su\
    \ = -a.get(root, u), sv = -a.get(root, v);\n                if (su < sv) std::swap(u,\
    \ v), std::swap(su, sv);\n                root = a.set(root, u, -(su + sv));\n\
    \                root = a.set(root, v, u);\n            }\n            roots[i\
    \ + 1] = root;\n        } else {\n            roots[i + 1] = root;\n         \
    \   std::cout << (leader(root, u) == leader(root, v) ? 1 : 0) << '\\n';\n    \
    \    }\n    }\n}\n"
  dependsOn:
  - datastructure/persistent_array.hpp
  isVerificationFile: true
  path: test/library-checker/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/persistent_unionfind.test.cpp
- /verify/test/library-checker/persistent_unionfind.test.cpp.html
title: test/library-checker/persistent_unionfind.test.cpp
---
