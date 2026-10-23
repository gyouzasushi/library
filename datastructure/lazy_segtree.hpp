#pragma once
#include <atcoder/lazysegtree>

#include "algebra/concept.hpp"
template <acted_monoid A>
using lazy_segtree = atcoder::lazy_segtree<typename A::S, A::op, A::e, typename A::F, A::mapping, A::composition, A::id>;
