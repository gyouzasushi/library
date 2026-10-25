#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include <optional>
#include <random>
#include <vector>

#include "algebra/group_add.hpp"
#include "algebra/group_xor.hpp"
#include "datastructure/weighted_dsu.hpp"

// brute force: potentials via BFS over accepted constraints
template <class G> struct brute {
    using S = typename G::S;
    int n;
    std::vector<std::vector<std::pair<int, S>>> g;  // (to, diff(from, to))
    explicit brute(int n) : n(n), g(n) {
    }
    std::vector<std::optional<S>> potentials(int s) {
        std::vector<std::optional<S>> p(n);
        p[s] = G::e();
        std::vector<int> st = {s};
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            for (auto [u, w] : g[v]) {
                if (p[u]) continue;
                p[u] = G::op(*p[v], w);
                st.push_back(u);
            }
        }
        return p;
    }
    bool merge(int a, int b, S w) {
        auto p = potentials(a);
        if (p[b]) return *p[b] == w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, G::inv(w));
        return true;
    }
    std::optional<S> diff(int a, int b) {
        return potentials(a)[b];
    }
};

template <class G> void run(std::mt19937& rng, auto gen) {
    for (int it = 0; it < 300; it++) {
        int n = 1 + rng() % 8;
        weighted_dsu<G> d(n);
        brute<G> b(n);
        for (int q = 0; q < 30; q++) {
            int x = rng() % n, y = rng() % n;
            if (rng() % 2) {
                auto w = gen();
                assert(d.merge(x, y, w) == b.merge(x, y, w));
            } else {
                auto r = b.diff(x, y);
                assert(d.same(x, y) == r.has_value());
                if (r) assert(d.diff(x, y) == *r);
            }
        }
        auto groups = d.groups();
        int total = 0;
        for (auto& grp : groups) {
            for (int v : grp) assert(d.leader(v) == d.leader(grp[0])), assert(d.size(v) == int(grp.size()));
            total += int(grp.size());
        }
        assert(total == n);
    }
}

// non-commutative: affine maps x -> a x + b over a prime field (a != 0)
struct group_affine {
    static constexpr long long p = 1000003;
    struct S {
        long long a, b;
        bool operator==(const S&) const = default;
    };
    static long long pw(long long a, long long n) {
        long long r = 1;
        a %= p;
        while (n) {
            if (n & 1) r = r * a % p;
            a = a * a % p;
            n >>= 1;
        }
        return r;
    }
    static S op(S f, S g) {  // f after g: f(g(x))
        return {f.a * g.a % p, (f.a * g.b + f.b) % p};
    }
    static S e() {
        return {1, 0};
    }
    static S inv(S f) {
        long long ia = pw(f.a, p - 2);
        return {ia, (p - ia * f.b % p) % p};
    }
};

int main() {
    std::mt19937 rng(2024);
    run<group_add<long long>>(rng, [&] { return (long long)(rng() % 21) - 10; });
    run<group_xor<int>>(rng, [&] { return int(rng() % 16); });
    run<group_affine>(rng, [&] { return group_affine::S{1 + (long long)(rng() % 5), (long long)(rng() % 7)}; });
    // contradiction leaves the structure unchanged
    {
        weighted_dsu<group_add<long long>> d(3);
        assert(d.merge(0, 1, 5));
        assert(d.merge(1, 2, 7));
        assert(d.diff(0, 2) == 12 && d.diff(2, 0) == -12);
        assert(!d.merge(0, 2, 13));
        assert(d.merge(0, 2, 12));
        assert(d.size(0) == 3);
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
