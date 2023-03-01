---
title: Wildcard Matching
documentation_of: string/wildcard_matching.hpp
---

### 概要
- 2つのワイルドカード付き文字列をスライドさせて、各箇所について一致するかどうかを調べる。
- 定数倍高速化の余地あり → 畳み込んだ後の配列の要素は $N\sigma^2$ 程度の大きさになるが、これが収まる限りで $\mathrm{mod}$ を小さくとることで `convolution` の回数を減らすことができる。
  
### 使い方
- `wildcard_matching(s, t)`:長さ $\|s\| - \|t\| + 1$ の配列 `ret` を返す。`ret[i]` は、'?' をワイルドカードとして `s.substr(i, t.size())` と `t` がマッチするかを表す。