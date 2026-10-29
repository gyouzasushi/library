#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "atcoder/scc"
#include "graph/lowlink.hpp"
#include "graph/quotient_graph.hpp"
int main() {
    std::mt19937 rng(20261029);
    for (int trial = 0; trial < 2000; trial++) {
        int n = 1 + rng() % 8;
        int m = rng() % 16;
        atcoder::scc_graph sg(n);
        std::vector<std::vector<int>> g(n);
        std::vector<std::vector<bool>> reach(n, std::vector<bool>(n, false));
        for (int i = 0; i < n; i++) reach[i][i] = true;
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            sg.add_edge(u, v);
            g[u].push_back(v);
            reach[u][v] = true;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
        std::vector<std::vector<int>> scc = sg.scc();
        std::vector<int> id = component_id(n, scc);
        std::vector<std::vector<int>> dag = quotient_graph(g, scc);
        int k = int(scc.size());
        assert(int(dag.size()) == k);
        for (int u = 0; u < n; u++) {
            assert(0 <= id[u] && id[u] < k);
            for (int v = 0; v < n; v++) assert((id[u] == id[v]) == (reach[u][v] && reach[v][u]));
            for (int v : g[u]) assert(id[u] <= id[v]);
        }
        for (int i = 0; i < k; i++) {
            for (int v : scc[i]) assert(id[v] == i);
        }
        std::vector<std::set<int>> expect(k);
        for (int u = 0; u < n; u++) {
            for (int v : g[u]) {
                if (id[u] != id[v]) expect[id[u]].insert(id[v]);
            }
        }
        for (int i = 0; i < k; i++) {
            assert(dag[i] == std::vector<int>(expect[i].begin(), expect[i].end()));
            for (int j : dag[i]) assert(i < j);
        }
    }
    for (int trial = 0; trial < 2000; trial++) {
        int n = 1 + rng() % 8;
        int m = rng() % 12;
        lowlink lk(n);
        std::vector<std::vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            lk.add_edge(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        lk.build();
        std::vector<std::vector<int>> comps = lk.two_edge_connected_components();
        std::vector<int> id = component_id(n, comps);
        std::vector<std::vector<int>> tree = quotient_graph(g, comps);
        int k = int(comps.size());
        int edges = 0;
        for (int i = 0; i < k; i++) {
            edges += int(tree[i].size());
            for (int j : tree[i]) assert(std::ranges::binary_search(tree[j], i));
        }
        assert(edges == 2 * int(lk.bridges().size()));
        for (int v = 0; v < n; v++) assert(id[v] == lk.component(v));
    }
    std::cout << "Hello World\n";
}
