#pragma once
#include <cstdint>
struct modint2305843009213693951 {
    using mint = modint2305843009213693951;

public:
    static constexpr uint64_t mod = 2305843009213693951;
    modint2305843009213693951() : _v(0) {
    }
    modint2305843009213693951(uint64_t v) : _v(fast_mod(v)) {
    }
    static constexpr uint64_t fast_mod(uint64_t v) {
        uint64_t u = v >> 61;
        uint64_t d = v & mod;
        uint64_t x = u + d;
        if (x > mod) x -= mod;
        return x;
    }
    uint64_t val() const {
        return _v;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= mod) _v -= mod;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= mod) _v += mod;
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        static constexpr uint64_t mask31 = (uint64_t(1) << 31) - 1;
        static constexpr uint64_t mask30 = (uint64_t(1) << 30) - 1;
        uint64_t au = _v >> 31;
        uint64_t ad = _v & mask31;
        uint64_t bu = rhs._v >> 31;
        uint64_t bd = rhs._v & mask31;
        uint64_t m = ad * bu + au * bd;
        uint64_t mu = m >> 30;
        uint64_t md = m & mask30;
        _v = fast_mod((au * bu << 1) + mu + (md << 31) + ad * bd);
        return *this;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint pow(uint64_t n) const {
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
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
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

private:
    uint64_t _v;
};