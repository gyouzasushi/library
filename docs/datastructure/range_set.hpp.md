---
title: Range Set
documentation_of: datastructure/range_set.hpp
---

### 概要
- 区間を set で管理するテクニック。
- すべて閉区間。
  
### 使い方
- `range_set(merge_adjacent_segment = true)`: コンストラクタ。区間 `[l, m]` と `[m + 1, r]` を `[l, r]` にマージしない場合は、`merge_adjacent_segment` を `false` にする。
- `insert(l, r)`: 区間 `[l, r]` を挿入。
- `erase(l, r)`: 区間 `[l, r]` を削除。
- `is_covered(l, r)`: 区間 `[l, r]` が完全に覆われているか？を返す。
- `covered_by(l, r)`: 区間 `[l, r]` を完全に覆う区間を返す。