#pragma once
template <typename T>
struct Matrix {
    std::vector<std::vector<T>> a;
    Matrix() {
    }
    Matrix(size_t n, size_t m) : a(n, std::vector<T>(m, 0)) {
    }
    Matrix(std::vector<std::vector<T>> _a) {
        for (size_t i = 1; i < _a.size(); i++) {
            assert(_a[0].size() == _a[i].size());
        }
        a = std::move(_a);
    }
    static Matrix e(size_t n) {
        Matrix ret(n, n);
        for (size_t i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }
    inline const std::vector<T>& operator[](int i) const {
        return a[i];
    }
    inline std::vector<T>& operator[](int i) {
        return a[i];
    }
    Matrix& operator*=(const Matrix& rhs) {
        assert(a[0].size() == rhs.a.size());
        std::vector ret(a.size(), std::vector<T>(rhs[0].size(), 0));
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < rhs[0].size(); j++) {
                for (size_t k = 0; k < a[0].size(); k++) {
                    ret[i][j] += a[i][k] * rhs[k][j];
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
