---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/rollback_dsu.hpp
    title: Rollback DSU
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unit/rollback_dsu.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 1 \"atcoder/dsu.hpp\"\n\n\n\n#include <algorithm>\n#line 7 \"atcoder/dsu.hpp\"\
    \n\nnamespace atcoder {\n\n// Implement (union by size) + (path compression)\n\
    // Reference:\n// Zvi Galil and Giuseppe F. Italiano,\n// Data structures and\
    \ algorithms for disjoint set union problems\nstruct dsu {\n  public:\n    dsu()\
    \ : _n(0) {}\n    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n  \
    \  int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        return _leader(a);\n    }\n\n    int size(int a) {\n       \
    \ assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\
    \n    std::vector<std::vector<int>> groups() {\n        std::vector<int> leader_buf(_n),\
    \ group_size(_n);\n        for (int i = 0; i < _n; i++) {\n            leader_buf[i]\
    \ = leader(i);\n            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n\n    int _leader(int a) {\n \
    \       if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = _leader(parent_or_size[a]);\n    }\n};\n\n}  // namespace atcoder\n\n\n#line\
    \ 4 \"datastructure/rollback_dsu.hpp\"\n#include <utility>\n#line 6 \"datastructure/rollback_dsu.hpp\"\
    \nstruct rollback_dsu {\npublic:\n    rollback_dsu() : rollback_dsu(0) {\n   \
    \ }\n    explicit rollback_dsu(int n) : _n(n), parent_or_size(n, -1) {\n    }\n\
    \    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) {\n            history.emplace_back(-1, -1);\n            return x;\n   \
    \     }\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n\
    \        history.emplace_back(y, parent_or_size[y]);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n    void undo() {\n        assert(!history.empty());\n        auto [y,\
    \ s] = history.back();\n        history.pop_back();\n        if (y == -1) return;\n\
    \        parent_or_size[parent_or_size[y]] -= s;\n        parent_or_size[y] =\
    \ s;\n    }\n    int time() const {\n        return int(history.size());\n   \
    \ }\n    void rollback(int t) {\n        assert(0 <= t && t <= time());\n    \
    \    while (time() > t) undo();\n    }\n    bool same(int a, int b) const {\n\
    \        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n      \
    \  return leader(a) == leader(b);\n    }\n    int leader(int a) const {\n    \
    \    assert(0 <= a && a < _n);\n        while (parent_or_size[a] >= 0) a = parent_or_size[a];\n\
    \        return a;\n    }\n    int size(int a) const {\n        assert(0 <= a\
    \ && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<int> leader_buf(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n\
    \            group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n\
    \        for (int i = 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n  \
    \      result.erase(std::remove_if(result.begin(), result.end(),\n           \
    \                         [&](const std::vector<int>& v) { return v.empty(); }),\n\
    \                     result.end());\n        return result;\n    }\n\nprivate:\n\
    \    int _n;\n    std::vector<int> parent_or_size;\n    std::vector<std::pair<int,\
    \ int>> history;  // (attached leader, its old parent_or_size)\n};\n#line 9 \"\
    test/unit/rollback_dsu.test.cpp\"\n\nint main() {\n    std::mt19937 rng(99);\n\
    \    for (int it = 0; it < 300; it++) {\n        int n = 1 + rng() % 10;\n   \
    \     rollback_dsu d(n);\n        std::vector<std::pair<int, int>> merged;  //\
    \ current edge list\n        std::vector<std::pair<int, int>> stack_sizes;\n \
    \       auto check = [&] {\n            atcoder::dsu ref(n);\n            for\
    \ (auto [a, b] : merged) ref.merge(a, b);\n            for (int a = 0; a < n;\
    \ a++) {\n                for (int b = 0; b < n; b++) assert(d.same(a, b) == ref.same(a,\
    \ b));\n                assert(d.size(a) == ref.size(a));\n            }\n   \
    \         assert(d.groups() == ref.groups());\n            assert(d.time() ==\
    \ int(merged.size()));\n        };\n        for (int q = 0; q < 60; q++) {\n \
    \           int op = rng() % 3;\n            if (op == 0 || merged.empty()) {\n\
    \                int a = rng() % n, b = rng() % n;\n                int l = d.merge(a,\
    \ b);\n                merged.emplace_back(a, b);\n                assert(l ==\
    \ d.leader(a) && l == d.leader(b));\n            } else if (op == 1) {\n     \
    \           d.undo();\n                merged.pop_back();\n            } else\
    \ {\n                int t = rng() % (merged.size() + 1);\n                d.rollback(t);\n\
    \                merged.resize(t);\n            }\n            check();\n    \
    \    }\n    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"atcoder/dsu\"\n#include \"datastructure/rollback_dsu.hpp\"\n\nint\
    \ main() {\n    std::mt19937 rng(99);\n    for (int it = 0; it < 300; it++) {\n\
    \        int n = 1 + rng() % 10;\n        rollback_dsu d(n);\n        std::vector<std::pair<int,\
    \ int>> merged;  // current edge list\n        std::vector<std::pair<int, int>>\
    \ stack_sizes;\n        auto check = [&] {\n            atcoder::dsu ref(n);\n\
    \            for (auto [a, b] : merged) ref.merge(a, b);\n            for (int\
    \ a = 0; a < n; a++) {\n                for (int b = 0; b < n; b++) assert(d.same(a,\
    \ b) == ref.same(a, b));\n                assert(d.size(a) == ref.size(a));\n\
    \            }\n            assert(d.groups() == ref.groups());\n            assert(d.time()\
    \ == int(merged.size()));\n        };\n        for (int q = 0; q < 60; q++) {\n\
    \            int op = rng() % 3;\n            if (op == 0 || merged.empty()) {\n\
    \                int a = rng() % n, b = rng() % n;\n                int l = d.merge(a,\
    \ b);\n                merged.emplace_back(a, b);\n                assert(l ==\
    \ d.leader(a) && l == d.leader(b));\n            } else if (op == 1) {\n     \
    \           d.undo();\n                merged.pop_back();\n            } else\
    \ {\n                int t = rng() % (merged.size() + 1);\n                d.rollback(t);\n\
    \                merged.resize(t);\n            }\n            check();\n    \
    \    }\n    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n\
    }\n"
  dependsOn:
  - datastructure/rollback_dsu.hpp
  isVerificationFile: true
  path: test/unit/rollback_dsu.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 01:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/rollback_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/unit/rollback_dsu.test.cpp
- /verify/test/unit/rollback_dsu.test.cpp.html
title: test/unit/rollback_dsu.test.cpp
---
