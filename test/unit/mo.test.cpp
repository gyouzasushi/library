#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "algorithm/mo.hpp"

int main() {
    std::mt19937 rng(12345);
    for (int it = 0; it < 300; it++) {
        int n = rng() % 30, q = rng() % 40;
        std::vector<int> a(n);
        for (auto& x : a) x = rng() % 5;
        mo m;
        std::vector<std::pair<int, int>> qs(q);
        for (int i = 0; i < q; i++) {
            int l = rng() % (n + 1), r = rng() % (n + 1);
            if (l > r) std::swap(l, r);
            qs[i] = {l, r};
            assert(m.add(l, r) == i);
        }
        // distinct count: symmetric callbacks
        {
            std::vector<int> cnt(5), ans(q, -1);
            int distinct = 0;
            m.run([&](int i) { if (cnt[a[i]]++ == 0) distinct++; },
                  [&](int i) { if (--cnt[a[i]] == 0) distinct--; },
                  [&](int k) { ans[k] = distinct; });
            for (int k = 0; k < q; k++) {
                auto [l, r] = qs[k];
                std::vector<int> b(a.begin() + l, a.begin() + r);
                std::sort(b.begin(), b.end());
                assert(ans[k] == (int)(std::unique(b.begin(), b.end()) - b.begin()));
            }
            for (int c : cnt) assert(c >= 0);
        }
        // inversions: left/right differ, and the window must satisfy l <= r
        {
            std::vector<int> cnt(5), ans(q, -1);
            int size = 0, inv = 0;
            auto less = [&](int v) { int s = 0; for (int u = 0; u < v; u++) s += cnt[u]; return s; };
            auto greater = [&](int v) { int s = 0; for (int u = v + 1; u < 5; u++) s += cnt[u]; return s; };
            m.run([&](int i) { inv += less(a[i]); cnt[a[i]]++; size++; },
                  [&](int i) { inv += greater(a[i]); cnt[a[i]]++; size++; },
                  [&](int i) { cnt[a[i]]--; size--; inv -= less(a[i]); assert(size >= 0); },
                  [&](int i) { cnt[a[i]]--; size--; inv -= greater(a[i]); assert(size >= 0); },
                  [&](int k) { ans[k] = inv; });
            for (int k = 0; k < q; k++) {
                auto [l, r] = qs[k];
                int e = 0;
                for (int i = l; i < r; i++)
                    for (int j = i + 1; j < r; j++) e += a[i] > a[j];
                assert(ans[k] == e);
            }
        }
    }
    // no queries
    {
        mo m;
        int calls = 0;
        auto f = [&](int) { calls++; };
        m.run(f, f, f);
        assert(calls == 0);
    }
    std::cout << "Hello World" << std::endl;
}
