#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <optional>
#include <random>
#include <vector>

#include "datastructure/slope_trick.hpp"

constexpr int B = 400;
constexpr int W = 50;
struct brute {
    std::vector<long long> f;
    brute() : f(2 * B + 1, 0) {}
    long long& at(long long x) { return f[x + B]; }
    long long at(long long x) const { return f[x + B]; }
    void add(long long a) {
        for (long long& v : f) v += a;
    }
    void add_x_minus_a(long long a) {
        for (int x = -B; x <= B; x++) at(x) += std::max<long long>(0, x - a);
    }
    void add_a_minus_x(long long a) {
        for (int x = -B; x <= B; x++) at(x) += std::max<long long>(0, a - x);
    }
    void prefix_min() {
        for (int x = -B + 1; x <= B; x++) at(x) = std::min(at(x), at(x - 1));
    }
    void suffix_min() {
        for (int x = B - 1; x >= -B; x--) at(x) = std::min(at(x), at(x + 1));
    }
    void shift(long long a, long long b) {
        std::vector<long long> g(2 * B + 1);
        for (int x = -B; x <= B; x++) {
            long long best = at(std::clamp<long long>(x - a, -B, B));
            for (long long y = std::max<long long>(-B, x - b); y <= std::min<long long>(B, x - a); y++)
                best = std::min(best, at(y));
            g[x + B] = best;
        }
        f = g;
    }
    long long min() const { return *std::min_element(f.begin(), f.end()); }
    std::pair<std::optional<long long>, std::optional<long long>> argmin() const {
        long long m = min();
        int l = -B, r = B;
        while (at(l) != m) l++;
        while (at(r) != m) r--;
        std::optional<long long> ol, orr;
        if (l != -B) ol = l;
        if (r != B) orr = r;
        return {ol, orr};
    }
};
void random_ops(std::mt19937& rng, slope_trick<long long>& st, brute& br, int ops, long long& shifted) {
    for (int t = 0; t < ops; t++) {
        int c = rng() % 7;
        long long a = (long long)(rng() % 21) - 10;
        if (c == 0) {
            st.add(a);
            br.add(a);
        } else if (c == 1) {
            st.add_x_minus_a(a);
            br.add_x_minus_a(a);
        } else if (c == 2) {
            st.add_a_minus_x(a);
            br.add_a_minus_x(a);
        } else if (c == 3) {
            st.add_abs(a);
            br.add_x_minus_a(a);
            br.add_a_minus_x(a);
        } else if (c == 4) {
            st.prefix_min();
            br.prefix_min();
        } else if (c == 5) {
            st.suffix_min();
            br.suffix_min();
        } else {
            long long b = (long long)(rng() % 11) - 5;
            long long d = rng() % 6;
            if (rng() % 2) {
                st.shift(b);
                br.shift(b, b);
                shifted += std::abs(b);
            } else {
                st.shift(b, b + d);
                br.shift(b, b + d);
                shifted += std::abs(b) + d;
            }
        }
    }
}
void check(const slope_trick<long long>& st, const brute& br, long long shifted) {
    assert(shifted < B - W);
    assert(st.min() == br.min());
    assert(st.argmin() == br.argmin());
    for (int x = -W; x <= W; x++) assert(st(x) == br.at(x));
}
int main() {
    std::mt19937 rng(20261030);
    for (int it = 0; it < 3000; it++) {
        slope_trick<long long> st;
        brute br;
        long long shifted = 0;
        int ops = rng() % 25;
        for (int t = 0; t < ops; t++) {
            random_ops(rng, st, br, 1, shifted);
            check(st, br, shifted);
        }
    }
    for (int it = 0; it < 2000; it++) {
        slope_trick<long long> f, g;
        brute bf, bg;
        long long shifted = 0;
        random_ops(rng, f, bf, rng() % 12, shifted);
        random_ops(rng, g, bg, rng() % 12, shifted);
        f.merge(g);
        for (int x = -B; x <= B; x++) bf.at(x) += bg.at(x);
        check(f, bf, shifted);
        assert(g.min() == 0);
        assert(!g.argmin().first && !g.argmin().second);
        assert(g(7) == 0);
    }
    {
        slope_trick<long long> f;
        assert(f.min() == 0);
        assert(!f.argmin().first && !f.argmin().second);
        f.add_x_minus_a(3);
        assert(f.argmin() == std::make_pair(std::optional<long long>(), std::optional<long long>(3)));
        f.add_a_minus_x(-2);
        assert(f.argmin() == std::make_pair(std::optional<long long>(-2), std::optional<long long>(3)));
        f.add_abs(10);
        assert(f.min() == 7);
        assert(f.argmin() == std::make_pair(std::optional<long long>(3), std::optional<long long>(10)));
    }
    std::cout << "Hello World" << std::endl;
}
