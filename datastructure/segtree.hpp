#pragma once
#include <atcoder/segtree>
template <class M>
using segtree = atcoder::segtree<typename M::S, M::op, M::e>;
