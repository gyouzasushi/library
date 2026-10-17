#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
struct heavy_light_decomposition {
public:
    heavy_light_decomposition() {
    }
    heavy_light_decomposition(int n, int root = 0)
        : _n(n),
          _root(root),
          g(n),
          sz(n),
          dep(n),
          par(n),
          heavy(n, -1),
          head(n),
          in(n),
          out(n),
          rev(n) {
    }
    void add_edge(int u, int v) {
        assert(0 <= u && u < _n);
        assert(0 <= v && v < _n);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build() {
        par[_root] = -1;
        dep[_root] = 0;
        std::vector<int> order, st = {_root};
        order.reserve(_n);
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            order.push_back(v);
            for (int c : g[v]) {
                if (c == par[v]) continue;
                par[c] = v;
                dep[c] = dep[v] + 1;
                st.push_back(c);
            }
        }
        for (int i = _n - 1; i >= 0; i--) {
            int v = order[i], p = par[v];
            sz[v]++;
            if (p == -1) continue;
            sz[p] += sz[v];
            if (heavy[p] == -1 || sz[v] > sz[heavy[p]]) heavy[p] = v;
        }
        int t = 0;
        head[_root] = _root;
        st = {_root};
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            in[v] = t++;
            rev[in[v]] = v;
            out[v] = in[v] + sz[v];
            for (int c : g[v]) {
                if (c == par[v] || c == heavy[v]) continue;
                head[c] = c;
                st.push_back(c);
            }
            if (heavy[v] != -1) {
                head[heavy[v]] = head[v];
                st.push_back(heavy[v]);
            }
        }
    }

    int index(int v) const {
        return in[v];
    }
    int vertex(int i) const {
        return rev[i];
    }
    std::pair<int, int> subtree(int v) const {
        return {in[v], out[v]};
    }
    int depth(int v) const {
        return dep[v];
    }
    int parent(int v) const {
        return par[v];
    }
    int head_of(int v) const {
        return head[v];
    }
    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (dep[head[u]] < dep[head[v]]) std::swap(u, v);
            u = par[head[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    int lca(int u, int v, int r) const {
        return lca(u, v) ^ lca(v, r) ^ lca(r, u);
    }
    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    int la(int v, int k) const {
        if (k < 0 || dep[v] < k) return -1;
        while (dep[v] - dep[head[v]] < k) {
            k -= dep[v] - dep[head[v]] + 1;
            v = par[head[v]];
        }
        return rev[in[v] - k];
    }
    int jump(int s, int t, int k) const {
        int l = lca(s, t);
        int d = dep[s] + dep[t] - 2 * dep[l];
        if (k < 0 || d < k) return -1;
        if (k <= dep[s] - dep[l]) return la(s, k);
        return la(t, d - k);
    }
    bool in_subtree(int u, int v) const {
        return in[u] <= in[v] && in[v] < out[u];
    }
    bool on_path(int s, int t, int x) const {
        return dist(s, x) + dist(x, t) == dist(s, t);
    }

    template <typename F>
    void for_each_vertex(int u, int v, const F& f) const {
        for_each(u, v, false, f);
    }
    template <typename F>
    void for_each_edge(int u, int v, const F& f) const {
        for_each(u, v, true, f);
    }
    template <typename F>
    void for_each_vertex_noncommutative(int u, int v, const F& f) const {
        for_each_noncommutative(u, v, false, f);
    }
    template <typename F>
    void for_each_edge_noncommutative(int u, int v, const F& f) const {
        for_each_noncommutative(u, v, true, f);
    }
    template <typename F>
    void for_each_vertex_in_subtree(int v, const F& f) const {
        f(in[v], out[v]);
    }
    template <typename F>
    void for_each_edge_in_subtree(int v, const F& f) const {
        if (in[v] + 1 < out[v]) f(in[v] + 1, out[v]);
    }

private:
    int _n, _root;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, dep, par, heavy, head, in, out, rev;
    template <typename F>
    void for_each(int u, int v, bool edge, const F& f) const {
        while (head[u] != head[v]) {
            if (dep[head[u]] < dep[head[v]]) std::swap(u, v);
            f(in[head[u]], in[u] + 1);
            u = par[head[u]];
        }
        if (dep[u] > dep[v]) std::swap(u, v);
        if (in[u] + edge < in[v] + 1) f(in[u] + edge, in[v] + 1);
    }
    template <typename F>
    void for_each_noncommutative(int u, int v, bool edge, const F& f) const {
        std::vector<std::pair<int, int>> down;
        while (head[u] != head[v]) {
            if (dep[head[u]] >= dep[head[v]]) {
                f(in[u] + 1, in[head[u]]);
                u = par[head[u]];
            } else {
                down.emplace_back(in[head[v]], in[v] + 1);
                v = par[head[v]];
            }
        }
        if (dep[u] > dep[v]) {
            if (in[v] + edge < in[u] + 1) f(in[u] + 1, in[v] + edge);
        } else {
            if (in[u] + edge < in[v] + 1) f(in[u] + edge, in[v] + 1);
        }
        for (auto it = down.rbegin(); it != down.rend(); it++) {
            f(it->first, it->second);
        }
    }
};
