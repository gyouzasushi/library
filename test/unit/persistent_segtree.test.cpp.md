---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_add.hpp
    title: 'Monoid: Add'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_min.hpp
    title: 'Monoid: Min'
  - icon: ':heavy_check_mark:'
    path: datastructure/persistent_segtree.hpp
    title: Persistent Segment Tree
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
  bundledCode: "#line 1 \"test/unit/persistent_segtree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <chrono>\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\n#line 2 \"algebra/monoid_add.hpp\"\ntemplate\
    \ <class T>\nstruct monoid_add {\n    using S = T;\n    static S op(S a, S b)\
    \ {\n        return a + b;\n    }\n    static S e() {\n        return T(0);\n\
    \    }\n};\n#line 3 \"algebra/monoid_min.hpp\"\n#include <limits>\ntemplate <class\
    \ T>\nstruct monoid_min {\n    using S = T;\n    static S op(S a, S b) {\n   \
    \     return std::min(a, b);\n    }\n    static S e() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 4 \"datastructure/persistent_segtree.hpp\"\n\n#line 2 \"algebra/concept.hpp\"\
    \n#include <concepts>\ntemplate <class M>\nconcept semigroup = requires(typename\
    \ M::S a, typename M::S b) {\n    { M::op(a, b) } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class M>\nconcept monoid = semigroup<M> && requires {\n    { M::e()\
    \ } -> std::same_as<typename M::S>;\n};\ntemplate <class G>\nconcept group = monoid<G>\
    \ && requires(typename G::S a) {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n\
    };\ntemplate <class A>\nconcept action = requires(typename A::F f, typename A::F\
    \ g) {\n    { A::composition(f, g) } -> std::same_as<typename A::F>;\n    { A::id()\
    \ } -> std::same_as<typename A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n\
    };\ntemplate <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\ntemplate <class\
    \ A>\nconcept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x)\
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n#line 6 \"datastructure/persistent_segtree.hpp\"\
    \ntemplate <monoid M> struct persistent_segtree {\npublic:\n    using S = typename\
    \ M::S;\n    explicit persistent_segtree(int n) : persistent_segtree(std::vector<S>(n,\
    \ M::e())) {\n    }\n    explicit persistent_segtree(const std::vector<S>& v)\
    \ : _n(int(v.size())) {\n        nodes.reserve(2 * _n);\n        if (_n > 0) build(v,\
    \ 0, _n);\n    }\n    int size() const {\n        return _n;\n    }\n    S get(int\
    \ root, int p) const {\n        assert(0 <= p && p < _n);\n        int cur = root,\
    \ l = 0, r = _n;\n        while (r - l > 1) {\n            int mid = (l + r) /\
    \ 2;\n            if (p < mid) {\n                cur = nodes[cur].l, r = mid;\n\
    \            } else {\n                cur = nodes[cur].r, l = mid;\n        \
    \    }\n        }\n        return nodes[cur].val;\n    }\n    int set(int root,\
    \ int p, const S& x) {\n        assert(0 <= p && p < _n);\n        int res = copy(root);\n\
    \        int cur = res, l = 0, r = _n;\n        path.clear();\n        while (r\
    \ - l > 1) {\n            path.push_back(cur);\n            int mid = (l + r)\
    \ / 2;\n            if (p < mid) {\n                int nxt = copy(nodes[cur].l);\n\
    \                nodes[cur].l = nxt;\n                cur = nxt, r = mid;\n  \
    \          } else {\n                int nxt = copy(nodes[cur].r);\n         \
    \       nodes[cur].r = nxt;\n                cur = nxt, l = mid;\n           \
    \ }\n        }\n        nodes[cur].val = x;\n        for (int i = int(path.size())\
    \ - 1; i >= 0; i--) {\n            node& v = nodes[path[i]];\n            v.val\
    \ = M::op(nodes[v.l].val, nodes[v.r].val);\n        }\n        return res;\n \
    \   }\n    S prod(int root, int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        return prod(root, 0, _n, l, r);\n    }\n    S all_prod(int\
    \ root) const {\n        return _n == 0 ? M::e() : nodes[root].val;\n    }\n\n\
    private:\n    struct node {\n        int l, r;\n        S val;\n    };\n    int\
    \ _n;\n    std::vector<node> nodes;\n    std::vector<int> path;\n    int copy(int\
    \ v) {\n        nodes.push_back(nodes[v]);\n        return int(nodes.size()) -\
    \ 1;\n    }\n    int build(const std::vector<S>& v, int l, int r) {\n        if\
    \ (r - l == 1) {\n            nodes.push_back({-1, -1, v[l]});\n            return\
    \ int(nodes.size()) - 1;\n        }\n        int mid = (l + r) / 2;\n        int\
    \ res = int(nodes.size());\n        nodes.push_back({-1, -1, M::e()});\n     \
    \   int lc = build(v, l, mid);\n        int rc = build(v, mid, r);\n        nodes[res].l\
    \ = lc, nodes[res].r = rc;\n        nodes[res].val = M::op(nodes[lc].val, nodes[rc].val);\n\
    \        return res;\n    }\n    S prod(int cur, int nl, int nr, int l, int r)\
    \ const {\n        if (r <= nl || nr <= l) return M::e();\n        if (l <= nl\
    \ && nr <= r) return nodes[cur].val;\n        int mid = (nl + nr) / 2;\n     \
    \   return M::op(prod(nodes[cur].l, nl, mid, l, r), prod(nodes[cur].r, mid, nr,\
    \ l, r));\n    }\n};\n#line 12 \"test/unit/persistent_segtree.test.cpp\"\ntemplate\
    \ <class M, class Naive>\nvoid stress(std::mt19937_64& rng, const Naive& naive)\
    \ {\n    using S = typename M::S;\n    for (int iter = 0; iter < 200; iter++)\
    \ {\n        int n = 1 + rng() % 20;\n        std::vector<S> init(n);\n      \
    \  for (auto& x : init) x = S(rng() % 100);\n        persistent_segtree<M> seg(init);\n\
    \        std::vector<std::vector<S>> versions{init};\n        std::vector<int>\
    \ roots{0};\n        assert(seg.size() == n);\n        for (int t = 0; t < 60;\
    \ t++) {\n            int k = rng() % roots.size();\n            int p = rng()\
    \ % n;\n            S x = S(rng() % 100);\n            roots.push_back(seg.set(roots[k],\
    \ p, x));\n            std::vector<S> v = versions[k];\n            v[p] = x;\n\
    \            versions.push_back(v);\n            int c = rng() % roots.size();\n\
    \            for (int i = 0; i < n; i++) assert(seg.get(roots[c], i) == versions[c][i]);\n\
    \            for (int l = 0; l <= n; l++) {\n                for (int r = l; r\
    \ <= n; r++) {\n                    S expect = M::e();\n                    for\
    \ (int i = l; i < r; i++) expect = naive(expect, versions[c][i]);\n          \
    \          assert(seg.prod(roots[c], l, r) == expect);\n                }\n  \
    \          }\n            assert(seg.all_prod(roots[c]) == seg.prod(roots[c],\
    \ 0, n));\n        }\n    }\n}\nint main() {\n    std::mt19937_64 rng(20261027);\n\
    \    stress<monoid_add<long long>>(rng, [](long long a, long long b) { return\
    \ a + b; });\n    stress<monoid_min<int>>(rng, [](int a, int b) { return std::min(a,\
    \ b); });\n    {\n        persistent_segtree<monoid_add<int>> seg(0);\n      \
    \  assert(seg.all_prod(0) == 0 && seg.prod(0, 0, 0) == 0);\n        persistent_segtree<monoid_add<int>>\
    \ seg1(3);\n        int r = seg1.set(0, 1, 5);\n        assert(seg1.all_prod(0)\
    \ == 0 && seg1.all_prod(r) == 5 && seg1.prod(r, 1, 2) == 5);\n    }\n    {\n \
    \       int n = 200000, q = 200000;\n        auto start = std::chrono::steady_clock::now();\n\
    \        persistent_segtree<monoid_add<long long>> seg(n);\n        std::vector<int>\
    \ roots{0};\n        long long acc = 0;\n        for (int i = 0; i < q; i++) {\n\
    \            int k = rng() % roots.size();\n            roots.push_back(seg.set(roots[k],\
    \ rng() % n, rng() % 1000));\n            int l = rng() % n, r = rng() % n;\n\
    \            if (l > r) std::swap(l, r);\n            acc += seg.prod(roots[rng()\
    \ % roots.size()], l, r + 1);\n        }\n        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf n=q=\" << n << \": \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <cassert>\n#include <chrono>\n#include <iostream>\n\
    #include <random>\n#include <vector>\n\n#include \"algebra/monoid_add.hpp\"\n\
    #include \"algebra/monoid_min.hpp\"\n#include \"datastructure/persistent_segtree.hpp\"\
    \ntemplate <class M, class Naive>\nvoid stress(std::mt19937_64& rng, const Naive&\
    \ naive) {\n    using S = typename M::S;\n    for (int iter = 0; iter < 200; iter++)\
    \ {\n        int n = 1 + rng() % 20;\n        std::vector<S> init(n);\n      \
    \  for (auto& x : init) x = S(rng() % 100);\n        persistent_segtree<M> seg(init);\n\
    \        std::vector<std::vector<S>> versions{init};\n        std::vector<int>\
    \ roots{0};\n        assert(seg.size() == n);\n        for (int t = 0; t < 60;\
    \ t++) {\n            int k = rng() % roots.size();\n            int p = rng()\
    \ % n;\n            S x = S(rng() % 100);\n            roots.push_back(seg.set(roots[k],\
    \ p, x));\n            std::vector<S> v = versions[k];\n            v[p] = x;\n\
    \            versions.push_back(v);\n            int c = rng() % roots.size();\n\
    \            for (int i = 0; i < n; i++) assert(seg.get(roots[c], i) == versions[c][i]);\n\
    \            for (int l = 0; l <= n; l++) {\n                for (int r = l; r\
    \ <= n; r++) {\n                    S expect = M::e();\n                    for\
    \ (int i = l; i < r; i++) expect = naive(expect, versions[c][i]);\n          \
    \          assert(seg.prod(roots[c], l, r) == expect);\n                }\n  \
    \          }\n            assert(seg.all_prod(roots[c]) == seg.prod(roots[c],\
    \ 0, n));\n        }\n    }\n}\nint main() {\n    std::mt19937_64 rng(20261027);\n\
    \    stress<monoid_add<long long>>(rng, [](long long a, long long b) { return\
    \ a + b; });\n    stress<monoid_min<int>>(rng, [](int a, int b) { return std::min(a,\
    \ b); });\n    {\n        persistent_segtree<monoid_add<int>> seg(0);\n      \
    \  assert(seg.all_prod(0) == 0 && seg.prod(0, 0, 0) == 0);\n        persistent_segtree<monoid_add<int>>\
    \ seg1(3);\n        int r = seg1.set(0, 1, 5);\n        assert(seg1.all_prod(0)\
    \ == 0 && seg1.all_prod(r) == 5 && seg1.prod(r, 1, 2) == 5);\n    }\n    {\n \
    \       int n = 200000, q = 200000;\n        auto start = std::chrono::steady_clock::now();\n\
    \        persistent_segtree<monoid_add<long long>> seg(n);\n        std::vector<int>\
    \ roots{0};\n        long long acc = 0;\n        for (int i = 0; i < q; i++) {\n\
    \            int k = rng() % roots.size();\n            roots.push_back(seg.set(roots[k],\
    \ rng() % n, rng() % 1000));\n            int l = rng() % n, r = rng() % n;\n\
    \            if (l > r) std::swap(l, r);\n            acc += seg.prod(roots[rng()\
    \ % roots.size()], l, r + 1);\n        }\n        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()\
    \ - start).count();\n        std::cerr << \"perf n=q=\" << n << \": \" << ms <<\
    \ \" ms (\" << acc % 1000 << \")\\n\";\n    }\n    std::cout << \"Hello World\\\
    n\";\n}\n"
  dependsOn:
  - algebra/monoid_add.hpp
  - algebra/monoid_min.hpp
  - datastructure/persistent_segtree.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/unit/persistent_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/persistent_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unit/persistent_segtree.test.cpp
- /verify/test/unit/persistent_segtree.test.cpp.html
title: test/unit/persistent_segtree.test.cpp
---
