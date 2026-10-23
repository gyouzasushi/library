#pragma once
#include <cassert>
#include <concepts>
#include <cstdint>
struct modint2305843009213693951 {
    using mint = modint2305843009213693951;
    static constexpr uint64_t mod() {
        return m;
    }
    static mint raw(uint64_t v) {
        mint x;
        x._v = v;
        return x;
    }
    modint2305843009213693951() : _v(0) {}
    template <std::unsigned_integral T>
    modint2305843009213693951(T v) : _v(reduce(v)) {}
    template <std::signed_integral T>
    modint2305843009213693951(T v) {
        if (v >= 0) {
            _v = reduce(uint64_t(v));
        } else {
            uint64_t x = reduce(uint64_t(0) - uint64_t(v));
            _v = x == 0 ? 0 : m - x;
        }
    }
    uint64_t val() const {
        return _v;
    }
    mint& operator++() {
        if (++_v == m) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = m;
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint r = *this;
        ++*this;
        return r;
    }
    mint operator--(int) {
        mint r = *this;
        --*this;
        return r;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += m - rhs._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        constexpr uint64_t mask31 = (uint64_t(1) << 31) - 1;
        constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;
        uint64_t au = _v >> 31, ad = _v & mask31;
        uint64_t bu = rhs._v >> 31, bd = rhs._v & mask31;
        uint64_t mid = ad * bu + au * bd;
        uint64_t mu = mid >> 30, md = mid & mask30;
        _v = reduce((au * bu << 1) + mu + (md << 31) + ad * bd);
        return *this;
    }
    mint& operator/=(const mint& rhs) {
        return *this *= rhs.inv();
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        assert(_v != 0);
        return pow(m - 2);
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

private:
    static constexpr uint64_t m = (uint64_t(1) << 61) - 1;
    static constexpr uint64_t reduce(uint64_t v) {
        uint64_t x = (v >> 61) + (v & m);
        if (x >= m) x -= m;
        return x;
    }
    uint64_t _v;
};
