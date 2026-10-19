#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "datastructure/range_set.hpp"
void stress(std::mt19937& rng) {
    const int U = 1 + rng() % 30;
    std::vector<bool> a(U, false);
    range_set<int> st;
    long long len = 0;  // コールバックで管理する被覆長
    auto f = [&](int l, int r) { len += r - l; };
    auto g = [&](int l, int r) { len -= r - l; };
    for (int it = 0; it < 200; it++) {
        int l = rng() % U, r = rng() % U;
        if (l > r) std::swap(l, r);
        r++;
        if (rng() % 2) {
            st.insert(l, r, f, g);
            for (int i = l; i < r; i++) a[i] = true;
        } else {
            st.erase(l, r, f, g);
            for (int i = l; i < r; i++) a[i] = false;
        }
        // contains, mex
        long long naive_len = 0;
        for (int p = 0; p < U; p++) {
            assert(st.contains(p) == a[p]);
            naive_len += a[p];
            int m = p;
            while (m < U && a[m]) m++;
            assert(st.mex(p) == m);
        }
        assert(len == naive_len);
        // size: 極大な連続区間の個数
        int runs = 0;
        for (int p = 0; p < U; p++) runs += a[p] && (p == 0 || !a[p - 1]);
        assert(st.size() == runs);
        // 列挙: 昇順・互いに離れている・中身が一致
        int prev_r = -1;
        for (auto [x, y] : st) {
            assert(x < y);
            assert(prev_r < x);
            for (int p = x; p < y; p++) assert(a[p]);
            prev_r = y;
        }
        // covers, find
        int ql = rng() % U, qr = rng() % U;
        if (ql > qr) std::swap(ql, qr);
        qr++;
        bool cov = true;
        for (int p = ql; p < qr; p++) cov &= a[p];
        assert(st.covers(ql, qr) == cov);
        auto fi = st.find(ql);
        if (a[ql]) {
            assert(fi != st.end() && fi->first <= ql && ql < fi->second);
        } else {
            assert(fi == st.end());
        }
    }
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 300; trial++) stress(rng);
    std::cout << "Hello World" << std::endl;
    return 0;
}
