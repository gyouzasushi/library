#pragma once
#include <array>
#include <cassert>
#include <vector>
template <int log = 30> struct binary_trie {
    static_assert(1 <= log && log <= 62);

public:
    binary_trie() : ch(1, {-1, -1}), cnt(1, 0) {
    }
    int size() const {
        return cnt[0];
    }
    void insert(long long x, int k = 1) {
        assert(0 <= x && x < (1LL << log));
        assert(k >= 0);
        int v = 0;
        cnt[v] += k;
        for (int d = log - 1; d >= 0; d--) {
            int b = x >> d & 1;
            if (ch[v][b] == -1) {
                ch[v][b] = int(ch.size());
                ch.push_back({-1, -1});
                cnt.push_back(0);
            }
            v = ch[v][b];
            cnt[v] += k;
        }
    }
    void erase(long long x, int k = 1) {
        assert(0 <= x && x < (1LL << log));
        assert(0 <= k && k <= count(x));
        int v = 0;
        cnt[v] -= k;
        for (int d = log - 1; d >= 0; d--) {
            v = ch[v][x >> d & 1];
            cnt[v] -= k;
        }
    }
    int count(long long x) const {
        assert(0 <= x && x < (1LL << log));
        int v = 0;
        for (int d = log - 1; d >= 0; d--) {
            v = ch[v][x >> d & 1];
            if (v == -1) return 0;
        }
        return cnt[v];
    }
    // #{ a : (a ^ xor_val) < upper }
    int count_less(long long upper, long long xor_val = 0) const {
        assert(0 <= xor_val && xor_val < (1LL << log));
        if (upper <= 0) return 0;
        if (upper >= (1LL << log)) return size();
        int v = 0, res = 0;
        for (int d = log - 1; d >= 0; d--) {
            int b = (upper >> d & 1), f = (xor_val >> d & 1);
            if (b) {
                int c = ch[v][f];
                if (c != -1) res += cnt[c];
            }
            v = ch[v][b ^ f];
            if (v == -1) break;
        }
        return res;
    }
    // k-th smallest (0-indexed) of { a ^ xor_val }
    long long kth_smallest(int k, long long xor_val = 0) const {
        assert(0 <= k && k < size());
        assert(0 <= xor_val && xor_val < (1LL << log));
        int v = 0;
        long long res = 0;
        for (int d = log - 1; d >= 0; d--) {
            int f = xor_val >> d & 1;
            int c = ch[v][f];
            int c_cnt = c == -1 ? 0 : cnt[c];
            if (k < c_cnt) {
                v = c;
            } else {
                k -= c_cnt;
                v = ch[v][f ^ 1];
                res |= 1LL << d;
            }
        }
        return res;
    }
    long long kth_largest(int k, long long xor_val = 0) const {
        assert(0 <= k && k < size());
        return kth_smallest(size() - 1 - k, xor_val);
    }
    long long min(long long xor_val = 0) const {
        return kth_smallest(0, xor_val);
    }
    long long max(long long xor_val = 0) const {
        return kth_smallest(size() - 1, xor_val);
    }

private:
    std::vector<std::array<int, 2>> ch;
    std::vector<int> cnt;
};
