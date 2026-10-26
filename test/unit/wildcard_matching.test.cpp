#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "string/wildcard_matching.hpp"

template <class Seq, class T>
std::vector<bool> brute(const Seq& s, const Seq& t, T wildcard) {
    int n = s.size(), m = t.size();
    if (m > n) return {};
    std::vector<bool> res(n - m + 1, true);
    for (int i = 0; i < n - m + 1; i++)
        for (int j = 0; j < m; j++)
            if (s[i + j] != t[j] && s[i + j] != wildcard && t[j] != wildcard) res[i] = false;
    return res;
}

int main() {
    std::mt19937 rng(2231);
    for (int it = 0; it < 2000; it++) {
        int n = rng() % 12, m = rng() % 12, k = 1 + rng() % 4;
        std::string s(n, ' '), t(m, ' ');
        for (auto& c : s) c = rng() % 3 == 0 ? '?' : 'a' + rng() % k;
        for (auto& c : t) c = rng() % 3 == 0 ? '?' : 'a' + rng() % k;
        assert(wildcard_matching(s, t) == brute(s, t, '?'));
        std::vector<int> a(n), b(m);
        for (auto& x : a) x = rng() % 3 == 0 ? -1 : (int)(rng() % k) * 1000000;
        for (auto& x : b) x = rng() % 3 == 0 ? -1 : (int)(rng() % k) * 1000000;
        assert(wildcard_matching(a, b, -1) == brute(a, b, -1));
    }
    // full ASCII alphabet, long strings
    {
        int n = 300000, m = 100000;
        std::string s(n, ' '), t(m, ' ');
        for (auto& c : s) c = 33 + rng() % 94;
        for (auto& c : t) c = rng() % 2 ? '*' : 33 + rng() % 94;
        auto res = wildcard_matching(s, t, '*');
        assert((int)res.size() == n - m + 1);
        for (int j = 0; j < m; j++) if (t[j] != '*') s[1234 + j] = t[j];
        res = wildcard_matching(s, t, '*');
        assert(res[1234]);
    }
    std::cout << "Hello World" << std::endl;
}
