---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: datastructure/unionfind.hpp
    title: datastructure/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ \"graph/manhattan_mst.hpp\"\n#include <cassert>\n#line 5 \"graph/manhattan_mst.hpp\"\
    \n#include <limits>\n#include <map>\n#include <numeric>\n#line 9 \"graph/manhattan_mst.hpp\"\
    \n\n#line 4 \"datastructure/segment_tree.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct SegmentTree {\npublic:\n    SegmentTree() : SegmentTree(0)\
    \ {\n    }\n    SegmentTree(int n) : SegmentTree(std::vector<S>(n, e())) {\n \
    \   }\n    SegmentTree(const std::vector<S>& v) : _n(int(v.size())) {\n      \
    \  log = ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() {\n        return d[1];\n    }\n\n    template <bool (*f)(S)>\n \
    \   int max_right(int l) {\n        return max_right(l, [](S x) { return f(x);\
    \ });\n    }\n    template <class F>\n    int max_right(int l, F f) {\n      \
    \  assert(0 <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return\
    \ _n;\n        l += size;\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    l = (2 * l);\n                    if\
    \ (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n          \
    \              l++;\n                    }\n                }\n              \
    \  return l - size;\n            }\n            sm = op(sm, d[l]);\n         \
    \   l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\n    template\
    \ <bool (*f)(S)>\n    int min_left(int r) {\n        return min_left(r, [](S x)\
    \ { return f(x); });\n    }\n    template <class F>\n    int min_left(int r, F\
    \ f) {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if\
    \ (r == 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n\
    \            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n           \
    \ if (!f(op(d[r], sm))) {\n                while (r < size) {\n              \
    \      r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n        \
    \                sm = op(d[r], sm);\n                        r--;\n          \
    \          }\n                }\n                return r + 1 - size;\n      \
    \      }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n \
    \       return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    int ceil_pow2(int n) {\n        int x = 0;\n        while ((1U << x)\
    \ < (unsigned int)(n)) x++;\n        return x;\n    }\n    void update(int k)\
    \ {\n        d[k] = op(d[2 * k], d[2 * k + 1]);\n    }\n};\n#line 11 \"graph/manhattan_mst.hpp\"\
    \ntemplate <typename T>\nstruct manhattan_mst_S {\n    T val;\n    int id;\n};\n\
    template <typename T>\nmanhattan_mst_S<T> manhattan_mst_op(manhattan_mst_S<T>\
    \ a,\n                                    manhattan_mst_S<T> b) {\n    return\
    \ a.val < b.val ? a : b;\n}\ntemplate <typename T>\nmanhattan_mst_S<T> manhattan_mst_e()\
    \ {\n    return {std::numeric_limits<T>::max(), -1};\n}\ntemplate <typename T>\n\
    std::vector<std::tuple<int, int, T>> manhattan_mst(std::vector<T> x,\n       \
    \                                            std::vector<T> y) {\n    int n =\
    \ x.size();\n    assert(int(x.size()) == n && int(y.size()) == n);\n    std::vector<int>\
    \ id(n);\n    std::iota(id.begin(), id.end(), 0);\n    std::vector<int> y_id(n);\n\
    \    std::vector<std::tuple<int, int, T>> ret;\n    for (int a = 0; a < 2; a++)\
    \ {\n        for (int b = 0; b < 2; b++) {\n            for (int c = 0; c < 2;\
    \ c++) {\n                sort(id.begin(), id.end(), [&](int i, int j) {\n   \
    \                 if (y[i] - x[i] == y[j] - x[j] && y[i] == y[j])\n          \
    \              return i < j;\n                    if (y[i] - x[i] == y[j] - x[j])\
    \ return y[i] > y[j];\n                    return y[i] - x[i] < y[j] - x[j];\n\
    \                });\n                std::vector<T> _y = y;\n               \
    \ std::sort(_y.begin(), _y.end());\n                for (int i = 0; i < n; i++)\
    \ {\n                    y_id[i] = std::lower_bound(_y.begin(), _y.end(), y[i])\
    \ -\n                              _y.begin();\n                }\n          \
    \      SegmentTree<manhattan_mst_S<T>, manhattan_mst_op<T>,\n                \
    \            manhattan_mst_e<T>>\n                    segt(n);\n             \
    \   for (int i : id) {\n                    manhattan_mst_S<T> p = segt.prod(y_id[i],\
    \ n);\n                    if (p.id != -1) {\n                        ret.emplace_back(i,\
    \ p.id, p.val - (x[i] + y[i]));\n                    }\n                    segt.set(y_id[i],\
    \ {x[i] + y[i], i});\n                }\n                std::swap(x, y);\n  \
    \          }\n            for (T &x : x) x = -x;\n        }\n        for (T &y\
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
  - datastructure/segment_tree.hpp
  isVerificationFile: true
  path: test/library-checker/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2023-01-10 15:20:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/manhattanmst.test.cpp
- /verify/test/library-checker/manhattanmst.test.cpp.html
title: test/library-checker/manhattanmst.test.cpp
---
