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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/library-checker/segment_add_get_min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#include <iostream>\n\
    \n#line 2 \"datastructure/li_chao_tree.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n#include <utility>\n#include <vector>\n\ntemplate <class\
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
    \ r, ql, qr, a, b);\n        }\n    }\n};\n#line 5 \"test/library-checker/segment_add_get_min.test.cpp\"\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    li_chao_tree<long\
    \ long> lct(-1000000000, 1000000001);\n    while (n--) {\n        long long l,\
    \ r, a, b;\n        std::cin >> l >> r >> a >> b;\n        lct.add_segment(a,\
    \ b, l, r);\n    }\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            long long l, r, a, b;\n            std::cin\
    \ >> l >> r >> a >> b;\n            lct.add_segment(a, b, l, r);\n        }\n\
    \        if (t == 1) {\n            long long p;\n            std::cin >> p;\n\
    \            auto ans = lct.min(p);\n            if (ans) {\n                std::cout\
    \ << *ans << '\\n';\n            } else {\n                std::cout << \"INFINITY\\\
    n\";\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include <iostream>\n\n#include \"datastructure/li_chao_tree.hpp\"\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    li_chao_tree<long long> lct(-1000000000,\
    \ 1000000001);\n    while (n--) {\n        long long l, r, a, b;\n        std::cin\
    \ >> l >> r >> a >> b;\n        lct.add_segment(a, b, l, r);\n    }\n    while\
    \ (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n   \
    \         long long l, r, a, b;\n            std::cin >> l >> r >> a >> b;\n \
    \           lct.add_segment(a, b, l, r);\n        }\n        if (t == 1) {\n \
    \           long long p;\n            std::cin >> p;\n            auto ans = lct.min(p);\n\
    \            if (ans) {\n                std::cout << *ans << '\\n';\n       \
    \     } else {\n                std::cout << \"INFINITY\\n\";\n            }\n\
    \        }\n    }\n}\n"
  dependsOn:
  - datastructure/li_chao_tree.hpp
  isVerificationFile: true
  path: test/library-checker/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 22:16:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/segment_add_get_min.test.cpp
- /verify/test/library-checker/segment_add_get_min.test.cpp.html
title: test/library-checker/segment_add_get_min.test.cpp
---
