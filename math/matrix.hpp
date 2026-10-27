#pragma once
#include <cassert>
#include <optional>
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
template <class T> T determinant(matrix<T> a) {
    int n = a.height();
    assert(n == a.width());
    T det = 1;
    for (int c = 0; c < n; c++) {
        int p = c;
        while (p < n && a[p][c] == T(0)) p++;
        if (p == n) return 0;
        if (p != c) {
            std::swap(a[p], a[c]);
            det = -det;
        }
        det *= a[c][c];
        T inv = T(1) / a[c][c];
        for (int i = c + 1; i < n; i++) {
            if (a[i][c] == T(0)) continue;
            T f = a[i][c] * inv;
            for (int j = c; j < n; j++) a[i][j] -= f * a[c][j];
        }
    }
    return det;
}
template <class T> std::optional<matrix<T>> inverse(matrix<T> a) {
    int n = a.height();
    assert(n == a.width());
    matrix<T> b = matrix<T>::e(n);
    for (int c = 0; c < n; c++) {
        int p = c;
        while (p < n && a[p][c] == T(0)) p++;
        if (p == n) return std::nullopt;
        std::swap(a[p], a[c]);
        std::swap(b[p], b[c]);
        T inv = T(1) / a[c][c];
        for (int j = 0; j < n; j++) {
            a[c][j] *= inv;
            b[c][j] *= inv;
        }
        for (int i = 0; i < n; i++) {
            if (i == c || a[i][c] == T(0)) continue;
            T f = a[i][c];
            for (int j = 0; j < n; j++) {
                a[i][j] -= f * a[c][j];
                b[i][j] -= f * b[c][j];
            }
        }
    }
    return b;
}
template <class T> int matrix_rank(matrix<T> a) {
    int h = a.height(), w = a.width(), r = 0;
    for (int c = 0; c < w && r < h; c++) {
        int p = r;
        while (p < h && a[p][c] == T(0)) p++;
        if (p == h) continue;
        std::swap(a[p], a[r]);
        T inv = T(1) / a[r][c];
        for (int i = r + 1; i < h; i++) {
            if (a[i][c] == T(0)) continue;
            T f = a[i][c] * inv;
            for (int j = c; j < w; j++) a[i][j] -= f * a[r][j];
        }
        r++;
    }
    return r;
}
template <class T> struct linear_system_solution {
    std::vector<T> x;
    std::vector<std::vector<T>> kernel;
};
template <class T> std::optional<linear_system_solution<T>> solve_linear_system(matrix<T> a, std::vector<T> b) {
    int h = a.height(), w = a.width();
    assert(int(b.size()) == h);
    std::vector<int> pivot;
    int r = 0;
    for (int c = 0; c < w && r < h; c++) {
        int p = r;
        while (p < h && a[p][c] == T(0)) p++;
        if (p == h) continue;
        std::swap(a[p], a[r]);
        std::swap(b[p], b[r]);
        T inv = T(1) / a[r][c];
        for (int j = c; j < w; j++) a[r][j] *= inv;
        b[r] *= inv;
        for (int i = 0; i < h; i++) {
            if (i == r || a[i][c] == T(0)) continue;
            T f = a[i][c];
            for (int j = c; j < w; j++) a[i][j] -= f * a[r][j];
            b[i] -= f * b[r];
        }
        pivot.push_back(c);
        r++;
    }
    for (int i = r; i < h; i++) {
        if (b[i] != T(0)) return std::nullopt;
    }
    linear_system_solution<T> ret;
    ret.x.assign(w, T(0));
    for (int i = 0; i < r; i++) ret.x[pivot[i]] = b[i];
    std::vector<bool> is_pivot(w, false);
    for (int c : pivot) is_pivot[c] = true;
    for (int f = 0; f < w; f++) {
        if (is_pivot[f]) continue;
        std::vector<T> v(w, T(0));
        v[f] = T(1);
        for (int i = 0; i < r; i++) v[pivot[i]] = -a[i][f];
        ret.kernel.push_back(std::move(v));
    }
    return ret;
}
