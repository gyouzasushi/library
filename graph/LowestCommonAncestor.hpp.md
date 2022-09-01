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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: plus_minus_one_range_minimum.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\n#include \"plus_minus_one_range_minimum.hpp\"\
    \nstruct LowestCommonAncestor {\npublic:\n    LowestCommonAncestor() {\n    }\n\
    \    LowestCommonAncestor(int n, int root = 0)\n        : _n(n), _root(root),\
    \ g(n), id(n), vs(2 * n - 1), dep(2 * n - 1) {\n    }\n    void add_edge(int from,\
    \ int to) {\n        assert(0 <= from && from < _n);\n        assert(0 <= to &&\
    \ to < _n);\n        g[from].push_back(to);\n        g[to].push_back(from);\n\
    \    }\n    void build() {\n        int k = 0;\n        auto dfs = [&](auto dfs,\
    \ int pos, int pre, int d) -> void {\n            id[pos] = k;\n            vs[k]\
    \ = pos;\n            dep[k++] = d;\n            for (int nxt : g[pos]) {\n  \
    \              if (nxt == pre) continue;\n                dfs(dfs, nxt, pos, d\
    \ + 1);\n                vs[k] = pos;\n                dep[k++] = d;\n       \
    \     }\n        };\n        dfs(dfs, _root, -1, 0);\n        rmq.init(dep);\n\
    \    }\n\n    int get(int u, int v) {\n        int l = std::min(id[u], id[v]);\n\
    \        int r = std::max(id[u], id[v]) + 1;\n        return vs[rmq.prod(l, r)];\n\
    \    }\n    int get(int u, int v, int r) {\n        return get(r, u) ^ get(u,\
    \ v) ^ get(v, r);\n    }\n    int depth(int u) {\n        return dep[id[u]];\n\
    \    }\n    int dist(int u, int v) {\n        return depth(u) + depth(v) - 2 *\
    \ depth(get(u, v));\n    }\n\nprivate:\n    int _n, _root;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> id, vs, dep;\n    PlusMinusOneRMQ rmq;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/graph/LowestCommonAncestor.hpp
- /library/graph/LowestCommonAncestor.hpp.html
title: graph/LowestCommonAncestor.hpp
---
