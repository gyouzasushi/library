#pragma once
#include <concepts>
template <class M>
concept semigroup = requires(typename M::S a, typename M::S b) {
    { M::op(a, b) } -> std::same_as<typename M::S>;
};
template <class M>
concept monoid = semigroup<M> && requires {
    { M::e() } -> std::same_as<typename M::S>;
};
template <class A>
concept acted_monoid = monoid<A> && requires(typename A::S x, typename A::F f, typename A::F g) {
    { A::mapping(f, x) } -> std::same_as<typename A::S>;
    { A::composition(f, g) } -> std::same_as<typename A::F>;
    { A::id() } -> std::same_as<typename A::F>;
};
