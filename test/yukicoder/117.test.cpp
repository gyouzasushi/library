#define PROBLEM "https://yukicoder.me/problems/no/117"
#include <atcoder/modint>
#include <cstdio>

#include "math/binomial_coefficient.hpp"
int main() {
    using binom = binomial_coefficient<atcoder::modint1000000007>;
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        char c;
        int n, k;
        scanf("\n%c(%d,%d)", &c, &n, &k);
        if (c == 'C') printf("%d\n", binom::C(n, k).val());
        if (c == 'P') printf("%d\n", binom::P(n, k).val());
        if (c == 'H') printf("%d\n", binom::H(n, k).val());
    }
}
