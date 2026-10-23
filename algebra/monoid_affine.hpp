#pragma once
template <class T>
struct monoid_affine {
    struct S {
        T a, b;
    };
    static S op(S f, S g) {
        return {g.a * f.a, g.a * f.b + g.b};
    }
    static S e() {
        return {T(1), T(0)};
    }
    static T eval(S f, T x) {
        return f.a * x + f.b;
    }
};
