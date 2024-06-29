#pragma once
#include <vector>
template <typename T>
struct matrix {
public:
    matrix() {
    }
    matrix(size_t n, size_t m) : a(n, std::vector<T>(m, 0)) {
    }
    matrix(std::vector<std::vector<T>> _a) {
        for (size_t i = 1; i < _a.size(); i++) {
            assert(_a[0].size() == _a[i].size());
        }
        a = std::move(_a);
    }
    matrix(std::vector<T> _a) {
        a.resize(_a.size());
        for (size_t i = 0; i < a.size(); i++) {
            a[i].resize(1);
            a[i][0] = _a[i];
        }
    }
    static matrix e(size_t n) {
        matrix ret(n, n);
        for (size_t i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }
    inline const std::vector<T>& operator[](int i) const {
        return a[i];
    }
    inline std::vector<T>& operator[](int i) {
        return a[i];
    }
    matrix& operator*=(const matrix& rhs) {
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
    matrix operator*(const matrix& rhs) const {
        return matrix(*this) *= rhs;
    }
    matrix pow(long long k) const {
        assert(0 <= k);
        matrix x = *this, ret = matrix::e(a.size());
        while (k > 0) {
            if (k & 1) ret *= x;
            x *= x;
            k >>= 1;
        }
        return ret;
    }

private:
    std::vector<std::vector<T>> a;
};
