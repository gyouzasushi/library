#pragma once
#include <cassert>
#include <vector>
struct quotient_block {
    long long l, r, q;
};
std::vector<quotient_block> quotient_blocks(long long n) {
    assert(n >= 0);
    std::vector<quotient_block> ret;
    for (long long l = 1; l <= n;) {
        long long q = n / l, r = n / q + 1;
        ret.push_back({l, r, q});
        l = r;
    }
    return ret;
}
