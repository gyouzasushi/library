#pragma once
#include <array>
#include <cassert>
#include <vector>

#include "string/trie.hpp"
template <int sigma = 26, int base = 'a'> struct aho_corasick {
    explicit aho_corasick(const trie<sigma, base>& t) : _n(t.size()), nxt(_n), fl(_n, -1), cnt(_n) {
        ord.reserve(_n);
        ord.push_back(0);
        for (int i = 0; i < _n; i++) {
            int v = ord[i];
            cnt[v] = t.count(v) + (v == 0 ? 0 : cnt[fl[v]]);
            for (int c = 0; c < sigma; c++) {
                int w = t.next(v, base + c);
                if (w == -1) {
                    nxt[v][c] = v == 0 ? 0 : nxt[fl[v]][c];
                } else {
                    nxt[v][c] = w;
                    fl[w] = v == 0 ? 0 : nxt[fl[v]][c];
                    ord.push_back(w);
                }
            }
        }
        assert(int(ord.size()) == _n);
    }
    int size() const {
        return _n;
    }
    int next(int v, int c) const {
        assert(0 <= v && v < _n);
        int x = c - base;
        assert(0 <= x && x < sigma);
        return nxt[v][x];
    }
    int fail(int v) const {
        assert(0 <= v && v < _n);
        return fl[v];
    }
    int count(int v) const {
        assert(0 <= v && v < _n);
        return cnt[v];
    }
    const std::vector<int>& order() const {
        return ord;
    }

  private:
    int _n;
    std::vector<std::array<int, sigma>> nxt;
    std::vector<int> fl, cnt, ord;
};
