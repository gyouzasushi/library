#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <vector>

struct mo {
    mo() = default;
    int add(int l, int r) {
        assert(0 <= l && l <= r);
        lr.emplace_back(l, r);
        return (int)lr.size() - 1;
    }
    void run(auto add_left, auto add_right, auto erase_left, auto erase_right,
             auto query) const {
        int l = 0, r = 0;
        for (int i : order()) {
            while (l > lr[i].first) add_left(--l);
            while (r < lr[i].second) add_right(r++);
            while (l < lr[i].first) erase_left(l++);
            while (r > lr[i].second) erase_right(--r);
            query(i);
        }
    }
    void run(auto add, auto erase, auto query) const {
        run(add, add, erase, erase, query);
    }

  private:
    std::vector<std::pair<int, int>> lr;
    std::vector<int> order() const {
        int q = lr.size();
        if (q == 0) return {};
        int n = 1;
        for (auto [l, r] : lr) n = std::max(n, r);
        int w = std::max(1, (int)(std::sqrt(3.0) * n / std::sqrt(2.0 * q)));
        std::vector<int> ord(q);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(), [&](int a, int b) {
            int ba = lr[a].first / w, bb = lr[b].first / w;
            if (ba != bb) return ba < bb;
            return (ba & 1) ? lr[a].second > lr[b].second
                            : lr[a].second < lr[b].second;
        });
        auto cost = [&](int a, int b) {
            return std::abs(lr[ord[a]].first - lr[ord[b]].first) +
                   std::abs(lr[ord[a]].second - lr[ord[b]].second);
        };
        auto improve = [&](int k) {
            if (cost(k, k + 2) + cost(k + 1, k + 3) <
                cost(k, k + 1) + cost(k + 2, k + 3))
                std::swap(ord[k + 1], ord[k + 2]);
            if (cost(k, k + 3) + cost(k + 1, k + 4) <
                cost(k, k + 1) + cost(k + 3, k + 4))
                std::swap(ord[k + 1], ord[k + 3]);
        };
        for (int k = 0; k + 5 <= q; k++) improve(k);
        for (int k = q - 5; k >= 0; k--) improve(k);
        return ord;
    }
};
