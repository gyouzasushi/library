#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

#include "graph/subtree_classify.hpp"
// AHU canonical string of the subtree rooted at u
std::string canon(const std::vector<std::vector<int>>& ch, int u) {
    std::vector<std::string> s;
    for (int v : ch[u]) s.push_back(canon(ch, v));
    std::sort(s.begin(), s.end());
    std::string res = "(";
    for (auto& t : s) res += t;
    return res + ")";
}
void check(const std::vector<int>& a, const std::vector<std::vector<int>>& ch, int root) {
    int n = int(ch.size());
    std::vector<std::string> c(n);
    std::vector<int> order{root};
    for (int i = 0; i < int(order.size()); i++)
        for (int v : ch[order[i]]) order.push_back(v);
    for (int u : order) c[u] = canon(ch, u);
    std::map<std::string, int> cls;
    for (int u = 0; u < n; u++) cls.emplace(c[u], 0);
    int k = int(cls.size());
    assert(*std::max_element(a.begin(), a.end()) == k - 1);
    assert(*std::min_element(a.begin(), a.end()) == 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) assert((a[i] == a[j]) == (c[i] == c[j]));
}
int main() {
    std::mt19937 rng(20261027);
    for (int iter = 0; iter < 3000; iter++) {
        int n = 1 + rng() % 9;
        int root = rng() % n;
        // random labelled tree via random parent in a random order
        std::vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;
        std::shuffle(perm.begin(), perm.end(), rng);
        std::swap(perm[0], *std::find(perm.begin(), perm.end(), root));
        std::vector<std::vector<int>> ch(n), und(n);
        for (int i = 1; i < n; i++) {
            int p = perm[rng() % i], v = perm[i];
            ch[p].push_back(v);
            und[p].push_back(v);
            und[v].push_back(p);
        }
        for (auto& l : und) std::shuffle(l.begin(), l.end(), rng);
        std::vector<int> a = subtree_classify(ch, root);
        check(a, ch, root);
        check(subtree_classify(und, root), ch, root);
    }
    {
        // path of length 2e5: no recursion depth issue
        int n = 200000;
        std::vector<std::vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[i - 1].push_back(i);
            g[i].push_back(i - 1);
        }
        std::vector<int> a = subtree_classify(g);
        for (int i = 0; i < n; i++) assert(a[i] == n - 1 - i);
    }
    {
        // star: all leaves in one class
        int n = 100000;
        std::vector<std::vector<int>> g(n);
        for (int i = 1; i < n; i++) g[0].push_back(i);
        std::vector<int> a = subtree_classify(g);
        assert(a[0] == 1);
        for (int i = 1; i < n; i++) assert(a[i] == 0);
    }
    {
        std::vector<int> a = subtree_classify(std::vector<std::vector<int>>(1));
        assert((a == std::vector<int>{0}));
    }
    std::cout << "Hello World" << std::endl;
}
