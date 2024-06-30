---
title: Range Set
documentation_of: datastructure/range_set.hpp
---

### 概要
- 区間を set で管理するテクニック。
- すべて閉区間。
  
### 使い方
- `range_set(merge_adjacent_segment = true)`: コンストラクタ。区間 `[l, m]` と `[m + 1, r]` を `[l, r]` にマージしない場合は、`merge_adjacent_segment` を `false` にする。
- `get(p)`: `p` を含む区間のイテレータ（存在しない場合は `end()`）を返す。
- `get(l, r)`: 区間 `[l, r]` を完全に含む区間のイテレータ（存在しない場合は `end()`）を返す。
- `insert(l, r)`: 区間 `[l, r]` を挿入。
- `insert(l, r, f, g)`: 区間 `[l, r]` を挿入。そのとき、区間が追加されるたびに `f` を、区間が削除されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r) -> void`。
- `erase(l, r)`: 区間 `[l, r]` を削除。
- `erase(l, r, f, g)`: 区間 `[l, r]` を削除。そのとき、区間が追加されるたびに `f` を、区間が削除されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r) -> void`。