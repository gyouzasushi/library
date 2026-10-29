#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

#include "string/rolling_hash.hpp"
#include "string/string_hash.hpp"
#include "algebra/range_assign_range_hash.hpp"
#include "datastructure/lazy_segtree.hpp"
int brute_cmp(const std::string& a, const std::string& b) {
    return a < b ? -1 : a == b ? 0 : 1;
}
int brute_lcp(const std::string& a, const std::string& b) {
    int i = 0;
    while (i < int(a.size()) && i < int(b.size()) && a[i] == b[i]) i++;
    return i;
}
int main() {
    std::mt19937 rng(7959);
    for (int trial = 0; trial < 200; trial++) {
        int n = 1 + rng() % 12, m = 1 + rng() % 12;
        int sigma = 1 + rng() % 3;
        std::string s(n, 'a'), t(m, 'a');
        for (auto& c : s) c = 'a' + rng() % sigma;
        for (auto& c : t) c = 'a' + rng() % sigma;
        rolling_hash<> rs(s);
        using A = range_assign_range_hash<>;
        std::vector<A::S> init;
        for (char c : t) init.push_back(A::from(c));
        lazy_segtree<A> rt(init);
        assert(rs.size() == n);
        for (int q = 0; q < 30; q++) {
            if (rng() % 3 == 0) {
                int l = rng() % (m + 1), r = rng() % (m + 1);
                if (l > r) std::swap(l, r);
                char c = 'a' + rng() % sigma;
                rt.apply(l, r, c);
                for (int i = l; i < r; i++) t[i] = c;
            } else if (rng() % 3 == 0) {
                int p = rng() % m;
                char c = 'a' + rng() % sigma;
                rt.set(p, A::from(c));
                t[p] = c;
            }
            int l1 = rng() % (n + 1), r1 = rng() % (n + 1);
            if (l1 > r1) std::swap(l1, r1);
            int l2 = rng() % (m + 1), r2 = rng() % (m + 1);
            if (l2 > r2) std::swap(l2, r2);
            std::string a = s.substr(l1, r1 - l1), b = t.substr(l2, r2 - l2);
            assert((rs.prod(l1, r1) == rt.prod(l2, r2)) == (a == b));
            assert(lcp(rs, l1, r1, rt, l2, r2) == brute_lcp(a, b));
            assert(compare(rs, l1, r1, rt, l2, r2) == brute_cmp(a, b));
            assert(compare(rt, l2, r2, rs, l1, r1) == brute_cmp(b, a));
            int l3 = rng() % (n + 1), r3 = rng() % (n + 1);
            if (l3 > r3) std::swap(l3, r3);
            std::string c = s.substr(l3, r3 - l3);
            assert(compare(rs, l1, r1, rs, l3, r3) == brute_cmp(a, c));
            assert(lcp(rs, l1, r1, rs, l3, r3) == brute_lcp(a, c));
            assert(rs.prod(l1, r1) + rs.prod(l3, r3) == rolling_hash<>(a + c).all_prod());
            assert(rs.prod(l1, r1) + rt.prod(l2, r2) == rolling_hash<>(a + b).all_prod());
            if (l1 < r1) assert(rs.get(l1) == string_hash<>(s[l1]));
            assert(rt.all_prod() == rolling_hash<>(t).all_prod());
            assert(rt.prod(l2, r2) == rolling_hash<>(b).all_prod());
        }
        {
            std::string r(n, 'a');
            char c = 'a' + rng() % sigma;
            for (auto& x : r) x = c;
            assert(string_hash<>::repeat(c, n) == rolling_hash<>(r).all_prod());
        }
        {
            std::set<string_hash<>> hs;
            std::set<std::string> ss;
            for (int l = 0; l <= n; l++)
                for (int r = l; r <= n; r++) hs.insert(rs.prod(l, r)), ss.insert(s.substr(l, r - l));
            assert(hs.size() == ss.size());
        }
    }
    {
        rolling_hash<2> rh(std::vector<int>{1, 2, 3});
        assert(rh.prod(0, 2) + rh.prod(2, 3) == rh.all_prod());
        assert(rh.prod(0, 0) == string_hash<2>());
        assert(rolling_hash<2>(std::string("")).all_prod() == string_hash<2>());
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
