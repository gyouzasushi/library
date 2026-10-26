#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "graph/chromatic_number.hpp"

int brute(int n, const std::vector<std::vector<int>>& g) {
    if (n == 0) return 0;
    for (int k = 1;; k++) {
        std::vector<int> c(n, -1);
        auto rec = [&](auto rec, int v) -> bool {
            if (v == n) return true;
            for (int col = 0; col < k; col++) {
                bool ok = true;
                for (int u : g[v])
                    if (c[u] == col) ok = false;
                if (!ok) continue;
                c[v] = col;
                if (rec(rec, v + 1)) return true;
                c[v] = -1;
            }
            return false;
        };
        if (rec(rec, 0)) return k;
    }
}

int main() {
    std::mt19937 rng(99);
    for (int it = 0; it < 300; it++) {
        int n = rng() % 9;
        int p = rng() % 101;
        std::vector<std::vector<int>> g(n);
        for (int u = 0; u < n; u++)
            for (int v = u + 1; v < n; v++)
                if ((int)(rng() % 100) < p) g[u].push_back(v), g[v].push_back(u);
        assert(chromatic_number(g) == brute(n, g));
    }
    // the user's atcoder::modint is untouched
    atcoder::modint::set_mod(998244353);
    chromatic_number({{1}, {0}});
    assert(atcoder::modint::mod() == 998244353);
    std::cout << "Hello World" << std::endl;
}
