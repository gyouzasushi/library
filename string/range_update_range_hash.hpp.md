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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/lazysegtree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <random>\n\
    \n#include \"atcoder/lazysegtree.hpp\"\n#include \"math/modint2305843009213693951.hpp\"\
    \n#include \"math/pow_sum_table.hpp\"\n#include \"math/pow_table.hpp\"\ntemplate\
    \ <int base_num = 1, typename mint = modint2305843009213693951>\nstruct range_update_range_hash\
    \ {\npublic:\n    range_update_range_hash() {\n    }\n    range_update_range_hash(const\
    \ std::vector<int>& a) : n(a.size()) {\n        std::vector<S> v(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            for (int base_id = 0; base_id < base_num;\
    \ base_id++) {\n                v[i].hash[base_id] = a[i];\n            }\n  \
    \          v[i].size = 1;\n            v[i].is_e = false;\n        }\n       \
    \ segt = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>(v);\n  \
    \  }\n    template <typename Iterable>\n    static range_update_range_hash from(const\
    \ Iterable& s) {\n        std::vector<int> a;\n        for (auto&& e : s) a.push_back(int(e));\n\
    \        return range_update_range_hash(a);\n    }\n\n    template <typename T>\n\
    \    void set(int p, T x) {\n        segt.set(p, int(x));\n    }\n    std::array<mint,\
    \ base_num> get(int p) {\n        return segt.get(p).hash;\n    }\n    std::array<mint,\
    \ base_num> prod(int l, int r) {\n        return segt.prod(l, r).hash;\n    }\n\
    \    std::array<mint, base_num> all_prod() {\n        return segt.all_prod();\n\
    \    }\n    template <typename T>\n    void apply(int l, int r, T x) {\n     \
    \   segt.apply(l, r, {int(x), false});\n    }\n    int lcp(int l1, int r1, int\
    \ l2, int r2) {\n        int len = std::min(r1 - l1, r2 - l2);\n        int ok\
    \ = 0, ng = len + 1;\n        while (ng - ok > 1) {\n            int mid = (ok\
    \ + ng) / 2;\n            bool f = prod(l1, l1 + mid) == prod(l2, l2 + mid);\n\
    \            (f ? ok : ng) = mid;\n        }\n        return ok;\n    }\n    int\
    \ cmp(int l1, int r1, int l2, int r2) {\n        int x = std::min({lcp(l1, r1,\
    \ l2, r2), r1 - l1, r2 - l2});\n        if (l1 + x == r1 && l2 + x != r2) return\
    \ -1;\n        if (l1 + x == r1 && l2 + x == r2) return 0;\n        if (l1 + x\
    \ != r1 && l2 + x == r2) return 1;\n        return get(l1 + x)[0].val() < get(l2\
    \ + x)[0].val() ? -1 : 1;\n    }\n\nprivate:\n    static inline std::array<mint,\
    \ base_num> gen_bases() {\n        static std::mt19937_64 rng(std::random_device{}());\n\
    \        std::array<mint, base_num> bases;\n        for (int i = 0; i < base_num;\
    \ i++) {\n            while (true) {\n                uint64_t k = std::uniform_int_distribution<uint64_t>(\n\
    \                    1, mint::mod - 1)(rng);\n                if (std::gcd(k,\
    \ mint::mod - 1) != 1) continue;\n                uint64_t b = mint(r).pow(k).val();\n\
    \                if (b <= A) continue;\n                bases[i] = b;\n      \
    \          break;\n            }\n        }\n        return bases;\n    }\n  \
    \  static inline std::array<pow_mod_sums<mint>, base_num> init_pow_sums(\n   \
    \     const std::array<mint, base_num>& bases) {\n        std::array<pow_mod_sums<mint>,\
    \ base_num> pow_sums;\n        for (int i = 0; i < base_num; i++) {\n        \
    \    pow_sums[i] = pow_mod_sums<mint>(bases[i], 0);\n        }\n        return\
    \ pow_sums;\n    }\n    static inline std::array<pow_mods<mint>, base_num> init_pows(\n\
    \        const std::array<mint, base_num>& bases) {\n        std::array<pow_mods<mint>,\
    \ base_num> pows;\n        for (int i = 0; i < base_num; i++) {\n            pows[i]\
    \ = pow_mods<mint>(bases[i], 0);\n        }\n        return pows;\n    }\n   \
    \ static inline std::array<mint, base_num> bases = gen_bases();\n    static inline\
    \ std::array<pow_mod_sums<mint>, base_num> pow_sums =\n        init_pow_sums(bases);\n\
    \    static inline std::array<pow_mods<mint>, base_num> pows = init_pows(bases);\n\
    \    int n;\n    static constexpr uint64_t r = 37;\n    static constexpr uint64_t\
    \ A = 2147483647;\n\n    struct S {\n        std::array<mint, base_num> hash;\n\
    \        int size;\n        bool is_e;\n    };\n    static S op(S a, S b) {\n\
    \        if (a.is_e) return b;\n        if (b.is_e) return a;\n        for (int\
    \ base_id = 0; base_id < base_num; base_id++) {\n            b.hash[base_id] +=\
    \ a.hash[base_id] * pows[base_id][b.size];\n        }\n        b.size += a.size;\n\
    \        return b;\n    }\n    static S e() {\n        return {std::array<mint,\
    \ base_num>(), 0, true};\n    }\n    struct F {\n        int f;\n        bool\
    \ is_id;\n    };\n    static S mapping(F f, S x) {\n        if (!f.is_id) {\n\
    \            for (int base_id = 0; base_id < base_num; base_id++) {\n        \
    \        x.hash[base_id] = f.f * pow_sums[base_id][x.size];\n            }\n \
    \       }\n        return x;\n    }\n    static F composition(F f, F g) {\n  \
    \      return (f.is_id ? g : f);\n    }\n    static F id() {\n        return {0,\
    \ true};\n    }\n    atcoder::lazy_segtree<S, op, e, F, mapping, composition,\
    \ id> segt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/range_update_range_hash.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/range_update_range_hash.hpp
layout: document
title: Range Update Range Hash
---

### 概要
- 区間更新に対応した Rolling-Hash。
  
### 使い方
- `RangeUpdateRangeSum<base_num, mint>::from(s)`: 文字列 `s` を初期値として構築する。`base_num` 個の基数を用いて、`mint` でハッシュを計算する。デフォルトは、`base_num = 1, mint = modint2305843009213693951`。
- `prod(l, r)`: `s[l..r]` のハッシュ値を求める。
- `all_prod()`: `s` のハッシュ値を求める。
- `apply(l, r, x)`: `s[l..r]` を `x` で置き換える。
- `set(p, x)`: `s[p]` を `x` で置き換える。
- `get(p)`: `s[p]` のハッシュ値を求める。
- `lcp(l1, r1, l2, r2)`: `s[l1..r1]` と `s[l2..r2]` の LCP の長さを求める。
- `cmp(l1, r1, l2, r2)`: `s1 = s[l1..r1]` と `s2 = s[l2..r2]` を辞書順で比較する。返り値は、`s1 < s2 ? -1 : s1 == s2 ? 0 : 1`。

### 計算量
- 構築: $\mathcal{O}(N)$
- `prod`: $\mathcal{O}(\log N)$
- `all_prod`: $\mathcal{O}(1)$
- `apply`: $\mathcal{O}(\log N)$
- `set`: $\mathcal{O}(\log N)$
- `get`: $\mathcal{O}(\log N)$
- `lcp`: $\mathcal{O}((\log N)^2)$
- `cmp`: $\mathcal{O}((\log N)^2)$