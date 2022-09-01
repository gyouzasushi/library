#pragma once
template <class S, S (*add)(S, S), S (*zero)(), S (*mul)(S, S), S (*one)()>
struct Matrix {
    std::vector<std::vector<S>> a;
    Matrix() {
    }
    Matrix(size_t n, size_t m) : a(n, std::vector<S>(m, zero())) {
    }
    Matrix(std::vector<std::vector<S>> _a) {
        for (size_t i = 1; i < _a.size(); i++) {
            assert(_a[0].size() == _a[i].size());
        }
        a = std::move(_a);
    }
    static Matrix e(size_t n) {
        Matrix ret(n, n);
        for (size_t i = 0; i < n; i++) ret[i][i] = one();
        return ret;
    }
    inline const std::vector<S>& operator[](int i) const {
        return a[i];
    }
    inline std::vector<S>& operator[](int i) {
        return a[i];
    }
    Matrix& operator*=(const Matrix& rhs) {
        assert(a[0].size() == rhs.a.size());
        std::vector ret(a.size(), std::vector<S>(rhs[0].size(), zero()));
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < rhs[0].size(); j++) {
                for (size_t k = 0; k < a[0].size(); k++) {
                    ret[i][j] = add(ret[i][j], mul(a[i][k], rhs[k][j]));
                }
            }
        }
        a = std::move(ret);
        return *this;
    }
    Matrix operator*(const Matrix& rhs) const {
        return Matrix(*this) *= rhs;
    }
    Matrix pow(long long k) const {
        assert(0 <= k);
        Matrix x = *this, ret = Matrix::e(a.size());
        while (k > 0) {
            if (k & 1) ret *= x;
            x *= x;
            k >>= 1;
        }
        return ret;
    }
};