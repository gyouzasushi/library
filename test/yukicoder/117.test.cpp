#define PROBLEM "https://yukicoder.me/problems/no/117"
#include <atcoder/modint>
#include <cstdio>

#include "math/combinatorics.hpp"
int main() {
    using cb = combinatorics<atcoder::modint1000000007>;
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        char c;
        int n, k;
        scanf("\n%c(%d,%d)", &c, &n, &k);
        if (c == 'C') printf("%d\n", cb::C(n, k).val());
        if (c == 'P') printf("%d\n", cb::P(n, k).val());
        if (c == 'H') printf("%d\n", cb::H(n, k).val());
    }
}
