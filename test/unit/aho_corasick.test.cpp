#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "string/aho_corasick.hpp"
#include "string/trie.hpp"
std::string rand_str(std::mt19937& rng, int maxlen, int alpha) {
    int len = rng() % (maxlen + 1);
    std::string s;
    for (int i = 0; i < len; i++) s += char('a' + rng() % alpha);
    return s;
}
bool ends_with(const std::string& s, const std::string& p) {
    return p.size() <= s.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;
}
int main() {
    std::mt19937 rng(430);
    for (int it = 0; it < 500; it++) {
        int alpha = 1 + rng() % 3, m = rng() % 8;
        trie<3> t;
        std::vector<std::string> pats;
        std::vector<int> end;
        for (int i = 0; i < m; i++) {
            pats.push_back(rand_str(rng, 4, alpha));
            end.push_back(t.insert(pats.back()));
        }
        aho_corasick ac(t);
        assert(ac.size() == t.size());
        // order: increasing depth, starts with root
        const auto& ord = ac.order();
        assert(int(ord.size()) == t.size() && ord[0] == 0);
        for (int i = 1; i < int(ord.size()); i++) assert(t.depth(ord[i - 1]) <= t.depth(ord[i]));
        // fail: longest proper suffix that is a trie node
        std::vector<std::string> str(t.size());
        for (int v : ord) {
            if (v == 0) continue;
            int p = t.parent(v);
            for (int c = 0; c < 3; c++) {
                if (t.next(p, 'a' + c) == v) str[v] = str[p] + char('a' + c);
            }
        }
        for (int v = 0; v < t.size(); v++) {
            if (v == 0) {
                assert(ac.fail(v) == -1);
                continue;
            }
            int best = 0;
            for (int u = 0; u < t.size(); u++) {
                if (u != v && ends_with(str[v], str[u]) && str[u].size() > str[best].size()) best = u;
            }
            assert(ac.fail(v) == best);
            int c = 0;
            for (auto& p : pats) c += ends_with(str[v], p);
            assert(ac.count(v) == c);
        }
        // scan a text: state = longest suffix of the read prefix that is a trie node
        std::string s = rand_str(rng, 30, alpha);
        std::vector<long long> hit(t.size());
        std::vector<int> occ(m);
        int v = 0;
        long long total = 0;
        for (int i = 0; i < int(s.size()); i++) {
            v = ac.next(v, s[i]);
            hit[v]++;
            total += ac.count(v);
            std::string pre = s.substr(0, i + 1);
            int best = 0;
            for (int u = 0; u < t.size(); u++) {
                if (ends_with(pre, str[u]) && str[u].size() > str[best].size()) best = u;
            }
            assert(v == best);
            for (int j = 0; j < m; j++) occ[j] += ends_with(pre, pats[j]);
        }
        long long brute = 0;
        for (int j = 0; j < m; j++) brute += occ[j];
        assert(total == brute);
        for (int i = int(ord.size()) - 1; i >= 1; i--) hit[ac.fail(ord[i])] += hit[ord[i]];
        for (int j = 0; j < m; j++) assert(hit[end[j]] == occ[j]);
    }
    {
        // empty pattern matches at every position
        trie<2> t;
        t.insert(std::string());
        aho_corasick ac(t);
        assert(ac.size() == 1 && ac.count(0) == 1 && ac.next(0, 'a') == 0 && ac.next(0, 'b') == 0);
    }
    {
        // large: 2e5 patterns of length 5 over 26 letters, text 2e5
        trie<26> t;
        for (int i = 0; i < 200000; i++) t.insert(rand_str(rng, 5, 26) + "a");
        aho_corasick ac(t);
        int v = 0;
        long long total = 0;
        for (int i = 0; i < 200000; i++) {
            v = ac.next(v, 'a' + rng() % 26);
            total += ac.count(v);
        }
        assert(total >= 0);
    }
    std::cout << "Hello World" << std::endl;
}
