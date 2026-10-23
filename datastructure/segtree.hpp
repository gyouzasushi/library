#pragma once
#include <atcoder/segtree>

#include "algebra/concept.hpp"
template <monoid M>
using segtree = atcoder::segtree<typename M::S, M::op, M::e>;
