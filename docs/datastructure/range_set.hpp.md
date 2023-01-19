---
title: Range Set
documentation_of: datastructure/range_set.hpp
---

### 概要
- 区間を set で管理するテクニック。
- `range_map<T, bool>` と同じことです。
- すべて閉区間。
  
### 使い方
- `range_set(merge_adjacent_segment = true)`: コンストラクタ。区間 `[l, m]` と `[m + 1, r]` を `[l, r]` にマージしない場合は、`merge_adjacent_segment` を `false` にする。
- `insert(l, r)`: 区間 `[l, r]` を挿入。
- `insert(l, r, f, g)`: 区間 `[l, r]` を挿入。そのとき、区間が削除されるたびに `f` を、区間が追加されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r) -> void`。
- `erase(l, r)`: 区間 `[l, r]` を削除。
- `erase(l, r, f, g)`: 区間 `[l, r]` を削除。そのとき、区間が削除されるたびに `f` を、区間が追加されるたびに `g` を実行する。`f`, `g` はともに `(T l, T r) -> void`。
- `contains(l, r)`: `[l, r]` を完全に覆う区間がある場合、それを返す。
- `ranges()`: すべての区間 `[l, r]` を列挙する。