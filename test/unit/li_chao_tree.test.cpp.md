---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/li_chao_tree.hpp
    title: Li Chao Tree
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
  bundledCode: "#line 1 \"test/unit/li_chao_tree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <iostream>\n\
    #include <optional>\n#include <random>\n#include <vector>\n\n#line 5 \"datastructure/li_chao_tree.hpp\"\
    \n#include <utility>\n#line 7 \"datastructure/li_chao_tree.hpp\"\n\ntemplate <class\
    \ T> struct li_chao_tree {\n    li_chao_tree(long long lo, long long hi) : lo(lo),\
    \ hi(hi) {\n        assert(lo < hi);\n        make_node();\n    }\n    void add_line(T\
    \ a, T b) { add_line(0, lo, hi, a, b); }\n    void add_segment(T a, T b, long\
    \ long l, long long r) {\n        assert(lo <= l && l <= r && r <= hi);\n    \
    \    add_segment(0, lo, hi, l, r, a, b);\n    }\n    std::optional<T> min(long\
    \ long x) const {\n        assert(lo <= x && x < hi);\n        std::optional<T>\
    \ res;\n        long long l = lo, r = hi;\n        for (int t = 0; t != -1;) {\n\
    \            const node& v = get(t);\n            if (v.has) {\n             \
    \   T y = v.a * x + v.b;\n                if (!res || y < *res) res = y;\n   \
    \         }\n            long long m = l + (r - l) / 2;\n            if (x < m)\
    \ {\n                r = m;\n                t = v.left;\n            } else {\n\
    \                l = m;\n                t = v.right;\n            }\n       \
    \ }\n        return res;\n    }\n\n  private:\n    struct node {\n        T a\
    \ = 0, b = 0;\n        bool has = false;\n        int left = -1, right = -1;\n\
    \    };\n    static constexpr int chunk_log = 16;\n    long long lo, hi;\n   \
    \ int num_nodes = 0;\n    std::vector<std::vector<node>> chunks;\n    node& get(int\
    \ t) { return chunks[t >> chunk_log][t & ((1 << chunk_log) - 1)]; }\n    const\
    \ node& get(int t) const {\n        return chunks[t >> chunk_log][t & ((1 << chunk_log)\
    \ - 1)];\n    }\n    int make_node() {\n        if ((num_nodes & ((1 << chunk_log)\
    \ - 1)) == 0) {\n            chunks.emplace_back();\n            chunks.back().reserve(1\
    \ << chunk_log);\n        }\n        chunks.back().push_back({});\n        return\
    \ num_nodes++;\n    }\n    void add_line(int t, long long l, long long r, T a,\
    \ T b) {\n        while (true) {\n            node& v = get(t);\n            if\
    \ (!v.has) {\n                v.a = a, v.b = b, v.has = true;\n              \
    \  return;\n            }\n            bool left_better = a * l + b < v.a * l\
    \ + v.b;\n            bool right_better = a * (r - 1) + b < v.a * (r - 1) + v.b;\n\
    \            if (left_better && right_better) {\n                v.a = a, v.b\
    \ = b;\n                return;\n            }\n            if (!left_better &&\
    \ !right_better) return;\n            long long m = l + (r - l) / 2;\n       \
    \     bool mid_better = a * m + b < v.a * m + v.b;\n            if (mid_better)\
    \ std::swap(v.a, a), std::swap(v.b, b);\n            if (left_better != mid_better)\
    \ {\n                if (get(t).left == -1) get(t).left = make_node();\n     \
    \           t = get(t).left, r = m;\n            } else {\n                if\
    \ (get(t).right == -1) get(t).right = make_node();\n                t = get(t).right,\
    \ l = m;\n            }\n        }\n    }\n    void add_segment(int t, long long\
    \ l, long long r, long long ql, long long qr,\n                     T a, T b)\
    \ {\n        if (qr <= l || r <= ql) return;\n        if (ql <= l && r <= qr)\
    \ {\n            add_line(t, l, r, a, b);\n            return;\n        }\n  \
    \      long long m = l + (r - l) / 2;\n        if (ql < m) {\n            if (get(t).left\
    \ == -1) get(t).left = make_node();\n            add_segment(get(t).left, l, m,\
    \ ql, qr, a, b);\n        }\n        if (m < qr) {\n            if (get(t).right\
    \ == -1) get(t).right = make_node();\n            add_segment(get(t).right, m,\
    \ r, ql, qr, a, b);\n        }\n    }\n};\n#line 11 \"test/unit/li_chao_tree.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(5);\n    for (int it = 0; it < 3000; it++)\
    \ {\n        long long lo = (long long)(rng() % 41) - 20;\n        long long hi\
    \ = lo + 1 + rng() % 40;\n        li_chao_tree<long long> t(lo, hi);\n       \
    \ std::vector<std::array<long long, 4>> segs;\n        int ops = rng() % 8;\n\
    \        for (int k = 0; k < ops; k++) {\n            long long a = (long long)(rng()\
    \ % 21) - 10, b = (long long)(rng() % 201) - 100;\n            if (rng() % 2)\
    \ {\n                t.add_line(a, b);\n                segs.push_back({a, b,\
    \ lo, hi});\n            } else {\n                long long l = lo + rng() %\
    \ (hi - lo + 1), r = lo + rng() % (hi - lo + 1);\n                if (l > r) std::swap(l,\
    \ r);\n                t.add_segment(a, b, l, r);\n                segs.push_back({a,\
    \ b, l, r});\n            }\n        }\n        for (long long x = lo; x < hi;\
    \ x++) {\n            std::optional<long long> best;\n            for (auto [a,\
    \ b, l, r] : segs)\n                if (l <= x && x < r && (!best || a * x + b\
    \ < *best)) best = a * x + b;\n            assert(t.min(x) == best);\n       \
    \ }\n    }\n    // the case the old implementation got wrong\n    {\n        li_chao_tree<long\
    \ long> t(-20, 21);\n        for (auto [a, b] : {std::pair{5, -62}, {-8, 49},\
    \ {-1, -50}, {-4, 8}, {-7, 16}, {-1, -22}}) t.add_line(a, b);\n        assert(t.min(10)\
    \ == -60);\n    }\n    // large coordinates, double values\n    {\n        li_chao_tree<double>\
    \ t(-1000000000, 1000000001);\n        t.add_line(0.5, 1.0);\n        t.add_segment(-0.5,\
    \ 2.0, 0, 10);\n        assert(*t.min(4) == 0.0);\n        assert(*t.min(100)\
    \ == 51.0);\n        assert(!li_chao_tree<long long>(0, 10).min(3));\n    }\n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <iostream>\n\
    #include <optional>\n#include <random>\n#include <vector>\n\n#include \"datastructure/li_chao_tree.hpp\"\
    \n\nint main() {\n    std::mt19937 rng(5);\n    for (int it = 0; it < 3000; it++)\
    \ {\n        long long lo = (long long)(rng() % 41) - 20;\n        long long hi\
    \ = lo + 1 + rng() % 40;\n        li_chao_tree<long long> t(lo, hi);\n       \
    \ std::vector<std::array<long long, 4>> segs;\n        int ops = rng() % 8;\n\
    \        for (int k = 0; k < ops; k++) {\n            long long a = (long long)(rng()\
    \ % 21) - 10, b = (long long)(rng() % 201) - 100;\n            if (rng() % 2)\
    \ {\n                t.add_line(a, b);\n                segs.push_back({a, b,\
    \ lo, hi});\n            } else {\n                long long l = lo + rng() %\
    \ (hi - lo + 1), r = lo + rng() % (hi - lo + 1);\n                if (l > r) std::swap(l,\
    \ r);\n                t.add_segment(a, b, l, r);\n                segs.push_back({a,\
    \ b, l, r});\n            }\n        }\n        for (long long x = lo; x < hi;\
    \ x++) {\n            std::optional<long long> best;\n            for (auto [a,\
    \ b, l, r] : segs)\n                if (l <= x && x < r && (!best || a * x + b\
    \ < *best)) best = a * x + b;\n            assert(t.min(x) == best);\n       \
    \ }\n    }\n    // the case the old implementation got wrong\n    {\n        li_chao_tree<long\
    \ long> t(-20, 21);\n        for (auto [a, b] : {std::pair{5, -62}, {-8, 49},\
    \ {-1, -50}, {-4, 8}, {-7, 16}, {-1, -22}}) t.add_line(a, b);\n        assert(t.min(10)\
    \ == -60);\n    }\n    // large coordinates, double values\n    {\n        li_chao_tree<double>\
    \ t(-1000000000, 1000000001);\n        t.add_line(0.5, 1.0);\n        t.add_segment(-0.5,\
    \ 2.0, 0, 10);\n        assert(*t.min(4) == 0.0);\n        assert(*t.min(100)\
    \ == 51.0);\n        assert(!li_chao_tree<long long>(0, 10).min(3));\n    }\n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - datastructure/li_chao_tree.hpp
  isVerificationFile: true
  path: test/unit/li_chao_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 22:16:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit/li_chao_tree.test.cpp
layout: document
redirect_from:
- /verify/test/unit/li_chao_tree.test.cpp
- /verify/test/unit/li_chao_tree.test.cpp.html
title: test/unit/li_chao_tree.test.cpp
---
