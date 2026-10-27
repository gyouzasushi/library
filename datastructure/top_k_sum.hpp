#pragma once
#include <cassert>
#include <functional>
#include <queue>
#include <vector>
template <class T, class Compare = std::greater<T>>
struct top_k_sum {
public:
    explicit top_k_sum(int k) : _k(k), _sum(T()) {
        assert(k >= 0);
    }
    void insert(const T& x) {
        in.push(x);
        _sum += x;
        modify();
    }
    void erase(const T& x) {
        assert(size() > 0);
        if (!in.empty() && in.top() == x) {
            _sum -= x;
            in.pop();
        } else if (!in.empty() && Compare()(x, in.top())) {
            _sum -= x;
            d_in.push(x);
        } else {
            d_out.push(x);
        }
        modify();
    }
    void set_k(int k) {
        assert(k >= 0);
        _k = k;
        modify();
    }
    int k() const {
        return _k;
    }
    T sum() const {
        return _sum;
    }
    int size() const {
        return int(in.size() + out.size() - d_in.size() - d_out.size());
    }

private:
    struct reverse_compare {
        bool operator()(const T& a, const T& b) const {
            return Compare()(b, a);
        }
    };
    std::priority_queue<T, std::vector<T>, Compare> in, d_in;
    std::priority_queue<T, std::vector<T>, reverse_compare> out, d_out;
    int _k;
    T _sum;
    int in_size() const {
        return int(in.size() - d_in.size());
    }
    void modify() {
        while (in_size() < _k && !out.empty()) {
            T p = out.top();
            out.pop();
            if (!d_out.empty() && p == d_out.top()) {
                d_out.pop();
            } else {
                _sum += p;
                in.push(p);
            }
        }
        while (in_size() > _k) {
            T p = in.top();
            in.pop();
            if (!d_in.empty() && p == d_in.top()) {
                d_in.pop();
            } else {
                _sum -= p;
                out.push(p);
            }
        }
        while (!d_in.empty() && in.top() == d_in.top()) {
            in.pop();
            d_in.pop();
        }
    }
};
