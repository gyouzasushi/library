#pragma once
#include <vector>
template <typename T>
struct ConvexHullTrickAddMonotone {
public:
    ConvexHullTrickAddMonotone() : pos(0) {
    }
    struct F {
        T a, b;
    };
    void add_line(T a, T b) {
        F f = {a, b};
        while (int(q.size()) >= 2 &&
               check(q[int(q.size()) - 2], q[int(q.size()) - 1], f)) {
            q.pop_back();
        }
        q.push_back(f);
    }
    T get_min(T x) {
        while (pos + 1 < int(q.size()) && f(q[pos], x) >= f(q[pos + 1], x)) {
            pos++;
        }
        return f(q[pos], x);
    }

private:
    int pos;
    std::vector<F> q;
    bool check(F f1, F f2, F f3) {
        return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);
    }
    T f(F _f, T x) {
        return _f.a * x + _f.b;
    }
};