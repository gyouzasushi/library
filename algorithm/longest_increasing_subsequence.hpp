#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

template <class T, class Compare = std::less<T>>
struct longest_increasing_subsequence {
    explicit longest_increasing_subsequence(const std::vector<T>& a,
                                            Compare comp = {})
        : n(a.size()), pos(n) {
        std::vector<T> dp;
        for (int i = 0; i < n; i++) {
            auto it = std::ranges::lower_bound(dp, a[i], comp);
            pos[i] = it - dp.begin();
            if (it == dp.end()) {
                dp.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }
        len = dp.size();
        cand.resize(len);
        for (int i = n - 1; i >= 0; i--) {
            int j = pos[i];
            if (j == len - 1 ||
                (!cand[j + 1].empty() && comp(a[i], a[cand[j + 1].back()]))) {
                cand[j].push_back(i);
            } else {
                pos[i] = -1;
            }
        }
        for (auto& c : cand) std::ranges::reverse(c);
    }
    int length() const { return len; }
    int position(int i) const {
        assert(0 <= i && i < n);
        return pos[i];
    }
    const std::vector<int>& candidates(int j) const {
        assert(0 <= j && j < len);
        return cand[j];
    }
    std::vector<int> indices() const {
        std::vector<int> res(len);
        for (int j = 0; j < len; j++) res[j] = cand[j].front();
        return res;
    }

  private:
    int n, len;
    std::vector<int> pos;
    std::vector<std::vector<int>> cand;
};
