---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit/top_k_sum.test.cpp
    title: test/unit/top_k_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/top_k_sum.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <queue>\n#include <vector>\ntemplate <class T, class\
    \ Compare = std::greater<T>>\nstruct top_k_sum {\npublic:\n    explicit top_k_sum(int\
    \ k) : _k(k), _sum(T()) {\n        assert(k >= 0);\n    }\n    void insert(const\
    \ T& x) {\n        in.push(x);\n        _sum += x;\n        modify();\n    }\n\
    \    void erase(const T& x) {\n        assert(size() > 0);\n        if (!in.empty()\
    \ && in.top() == x) {\n            _sum -= x;\n            in.pop();\n       \
    \ } else if (!in.empty() && Compare()(x, in.top())) {\n            _sum -= x;\n\
    \            d_in.push(x);\n        } else {\n            d_out.push(x);\n   \
    \     }\n        modify();\n    }\n    void set_k(int k) {\n        assert(k >=\
    \ 0);\n        _k = k;\n        modify();\n    }\n    int k() const {\n      \
    \  return _k;\n    }\n    T sum() const {\n        return _sum;\n    }\n    int\
    \ size() const {\n        return int(in.size() + out.size() - d_in.size() - d_out.size());\n\
    \    }\n\nprivate:\n    struct reverse_compare {\n        bool operator()(const\
    \ T& a, const T& b) const {\n            return Compare()(b, a);\n        }\n\
    \    };\n    std::priority_queue<T, std::vector<T>, Compare> in, d_in;\n    std::priority_queue<T,\
    \ std::vector<T>, reverse_compare> out, d_out;\n    int _k;\n    T _sum;\n   \
    \ int in_size() const {\n        return int(in.size() - d_in.size());\n    }\n\
    \    void modify() {\n        while (in_size() < _k && !out.empty()) {\n     \
    \       T p = out.top();\n            out.pop();\n            if (!d_out.empty()\
    \ && p == d_out.top()) {\n                d_out.pop();\n            } else {\n\
    \                _sum += p;\n                in.push(p);\n            }\n    \
    \    }\n        while (in_size() > _k) {\n            T p = in.top();\n      \
    \      in.pop();\n            if (!d_in.empty() && p == d_in.top()) {\n      \
    \          d_in.pop();\n            } else {\n                _sum -= p;\n   \
    \             out.push(p);\n            }\n        }\n        while (!d_in.empty()\
    \ && in.top() == d_in.top()) {\n            in.pop();\n            d_in.pop();\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <queue>\n\
    #include <vector>\ntemplate <class T, class Compare = std::greater<T>>\nstruct\
    \ top_k_sum {\npublic:\n    explicit top_k_sum(int k) : _k(k), _sum(T()) {\n \
    \       assert(k >= 0);\n    }\n    void insert(const T& x) {\n        in.push(x);\n\
    \        _sum += x;\n        modify();\n    }\n    void erase(const T& x) {\n\
    \        assert(size() > 0);\n        if (!in.empty() && in.top() == x) {\n  \
    \          _sum -= x;\n            in.pop();\n        } else if (!in.empty() &&\
    \ Compare()(x, in.top())) {\n            _sum -= x;\n            d_in.push(x);\n\
    \        } else {\n            d_out.push(x);\n        }\n        modify();\n\
    \    }\n    void set_k(int k) {\n        assert(k >= 0);\n        _k = k;\n  \
    \      modify();\n    }\n    int k() const {\n        return _k;\n    }\n    T\
    \ sum() const {\n        return _sum;\n    }\n    int size() const {\n       \
    \ return int(in.size() + out.size() - d_in.size() - d_out.size());\n    }\n\n\
    private:\n    struct reverse_compare {\n        bool operator()(const T& a, const\
    \ T& b) const {\n            return Compare()(b, a);\n        }\n    };\n    std::priority_queue<T,\
    \ std::vector<T>, Compare> in, d_in;\n    std::priority_queue<T, std::vector<T>,\
    \ reverse_compare> out, d_out;\n    int _k;\n    T _sum;\n    int in_size() const\
    \ {\n        return int(in.size() - d_in.size());\n    }\n    void modify() {\n\
    \        while (in_size() < _k && !out.empty()) {\n            T p = out.top();\n\
    \            out.pop();\n            if (!d_out.empty() && p == d_out.top()) {\n\
    \                d_out.pop();\n            } else {\n                _sum += p;\n\
    \                in.push(p);\n            }\n        }\n        while (in_size()\
    \ > _k) {\n            T p = in.top();\n            in.pop();\n            if\
    \ (!d_in.empty() && p == d_in.top()) {\n                d_in.pop();\n        \
    \    } else {\n                _sum -= p;\n                out.push(p);\n    \
    \        }\n        }\n        while (!d_in.empty() && in.top() == d_in.top())\
    \ {\n            in.pop();\n            d_in.pop();\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/top_k_sum.hpp
  requiredBy: []
  timestamp: '2026-10-27 20:36:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit/top_k_sum.test.cpp
documentation_of: datastructure/top_k_sum.hpp
layout: document
title: Top K Sum
---

### 概要
- 多重集合を `Compare` 順に並べたときの先頭 $k$ 個の和を保つ。

### 使い方
- `top_k_sum<T, Compare = std::greater<T>>(k)`: 空の多重集合を作る。`std::greater` なら大きい方から $k$ 個の和、`std::less` なら小さい方から $k$ 個の和。
- `insert(x)`: `x` を 1 個追加する。
- `erase(x)`: `x` を 1 個削除する。`x` は含まれていなければならない。
- `set_k(k)`: $k$ を `k` に設定する。
- `k()`: $k$ を返す。
- `sum()`: 先頭 $k$ 個の和を返す。要素が $k$ 個未満なら全要素の和を返す。
- `size()`: 要素の個数を返す。

### 制約
- $0 \le k$
- `T` は `+=`, `-=`, `==` を持つ

### 計算量
- `insert`, `erase`: 償却 $\mathcal{O}(\log N)$
- `set_k`: 償却 $\mathcal{O}(\lvert k - k' \rvert \log N)$
- `k`, `sum`, `size`: $\mathcal{O}(1)$
