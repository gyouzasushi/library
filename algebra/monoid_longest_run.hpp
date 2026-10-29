#pragma once
#include <algorithm>
template <class T>
struct monoid_longest_run {
    struct S {
        int len;
        T left, right;
        int left_run, right_run, longest;
    };
    static S op(S a, S b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        S c = {a.len + b.len, a.left, b.right, a.left_run, b.right_run, std::max(a.longest, b.longest)};
        if (a.right == b.left) {
            c.longest = std::max(c.longest, a.right_run + b.left_run);
            if (a.left_run == a.len) c.left_run = a.len + b.left_run;
            if (b.right_run == b.len) c.right_run = a.right_run + b.len;
        }
        return c;
    }
    static S e() {
        return {0, T(), T(), 0, 0, 0};
    }
    static S from(T c) {
        return {1, c, c, 1, 1, 1};
    }
};
