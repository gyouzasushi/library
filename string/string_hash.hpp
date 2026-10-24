#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <random>
#include <vector>

#include "math/modint2305843009213693951.hpp"
template <int k = 1, class mint = modint2305843009213693951>
struct string_hash {
    static_assert(k >= 1);
    std::array<mint, k> val;
    int len;
    string_hash() : val{}, len(0) {}
    explicit string_hash(int c) : len(1) {
        val.fill(mint(c));
    }
    static string_hash repeat(int c, int n) {
        assert(0 <= n);
        string_hash h;
        h.len = n;
        for (int i = 0; i < k; i++) h.val[i] = mint(c) * pow_sum(i, n);
        return h;
    }
    friend string_hash operator+(const string_hash& a, const string_hash& b) {
        string_hash r;
        r.len = a.len + b.len;
        for (int i = 0; i < k; i++) r.val[i] = a.val[i] * pow(i, b.len) + b.val[i];
        return r;
    }
    string_hash& operator+=(const string_hash& b) {
        return *this = *this + b;
    }
    friend bool operator==(const string_hash& a, const string_hash& b) {
        return a.len == b.len && a.val == b.val;
    }
    friend bool operator<(const string_hash& a, const string_hash& b) {
        if (a.len != b.len) return a.len < b.len;
        for (int i = 0; i < k; i++) {
            if (a.val[i] != b.val[i]) return a.val[i].val() < b.val[i].val();
        }
        return false;
    }
    static mint base(int i) {
        return bases()[i];
    }
    static mint pow(int i, int n) {
        ensure(n);
        return pows()[i][n];
    }
    static mint pow_sum(int i, int n) {
        ensure(n);
        return pow_sums()[i][n];
    }

private:
    static std::array<mint, k> gen_bases() {
        std::mt19937_64 rng(std::random_device{}());
        std::array<mint, k> b;
        for (int i = 0; i < k; i++) {
            while (true) {
                uint64_t e = std::uniform_int_distribution<uint64_t>(1, mint::mod() - 1)(rng);
                if (std::gcd(e, uint64_t(mint::mod() - 1)) != 1) continue;
                b[i] = mint(37).pow(e);
                break;
            }
        }
        return b;
    }
    static std::array<mint, k>& bases() {
        static std::array<mint, k> b = gen_bases();
        return b;
    }
    static std::array<std::vector<mint>, k>& pows() {
        static std::array<std::vector<mint>, k> p = [] {
            std::array<std::vector<mint>, k> p;
            for (auto& v : p) v.assign(1, mint(1));
            return p;
        }();
        return p;
    }
    static std::array<std::vector<mint>, k>& pow_sums() {
        static std::array<std::vector<mint>, k> s = [] {
            std::array<std::vector<mint>, k> s;
            for (auto& v : s) v.assign(1, mint(0));
            return s;
        }();
        return s;
    }
    static void ensure(int n) {
        auto& p = pows();
        auto& s = pow_sums();
        int sz = int(p[0].size());
        if (n < sz) return;
        int m = std::max(n + 1, 2 * sz);
        for (int i = 0; i < k; i++) {
            p[i].resize(m);
            s[i].resize(m);
            for (int j = sz; j < m; j++) {
                p[i][j] = p[i][j - 1] * base(i);
                s[i][j] = s[i][j - 1] + p[i][j - 1];
            }
        }
    }
};
template <class A, class B>
int lcp(A& a, int l1, int r1, B& b, int l2, int r2) {
    int ok = 0, ng = std::min(r1 - l1, r2 - l2) + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        (a.prod(l1, l1 + mid) == b.prod(l2, l2 + mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, class B>
int cmp(A& a, int l1, int r1, B& b, int l2, int r2) {
    int x = lcp(a, l1, r1, b, l2, r2);
    bool ea = l1 + x == r1, eb = l2 + x == r2;
    if (ea && eb) return 0;
    if (ea) return -1;
    if (eb) return 1;
    return a.get(l1 + x).val[0].val() < b.get(l2 + x).val[0].val() ? -1 : 1;
}
