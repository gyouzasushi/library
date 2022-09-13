#include <algorithm>
#include <limits>
struct DynamicLiChaoTree {
public:
    DynamicLiChaoTree(long long min_index = -1'000'000'000,
                      long long max_index = 1'000'000'000)
        : min_index(min_index), max_index(max_index + 1), root(nullptr) {
    }
    void add_line(long long a, long long b) {
        Line line = Line{a, b};
        add_line(root, min_index, max_index, line);
    }
    void add_segment(long long a, long long b, long long l_lim,
                     long long r_lim) {
        Line line = Line{a, b};
        add_segment(root, l_lim, r_lim, min_index, max_index, line);
    }
    long long get(long long x) {
        node* t = root;
        long long l = min_index, r = max_index;
        long long ret = std::numeric_limits<long long>::max();
        while (r - l > 0 && t != nullptr) {
            long long m = (l + r) >> 1;
            ret = std::min(ret, t->line.f(x));
            if (x < m) {
                r = m;
                t = t->left;
            } else {
                l = m;
                t = t->right;
            }
        }
        return ret;
    }

private:
    struct Line {
        long long slope, intercept;
        Line() : slope(0), intercept(std::numeric_limits<long long>::max()) {
        }
        Line(long long a, long long b) : slope(a), intercept(b) {
        }
        long long f(long long x) {
            return slope * x + intercept;
        }
    };
    struct node {
        Line line;
        node *left, *right;
        node(Line line) : line(line), left(nullptr), right(nullptr) {
        }
    };
    const long long min_index, max_index;
    node* root;
    node* add_line(node*& t, long long l, long long r, Line line) const {
        if (l == r) return nullptr;
        if (!t) {
            t = new node(line);
            return t;
        }
        long long m = (l + r) >> 1;
        bool check_l = (line.f(l) <= t->line.f(l));
        bool check_m = (line.f(m) <= t->line.f(m));
        bool check_r = (line.f(r) <= t->line.f(r));
        if (check_l && check_r) {
            t->line = line;
            return t;
        }
        if (!check_l && !check_r) {
            return t;
        }
        if (check_m) {
            std::swap(t->line, line);
        }
        if (check_l != check_m) {
            t->left = add_line(t->left, l, m, line);
        } else {
            t->right = add_line(t->right, m + 1, r, line);
        }
        return t;
    }
    node* add_segment(node*& t, long long l_lim, long long r_lim, long long l,
                      long long r, Line line) {
        if (r <= l_lim || r_lim <= l) return t;
        if (l_lim <= l && r <= r_lim) return add_line(t, l, r, line);
        if (t == nullptr) t = new node(Line());
        long long m = (l + r) >> 1;
        t->left = add_segment(t->left, l_lim, r_lim, l, m, line);
        t->right = add_segment(t->right, l_lim, r_lim, m, r, line);
        return t;
    }
};