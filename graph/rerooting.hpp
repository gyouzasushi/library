#pragma once
template <typename T, T (*f1)(T, int, int), T (*f2)(T, int), T (*merge)(T, T),
          T (*e)()>
struct ReRooting {
    // dp_v = f2(merge(f1(dp_c1,v,c1), f1(dp_c2,v,c2), ..., f1(dp_ck,v,ck)) , v)
public:
    ReRooting() : ReRooting(0) {
    }
    ReRooting(int n) : n(n), g(n), dp(n) {
    }
    void add_edge(int from, int to) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back(to);
        g[to].push_back(from);
    }

    void build(int root = 0) {
        for (int i = 0; i < n; i++) {
            int deg = int(g[i].size());
            dp[i].resize(deg);
        }
        auto dfs1 = [&](auto dfs1, int pos, int pre) -> T {
            T ret = e();
            int deg = int(g[pos].size());
            for (int i = 0; i < deg; i++) {
                int nxt = g[pos][i];
                if (nxt == pre) continue;
                dp[pos][i] = dfs1(dfs1, nxt, pos);
                ret = merge(ret, f1(dp[pos][i], pos, nxt));
            }
            return f2(ret, pos);
        };
        auto dfs2 = [&](auto dfs2, int pos, int pre, const T &top) -> void {
            int deg = int(g[pos].size());
            vector<T> sum_left(deg + 1, e()), sum_right(deg + 1, e());
            for (int i = 0; i < deg; i++) {
                int nxt = g[pos][i];
                T tmp = (nxt == pre ? dp[pos][i] = top : dp[pos][i]);
                sum_left[i + 1] = merge(sum_left[i], f1(tmp, pos, nxt));
            }
            for (int i = deg; i > 0; i--) {
                int nxt = g[pos][i - 1];
                T tmp = (nxt == pre ? dp[pos][i - 1] = top : dp[pos][i - 1]);
                sum_right[i - 1] = merge(sum_right[i], f1(tmp, pos, nxt));
            }
            for (int i = 0; i < deg; i++) {
                int nxt = g[pos][i];
                if (nxt == pre) continue;
                T tmp = merge(sum_left[i], sum_right[i + 1]);
                dfs2(dfs2, nxt, pos, f2(tmp, pos));
            }
        };
        dfs1(dfs1, root, -1);
        dfs2(dfs2, root, -1, e());
    }

    T solve(int pos) {
        T ans = e();
        int deg = int(g[pos].size());
        for (int i = 0; i < deg; i++) {
            int nxt = g[pos][i];
            ans = merge(ans, f1(dp[pos][i], pos, nxt));
        }
        return f2(ans, pos);
    }

private:
    int n;
    vector<vector<int>> g;
    vector<vector<T>> dp;
};