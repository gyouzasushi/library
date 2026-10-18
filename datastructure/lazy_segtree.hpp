#pragma once
#include <atcoder/lazysegtree>
template <class A>
using lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename A::F, A::mapping, A::composition, A::id>;
