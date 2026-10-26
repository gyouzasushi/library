#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "string/trie.hpp"

std::string rand_str(std::mt19937& rng, int maxlen, int alpha) {
    int len = rng() % (maxlen + 1);
    std::string s;
    for (int i = 0; i < len; i++) s += char('a' + rng() % alpha);
    return s;
}
bool is_prefix(const std::string& p, const std::string& s) {
    return p.size() <= s.size() && s.compare(0, p.size(), p) == 0;
}

int main() {
    std::mt19937 rng(4242);
    // multiset semantics vs brute force
    for (int it = 0; it < 200; it++) {
        trie<3> t;
        std::vector<std::string> ms;
        for (int q = 0; q < 60; q++) {
            std::string s = rand_str(rng, 5, 3);
            if (rng() % 3 != 0 || ms.empty()) {
                int v = t.insert(s);
                ms.push_back(s);
                assert(t.find(s) == v && t.depth(v) == int(s.size()));
            } else {
                std::string e = ms[rng() % ms.size()];
                t.erase(e);
                ms.erase(std::find(ms.begin(), ms.end(), e));
            }
            std::string p = rand_str(rng, 5, 3);
            int v = t.find(p);
            int exact = int(std::count(ms.begin(), ms.end(), p));
            int pref = int(std::count_if(ms.begin(), ms.end(), [&](const std::string& x) { return is_prefix(p, x); }));
            if (v == -1) {
                assert(pref == 0);
            } else {
                assert(t.count(v) == exact);
                assert(t.count_prefix(v) == pref);
                assert(t.depth(v) == int(p.size()));
                // walk by next from the root reaches the same node, parent walks back
                int w = 0;
                for (char c : p) w = t.next(w, c);
                assert(w == v);
                int up = v;
                for (size_t i = 0; i < p.size(); i++) up = t.parent(up);
                assert(up == 0 && t.parent(0) == -1);
            }
        }
        assert(t.count_prefix(0) == int(ms.size()));
    }
    // ABC353 E: sum of LCP over pairs = sum over nodes of C(count_prefix, 2)
    for (int it = 0; it < 50; it++) {
        int n = 1 + rng() % 8;
        std::vector<std::string> s(n);
        trie<26> t;
        for (auto& x : s) x = rand_str(rng, 6, 2), t.insert(x);
        long long brute = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                size_t k = 0;
                while (k < s[i].size() && k < s[j].size() && s[i][k] == s[j][k]) k++;
                brute += k;
            }
        }
        long long got = 0;
        for (int v = 1; v < t.size(); v++) got += (long long)t.count_prefix(v) * (t.count_prefix(v) - 1) / 2;
        assert(got == brute);
    }
    // ABC377 G: min over X in {"", S_1..S_{k-1}} of |T| + |X| - 2 LCP(T, X), with per-node side data
    for (int it = 0; it < 50; it++) {
        int n = 1 + rng() % 8;
        std::vector<std::string> s(n);
        for (auto& x : s) x = rand_str(rng, 6, 2);
        trie<26> t;
        std::vector<int> min_len = {0};  // min length of inserted strings in the subtree; root: "" allowed
        for (int k = 0; k < n; k++) {
            const std::string& T = s[k];
            int brute = int(T.size());
            for (int i = 0; i < k; i++) {
                size_t l = 0;
                while (l < T.size() && l < s[i].size() && T[l] == s[i][l]) l++;
                brute = std::min(brute, int(T.size() + s[i].size() - 2 * l));
            }
            int got = int(T.size());
            int v = 0;
            for (size_t j = 0; j <= T.size(); j++) {
                got = std::min(got, int(T.size() - j) + min_len[v] - int(j));
                if (j == T.size() || (v = t.next(v, T[j])) == -1) break;
            }
            assert(got == brute);
            int e = t.insert(T);
            min_len.resize(t.size(), 1 << 30);
            for (int u = e; u != 0; u = t.parent(u)) min_len[u] = std::min(min_len[u], int(T.size()));
        }
    }
    // integer sequences
    {
        trie<10, 0> t;
        std::vector<int> a = {3, 1, 4}, b = {3, 1}, c = {3, 1, 5};
        int va = t.insert(a), vb = t.insert(b);
        assert(t.find(c) == -1 && t.find(b) == vb && t.parent(va) == vb);
        assert(t.count_prefix(vb) == 2 && t.count(vb) == 1 && t.count_prefix(0) == 2);
        assert(t.next(vb, 4) == va && t.next(vb, 5) == -1);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
