#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "algorithm/longest_increasing_subsequence.hpp"

template <class Compare> void check(const std::vector<int>& a, Compare comp) {
    int n = a.size();
    // brute force: enumerate all subsequences
    std::vector<std::vector<int>> all;
    int best = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        std::vector<int> idx;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1) idx.push_back(i);
        bool ok = true;
        for (int k = 0; k + 1 < (int)idx.size(); k++)
            if (!comp(a[idx[k]], a[idx[k + 1]])) ok = false;
        if (!ok) continue;
        if ((int)idx.size() > best) best = idx.size(), all.clear();
        if ((int)idx.size() == best) all.push_back(idx);
    }
    longest_increasing_subsequence lis(a, comp);
    assert(lis.length() == best);
    std::vector<int> pos(n, -1);
    std::vector<std::vector<int>> cand(best);
    for (auto& idx : all)
        for (int j = 0; j < best; j++) {
            assert(pos[idx[j]] == -1 || pos[idx[j]] == j);
            pos[idx[j]] = j;
            cand[j].push_back(idx[j]);
        }
    for (int i = 0; i < n; i++) assert(lis.position(i) == pos[i]);
    for (int j = 0; j < best; j++) {
        std::sort(cand[j].begin(), cand[j].end());
        cand[j].erase(std::unique(cand[j].begin(), cand[j].end()), cand[j].end());
        assert(lis.candidates(j) == cand[j]);
        for (int k = 0; k + 1 < (int)cand[j].size(); k++)
            assert(!comp(a[cand[j][k]], a[cand[j][k + 1]]));  // values non-increasing
    }
    std::sort(all.begin(), all.end());
    if (best > 0) assert(lis.indices() == all.front());
    else assert(lis.indices().empty());
}

int main() {
    std::mt19937 rng(777);
    for (int it = 0; it < 400; it++) {
        int n = rng() % 11;
        int v = 1 + rng() % 6;
        std::vector<int> a(n);
        for (auto& x : a) x = rng() % v;
        check(a, std::less<int>());
        check(a, std::less_equal<int>());
    }
    // blog example (2, 1, 4, 5, 3): index 4 is useless
    {
        std::vector<int> a = {2, 1, 4, 5, 3};
        longest_increasing_subsequence lis(a);
        assert(lis.length() == 3);
        assert((lis.indices() == std::vector<int>{0, 2, 3}));
        assert(lis.position(4) == -1);
        assert((lis.candidates(0) == std::vector<int>{0, 1}));
    }
    // strings
    {
        std::vector<std::string> a = {"b", "a", "c"};
        longest_increasing_subsequence lis(a);
        assert(lis.length() == 2);
    }
    // large
    {
        int n = 200000;
        std::vector<int> a(n);
        for (auto& x : a) x = rng();
        longest_increasing_subsequence lis(a);
        assert(lis.length() > 0);
    }
    std::cout << "Hello World" << std::endl;
}
