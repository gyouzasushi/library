#pragma once
#include <array>
#include <cassert>
#include <vector>
template <int sigma = 26, int base = 'a'> struct trie {
    static_assert(sigma >= 1);

public:
    trie() : ch(1), par(1, -1), dep(1, 0), cnt(1, 0), cnt_prefix(1, 0) {
        ch[0].fill(-1);
    }
    int size() const {
        return int(ch.size());
    }
    template <class Seq> int insert(const Seq& s) {
        int v = 0;
        cnt_prefix[v]++;
        for (auto c : s) {
            int x = int(c) - base;
            assert(0 <= x && x < sigma);
            if (ch[v][x] == -1) {
                ch[v][x] = size();
                ch.emplace_back().fill(-1);
                par.push_back(v);
                dep.push_back(dep[v] + 1);
                cnt.push_back(0);
                cnt_prefix.push_back(0);
            }
            v = ch[v][x];
            cnt_prefix[v]++;
        }
        cnt[v]++;
        return v;
    }
    template <class Seq> void erase(const Seq& s) {
        int t = find(s);
        assert(t != -1 && cnt[t] > 0);
        cnt[t]--;
        for (int v = t; v != -1; v = par[v]) cnt_prefix[v]--;
    }
    template <class Seq> int find(const Seq& s) const {
        int v = 0;
        for (auto c : s) {
            v = next(v, int(c));
            if (v == -1) return -1;
        }
        return v;
    }
    int next(int v, int c) const {
        assert(0 <= v && v < size());
        int x = c - base;
        assert(0 <= x && x < sigma);
        return ch[v][x];
    }
    int parent(int v) const {
        assert(0 <= v && v < size());
        return par[v];
    }
    int depth(int v) const {
        assert(0 <= v && v < size());
        return dep[v];
    }
    int count(int v) const {
        assert(0 <= v && v < size());
        return cnt[v];
    }
    int count_prefix(int v) const {
        assert(0 <= v && v < size());
        return cnt_prefix[v];
    }

private:
    std::vector<std::array<int, sigma>> ch;
    std::vector<int> par, dep, cnt, cnt_prefix;
};
