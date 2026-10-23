#pragma once
#include <cassert>
#include <utility>
#include <vector>

#include "algebra/concept.hpp"
#include "algebra/semiring_plus_times.hpp"
template <semiring R>
struct semiring_matrix {
    using S = typename R::S;
    semiring_matrix() : semiring_matrix(0, 0) {}
    semiring_matrix(int h, int w) : h(h), w(w), a(h, std::vector<S>(w, R::zero())) {}
    explicit semiring_matrix(std::vector<std::vector<S>> v) : h(int(v.size())), w(h ? int(v[0].size()) : 0), a(std::move(v)) {
        for (int i = 0; i < h; i++) assert(int(a[i].size()) == w);
    }
    static semiring_matrix e(int n) {
        semiring_matrix ret(n, n);
        for (int i = 0; i < n; i++) ret[i][i] = R::one();
        return ret;
    }
    int height() const {
        return h;
    }
    int width() const {
        return w;
    }
    const std::vector<S>& operator[](int i) const {
        return a[i];
    }
    std::vector<S>& operator[](int i) {
        return a[i];
    }
    friend semiring_matrix operator+(const semiring_matrix& lhs, const semiring_matrix& rhs) {
        assert(lhs.h == rhs.h && lhs.w == rhs.w);
        semiring_matrix ret(lhs.h, lhs.w);
        for (int i = 0; i < lhs.h; i++) {
            for (int j = 0; j < lhs.w; j++) ret[i][j] = R::add(lhs[i][j], rhs[i][j]);
        }
        return ret;
    }
    friend semiring_matrix operator*(const semiring_matrix& lhs, const semiring_matrix& rhs) {
        assert(lhs.w == rhs.h);
        semiring_matrix ret(lhs.h, rhs.w);
        for (int i = 0; i < lhs.h; i++) {
            for (int k = 0; k < lhs.w; k++) {
                for (int j = 0; j < rhs.w; j++) ret[i][j] = R::add(ret[i][j], R::mul(lhs[i][k], rhs[k][j]));
            }
        }
        return ret;
    }
    semiring_matrix& operator+=(const semiring_matrix& rhs) {
        return *this = *this + rhs;
    }
    semiring_matrix& operator*=(const semiring_matrix& rhs) {
        return *this = *this * rhs;
    }
    semiring_matrix pow(long long k) const {
        assert(h == w && k >= 0);
        semiring_matrix x = *this, ret = e(h);
        while (k) {
            if (k & 1) ret *= x;
            x *= x;
            k >>= 1;
        }
        return ret;
    }
    friend bool operator==(const semiring_matrix& lhs, const semiring_matrix& rhs) {
        return lhs.a == rhs.a;
    }

private:
    int h, w;
    std::vector<std::vector<S>> a;
};
template <class T>
using matrix = semiring_matrix<semiring_plus_times<T>>;
