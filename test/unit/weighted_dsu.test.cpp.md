---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/concept.hpp
    title: 'Algebra: Concept'
  - icon: ':heavy_check_mark:'
    path: algebra/group_add.hpp
    title: 'Group: Add'
  - icon: ':heavy_check_mark:'
    path: algebra/group_xor.hpp
    title: 'Group: XOR'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_add.hpp
    title: 'Monoid: Add'
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_xor.hpp
    title: 'Monoid: XOR'
  - icon: ':heavy_check_mark:'
    path: datastructure/weighted_dsu.hpp
    title: Weighted DSU
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
  bundledCode: "#line 1 \"test/unit/weighted_dsu.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <optional>\n#include <random>\n\
    #include <vector>\n\n#line 2 \"algebra/monoid_add.hpp\"\ntemplate <class T>\n\
    struct monoid_add {\n    using S = T;\n    static S op(S a, S b) {\n        return\
    \ a + b;\n    }\n    static S e() {\n        return T(0);\n    }\n};\n#line 3\
    \ \"algebra/group_add.hpp\"\ntemplate <class T>\nstruct group_add : monoid_add<T>\
    \ {\n    static T inv(T a) {\n        return -a;\n    }\n};\n#line 2 \"algebra/monoid_xor.hpp\"\
    \ntemplate <class T>\nstruct monoid_xor {\n    using S = T;\n    static S op(S\
    \ a, S b) {\n        return a ^ b;\n    }\n    static S e() {\n        return\
    \ T(0);\n    }\n};\n#line 3 \"algebra/group_xor.hpp\"\ntemplate <class T>\nstruct\
    \ group_xor : monoid_xor<T> {\n    static T inv(T a) {\n        return a;\n  \
    \  }\n};\n#line 2 \"datastructure/weighted_dsu.hpp\"\n#include <algorithm>\n#line\
    \ 4 \"datastructure/weighted_dsu.hpp\"\n#include <utility>\n#line 6 \"datastructure/weighted_dsu.hpp\"\
    \n\n#line 2 \"algebra/concept.hpp\"\n#include <concepts>\ntemplate <class M>\n\
    concept semigroup = requires(typename M::S a, typename M::S b) {\n    { M::op(a,\
    \ b) } -> std::same_as<typename M::S>;\n};\ntemplate <class M>\nconcept monoid\
    \ = semigroup<M> && requires {\n    { M::e() } -> std::same_as<typename M::S>;\n\
    };\ntemplate <class G>\nconcept group = monoid<G> && requires(typename G::S a)\
    \ {\n    { G::inv(a) } -> std::same_as<typename G::S>;\n};\ntemplate <class A>\n\
    concept action = requires(typename A::F f, typename A::F g) {\n    { A::composition(f,\
    \ g) } -> std::same_as<typename A::F>;\n    { A::id() } -> std::same_as<typename\
    \ A::F>;\n    { A::composition_commutative } -> std::convertible_to<bool>;\n};\n\
    template <class A>\nconcept acted_monoid = monoid<A> && action<A> && requires(typename\
    \ A::S x, typename A::F f) {\n    { A::mapping(f, x) } -> std::same_as<typename\
    \ A::S>;\n};\ntemplate <class R>\nconcept semiring = requires(typename R::S a,\
    \ typename R::S b) {\n    { R::add(a, b) } -> std::same_as<typename R::S>;\n \
    \   { R::zero() } -> std::same_as<typename R::S>;\n    { R::mul(a, b) } -> std::same_as<typename\
    \ R::S>;\n    { R::one() } -> std::same_as<typename R::S>;\n};\ntemplate <class\
    \ A>\nconcept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x)\
    \ {\n    { x.fail } -> std::convertible_to<bool>;\n};\n#line 8 \"datastructure/weighted_dsu.hpp\"\
    \n\n// potential p[v] of each vertex; diff(a, b) = op(inv(p[a]), p[b])\ntemplate\
    \ <group G> struct weighted_dsu {\npublic:\n    using S = typename G::S;\n   \
    \ weighted_dsu() : weighted_dsu(0) {\n    }\n    explicit weighted_dsu(int n)\
    \ : _n(n), parent_or_size(n, -1), pot(n, G::e()) {\n    }\n    // make diff(a,\
    \ b) == w; returns false if it contradicts the existing constraints\n    bool\
    \ merge(int a, int b, S w) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) return diff(a, b) == w;\n        // p[y] relative to x: op(inv(p[a]), op(p[y],\
    \ p[b])) == w\n        S py = G::op(G::op(pot[a], w), G::inv(pot[b]));\n     \
    \   if (-parent_or_size[x] < -parent_or_size[y]) {\n            std::swap(x, y);\n\
    \            py = G::inv(py);\n        }\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        pot[y] = py;\n        return true;\n\
    \    }\n    S diff(int a, int b) {\n        assert(same(a, b));\n        return\
    \ G::op(G::inv(pot[a]), pot[b]);\n    }\n    bool same(int a, int b) {\n     \
    \   assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return\
    \ leader(a) == leader(b);\n    }\n    int leader(int a) {\n        assert(0 <=\
    \ a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n        int p =\
    \ parent_or_size[a];\n        int r = leader(p);\n        if (p != r) pot[a] =\
    \ G::op(pot[p], pot[a]);\n        return parent_or_size[a] = r;\n    }\n    int\
    \ size(int a) {\n        assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ leader_buf(_n), group_size(_n);\n        for (int i = 0; i < _n; i++) {\n  \
    \          leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) result[i].reserve(group_size[i]);\n        for (int i =\
    \ 0; i < _n; i++) result[leader_buf[i]].push_back(i);\n        result.erase(std::ranges::remove_if(result,\
    \ [](const std::vector<int>& v) { return v.empty(); }).begin(),\n            \
    \         result.end());\n        return result;\n    }\n\nprivate:\n    int _n;\n\
    \    std::vector<int> parent_or_size;\n    std::vector<S> pot;  // relative to\
    \ parent\n};\n#line 11 \"test/unit/weighted_dsu.test.cpp\"\n\n// brute force:\
    \ potentials via BFS over accepted constraints\ntemplate <class G> struct brute\
    \ {\n    using S = typename G::S;\n    int n;\n    std::vector<std::vector<std::pair<int,\
    \ S>>> g;  // (to, diff(from, to))\n    explicit brute(int n) : n(n), g(n) {\n\
    \    }\n    std::vector<std::optional<S>> potentials(int s) {\n        std::vector<std::optional<S>>\
    \ p(n);\n        p[s] = G::e();\n        std::vector<int> st = {s};\n        while\
    \ (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            for (auto [u, w] : g[v]) {\n                if (p[u]) continue;\n\
    \                p[u] = G::op(*p[v], w);\n                st.push_back(u);\n \
    \           }\n        }\n        return p;\n    }\n    bool merge(int a, int\
    \ b, S w) {\n        auto p = potentials(a);\n        if (p[b]) return *p[b] ==\
    \ w;\n        g[a].emplace_back(b, w);\n        g[b].emplace_back(a, G::inv(w));\n\
    \        return true;\n    }\n    std::optional<S> diff(int a, int b) {\n    \
    \    return potentials(a)[b];\n    }\n};\n\ntemplate <class G> void run(std::mt19937&\
    \ rng, auto gen) {\n    for (int it = 0; it < 300; it++) {\n        int n = 1\
    \ + rng() % 8;\n        weighted_dsu<G> d(n);\n        brute<G> b(n);\n      \
    \  for (int q = 0; q < 30; q++) {\n            int x = rng() % n, y = rng() %\
    \ n;\n            if (rng() % 2) {\n                auto w = gen();\n        \
    \        assert(d.merge(x, y, w) == b.merge(x, y, w));\n            } else {\n\
    \                auto r = b.diff(x, y);\n                assert(d.same(x, y) ==\
    \ r.has_value());\n                if (r) assert(d.diff(x, y) == *r);\n      \
    \      }\n        }\n        auto groups = d.groups();\n        int total = 0;\n\
    \        for (auto& grp : groups) {\n            for (int v : grp) assert(d.leader(v)\
    \ == d.leader(grp[0])), assert(d.size(v) == int(grp.size()));\n            total\
    \ += int(grp.size());\n        }\n        assert(total == n);\n    }\n}\n\n//\
    \ non-commutative: affine maps x -> a x + b over a prime field (a != 0)\nstruct\
    \ group_affine {\n    static constexpr long long p = 1000003;\n    struct S {\n\
    \        long long a, b;\n        bool operator==(const S&) const = default;\n\
    \    };\n    static long long pw(long long a, long long n) {\n        long long\
    \ r = 1;\n        a %= p;\n        while (n) {\n            if (n & 1) r = r *\
    \ a % p;\n            a = a * a % p;\n            n >>= 1;\n        }\n      \
    \  return r;\n    }\n    static S op(S f, S g) {  // f after g: f(g(x))\n    \
    \    return {f.a * g.a % p, (f.a * g.b + f.b) % p};\n    }\n    static S e() {\n\
    \        return {1, 0};\n    }\n    static S inv(S f) {\n        long long ia\
    \ = pw(f.a, p - 2);\n        return {ia, (p - ia * f.b % p) % p};\n    }\n};\n\
    \nint main() {\n    std::mt19937 rng(2024);\n    run<group_add<long long>>(rng,\
    \ [&] { return (long long)(rng() % 21) - 10; });\n    run<group_xor<int>>(rng,\
    \ [&] { return int(rng() % 16); });\n    run<group_affine>(rng, [&] { return group_affine::S{1\
    \ + (long long)(rng() % 5), (long long)(rng() % 7)}; });\n    // contradiction\
    \ leaves the structure unchanged\n    {\n        weighted_dsu<group_add<long long>>\
    \ d(3);\n        assert(d.merge(0, 1, 5));\n        assert(d.merge(1, 2, 7));\n\
    \        assert(d.diff(0, 2) == 12 && d.diff(2, 0) == -12);\n        assert(!d.merge(0,\
    \ 2, 13));\n        assert(d.merge(0, 2, 12));\n        assert(d.size(0) == 3);\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <optional>\n#include <random>\n\
    #include <vector>\n\n#include \"algebra/group_add.hpp\"\n#include \"algebra/group_xor.hpp\"\
    \n#include \"datastructure/weighted_dsu.hpp\"\n\n// brute force: potentials via\
    \ BFS over accepted constraints\ntemplate <class G> struct brute {\n    using\
    \ S = typename G::S;\n    int n;\n    std::vector<std::vector<std::pair<int, S>>>\
    \ g;  // (to, diff(from, to))\n    explicit brute(int n) : n(n), g(n) {\n    }\n\
    \    std::vector<std::optional<S>> potentials(int s) {\n        std::vector<std::optional<S>>\
    \ p(n);\n        p[s] = G::e();\n        std::vector<int> st = {s};\n        while\
    \ (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \            for (auto [u, w] : g[v]) {\n                if (p[u]) continue;\n\
    \                p[u] = G::op(*p[v], w);\n                st.push_back(u);\n \
    \           }\n        }\n        return p;\n    }\n    bool merge(int a, int\
    \ b, S w) {\n        auto p = potentials(a);\n        if (p[b]) return *p[b] ==\
    \ w;\n        g[a].emplace_back(b, w);\n        g[b].emplace_back(a, G::inv(w));\n\
    \        return true;\n    }\n    std::optional<S> diff(int a, int b) {\n    \
    \    return potentials(a)[b];\n    }\n};\n\ntemplate <class G> void run(std::mt19937&\
    \ rng, auto gen) {\n    for (int it = 0; it < 300; it++) {\n        int n = 1\
    \ + rng() % 8;\n        weighted_dsu<G> d(n);\n        brute<G> b(n);\n      \
    \  for (int q = 0; q < 30; q++) {\n            int x = rng() % n, y = rng() %\
    \ n;\n            if (rng() % 2) {\n                auto w = gen();\n        \
    \        assert(d.merge(x, y, w) == b.merge(x, y, w));\n            } else {\n\
    \                auto r = b.diff(x, y);\n                assert(d.same(x, y) ==\
    \ r.has_value());\n                if (r) assert(d.diff(x, y) == *r);\n      \
    \      }\n        }\n        auto groups = d.groups();\n        int total = 0;\n\
    \        for (auto& grp : groups) {\n            for (int v : grp) assert(d.leader(v)\
    \ == d.leader(grp[0])), assert(d.size(v) == int(grp.size()));\n            total\
    \ += int(grp.size());\n        }\n        assert(total == n);\n    }\n}\n\n//\
    \ non-commutative: affine maps x -> a x + b over a prime field (a != 0)\nstruct\
    \ group_affine {\n    static constexpr long long p = 1000003;\n    struct S {\n\
    \        long long a, b;\n        bool operator==(const S&) const = default;\n\
    \    };\n    static long long pw(long long a, long long n) {\n        long long\
    \ r = 1;\n        a %= p;\n        while (n) {\n            if (n & 1) r = r *\
    \ a % p;\n            a = a * a % p;\n            n >>= 1;\n        }\n      \
    \  return r;\n    }\n    static S op(S f, S g) {  // f after g: f(g(x))\n    \
    \    return {f.a * g.a % p, (f.a * g.b + f.b) % p};\n    }\n    static S e() {\n\
    \        return {1, 0};\n    }\n    static S inv(S f) {\n        long long ia\
    \ = pw(f.a, p - 2);\n        return {ia, (p - ia * f.b % p) % p};\n    }\n};\n\
    \nint main() {\n    std::mt19937 rng(2024);\n    run<group_add<long long>>(rng,\
    \ [&] { return (long long)(rng() % 21) - 10; });\n    run<group_xor<int>>(rng,\
    \ [&] { return int(rng() % 16); });\n    run<group_affine>(rng, [&] { return group_affine::S{1\
    \ + (long long)(rng() % 5), (long long)(rng() % 7)}; });\n    // contradiction\
    \ leaves the structure unchanged\n    {\n        weighted_dsu<group_add<long long>>\
    \ d(3);\n        assert(d.merge(0, 1, 5));\n        assert(d.merge(1, 2, 7));\n\
    \        assert(d.diff(0, 2) == 12 && d.diff(2, 0) == -12);\n        assert(!d.merge(0,\
    \ 2, 13));\n        assert(d.merge(0, 2, 12));\n        assert(d.size(0) == 3);\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - algebra/group_add.hpp
  - algebra/monoid_add.hpp
  - algebra/group_xor.hpp
  - algebra/monoid_xor.hpp
  - datastructure/weighted_dsu.hpp
  - algebra/concept.hpp
  isVerificationFile: true
  path: test/unit/weighted_dsu.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:09:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/weighted_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/unit/weighted_dsu.test.cpp
- /verify/test/unit/weighted_dsu.test.cpp.html
title: test/unit/weighted_dsu.test.cpp
---
