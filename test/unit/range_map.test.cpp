#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <map>
#include <optional>
#include <random>
#include <vector>

#include "datastructure/range_map.hpp"
void stress(std::mt19937& rng) {
    const int U = 1 + rng() % 30;
    const int K = 1 + rng() % 4;  // 値の種類
    const int NONE = -1;
    std::vector<int> a(U, NONE);
    range_map<int, int> mp;
    std::map<int, long long> cnt;  // コールバックで管理する値ごとの個数
    long long runs = 0;            // コールバックで管理する run の個数
    auto f = [&](int l, int r, const int& x) {
        cnt[x] += r - l;
        runs++;
    };
    auto g = [&](int l, int r, const int& x) {
        cnt[x] -= r - l;
        runs--;
    };
    for (int it = 0; it < 200; it++) {
        int l = rng() % U, r = rng() % U;
        if (l > r) std::swap(l, r);
        r++;
        if (rng() % 3) {
            int x = rng() % K;
            mp.assign(l, r, x, f, g);
            for (int i = l; i < r; i++) a[i] = x;
        } else {
            mp.erase(l, r, f, g);
            for (int i = l; i < r; i++) a[i] = NONE;
        }
        // 値と contains
        for (int p = 0; p < U; p++) {
            auto fi = mp.find(p);
            assert(mp.contains(p) == (a[p] != NONE));
            if (a[p] != NONE) {
                assert(fi != mp.end() && fi->l <= p && p < fi->r && fi->x == a[p]);
            } else {
                assert(fi == mp.end());
            }
        }
        // run が正規形: 値のある極大な連続区間と一致
        int expect_runs = 0;
        for (int p = 0; p < U; p++) expect_runs += a[p] != NONE && (p == 0 || a[p] != a[p - 1]);
        assert(mp.size() == expect_runs);
        assert(runs == expect_runs);
        int prev_r = -1;
        std::optional<int> prev_x;
        for (auto [rl, rr, rx] : mp) {
            assert(rl < rr);
            assert(prev_r <= rl);
            if (prev_r == rl) assert(*prev_x != rx);
            for (int p = rl; p < rr; p++) assert(a[p] == rx);
            if (rl > 0) assert(a[rl - 1] != rx);
            if (rr < U) assert(a[rr] != rx);
            prev_r = rr;
            prev_x = rx;
        }
        // ヒストグラム
        std::map<int, long long> expect;
        for (int v : a) {
            if (v != NONE) expect[v]++;
        }
        for (auto [v, c] : cnt) assert(c == expect[v]);
    }
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 300; trial++) stress(rng);
    std::cout << "Hello World" << std::endl;
    return 0;
}
