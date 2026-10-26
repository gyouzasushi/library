#pragma once
#include <algorithm>
#include <cassert>
#include <optional>
#include <utility>
#include <vector>

template <class T> struct li_chao_tree {
    li_chao_tree(long long lo, long long hi) : lo(lo), hi(hi) {
        assert(lo < hi);
        make_node();
    }
    void add_line(T a, T b) { add_line(0, lo, hi, a, b); }
    void add_segment(T a, T b, long long l, long long r) {
        assert(lo <= l && l <= r && r <= hi);
        add_segment(0, lo, hi, l, r, a, b);
    }
    std::optional<T> min(long long x) const {
        assert(lo <= x && x < hi);
        std::optional<T> res;
        long long l = lo, r = hi;
        for (int t = 0; t != -1;) {
            const node& v = get(t);
            if (v.has) {
                T y = v.a * x + v.b;
                if (!res || y < *res) res = y;
            }
            long long m = l + (r - l) / 2;
            if (x < m) {
                r = m;
                t = v.left;
            } else {
                l = m;
                t = v.right;
            }
        }
        return res;
    }

  private:
    struct node {
        T a = 0, b = 0;
        bool has = false;
        int left = -1, right = -1;
    };
    static constexpr int chunk_log = 16;
    long long lo, hi;
    int num_nodes = 0;
    std::vector<std::vector<node>> chunks;
    node& get(int t) { return chunks[t >> chunk_log][t & ((1 << chunk_log) - 1)]; }
    const node& get(int t) const {
        return chunks[t >> chunk_log][t & ((1 << chunk_log) - 1)];
    }
    int make_node() {
        if ((num_nodes & ((1 << chunk_log) - 1)) == 0) {
            chunks.emplace_back();
            chunks.back().reserve(1 << chunk_log);
        }
        chunks.back().push_back({});
        return num_nodes++;
    }
    void add_line(int t, long long l, long long r, T a, T b) {
        while (true) {
            node& v = get(t);
            if (!v.has) {
                v.a = a, v.b = b, v.has = true;
                return;
            }
            bool left_better = a * l + b < v.a * l + v.b;
            bool right_better = a * (r - 1) + b < v.a * (r - 1) + v.b;
            if (left_better && right_better) {
                v.a = a, v.b = b;
                return;
            }
            if (!left_better && !right_better) return;
            long long m = l + (r - l) / 2;
            bool mid_better = a * m + b < v.a * m + v.b;
            if (mid_better) std::swap(v.a, a), std::swap(v.b, b);
            if (left_better != mid_better) {
                if (get(t).left == -1) get(t).left = make_node();
                t = get(t).left, r = m;
            } else {
                if (get(t).right == -1) get(t).right = make_node();
                t = get(t).right, l = m;
            }
        }
    }
    void add_segment(int t, long long l, long long r, long long ql, long long qr,
                     T a, T b) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            add_line(t, l, r, a, b);
            return;
        }
        long long m = l + (r - l) / 2;
        if (ql < m) {
            if (get(t).left == -1) get(t).left = make_node();
            add_segment(get(t).left, l, m, ql, qr, a, b);
        }
        if (m < qr) {
            if (get(t).right == -1) get(t).right = make_node();
            add_segment(get(t).right, m, r, ql, qr, a, b);
        }
    }
};
