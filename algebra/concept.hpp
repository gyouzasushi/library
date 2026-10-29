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
template <class G>
concept group = monoid<G> && requires(typename G::S a) {
    { G::inv(a) } -> std::same_as<typename G::S>;
};
template <class A>
concept action = requires(typename A::F f, typename A::F g) {
    { A::composition(f, g) } -> std::same_as<typename A::F>;
    { A::id() } -> std::same_as<typename A::F>;
    { A::composition_commutative } -> std::convertible_to<bool>;
};
template <class A>
concept acted_monoid = monoid<A> && action<A> && requires(typename A::S x, typename A::F f) {
    { A::mapping(f, x) } -> std::same_as<typename A::S>;
};
template <class R>
concept semiring = requires(typename R::S a, typename R::S b) {
    { R::add(a, b) } -> std::same_as<typename R::S>;
    { R::zero() } -> std::same_as<typename R::S>;
    { R::mul(a, b) } -> std::same_as<typename R::S>;
    { R::one() } -> std::same_as<typename R::S>;
};
template <class A>
concept beats_acted_monoid = acted_monoid<A> && requires(typename A::S x) {
    { x.fail } -> std::convertible_to<bool>;
};
