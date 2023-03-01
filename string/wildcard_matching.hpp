#pragma once
#include "math/convolution.hpp"
std::vector<bool> wildcard_matching(std::string s, std::string t) {
    int n = s.size(), m = t.size();
    assert(m > 0);
    assert(n >= m);
    std::vector<long long> a1(n), a2(n), a3(n);
    for (int i = 0; i < n; i++) {
        a1[i] = s[i] == '?' ? 0 : 1;
        a2[i] = a1[i] * (s[i] == '?' ? 0 : (long long)s[i]);
        a3[i] = a2[i] * (s[i] == '?' ? 0 : (long long)s[i]);
    }
    std::vector<long long> b1(m), b2(m), b3(m);
    for (int i = 0; i < m; i++) {
        b1[i] = t[i] == '?' ? 0 : 1;
        b2[i] = b1[i] * (t[i] == '?' ? 0 : (long long)t[i]);
        b3[i] = b2[i] * (t[i] == '?' ? 0 : (long long)t[i]);
    }
    auto f = [](const std::vector<long long> &a, std::vector<long long> &b) {
        std::reverse(b.begin(), b.end());
        std::vector<long long> c = convolution_ll(a, b);
        return std::vector<long long>(c.begin() + b.size() - 1, c.end());
    };
    std::vector<long long> c1 = f(a3, b1);
    std::vector<long long> c2 = f(a2, b2);
    std::vector<long long> c3 = f(a1, b3);
    std::vector<bool> ret(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        ret[i] = c1[i] - c2[i] * 2 + c3[i] == 0;
    }
    return ret;
}

std::vector<bool> wildcard_matching_lower(std::string s, std::string t) {
    int n = s.size(), m = t.size();
    assert(m > 0);
    assert(n >= m);
    std::vector<long long> a1(n), a2(n), a3(n);
    for (int i = 0; i < n; i++) {
        a1[i] = s[i] == '?' ? 0 : 1;
        a2[i] = a1[i] * (s[i] == '?' ? 0 : (long long)(s[i] - 'a' + 1));
        a3[i] = a2[i] * (s[i] == '?' ? 0 : (long long)(s[i] - 'a' + 1));
    }
    std::vector<long long> b1(m), b2(m), b3(m);
    for (int i = 0; i < m; i++) {
        b1[i] = t[i] == '?' ? 0 : 1;
        b2[i] = b1[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'a' + 1));
        b3[i] = b2[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'a' + 1));
    }
    auto f = [](const std::vector<long long> &a, std::vector<long long> &b) {
        std::reverse(b.begin(), b.end());
        std::vector c = convolution(a, b);
        return std::vector<long long>(c.begin() + b.size() - 1, c.end());
    };
    std::vector<long long> c1 = f(a3, b1);
    std::vector<long long> c2 = f(a2, b2);
    std::vector<long long> c3 = f(a1, b3);
    std::vector<bool> ret(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        ret[i] = c1[i] - c2[i] * 2 + c3[i] == 0;
    }
    return ret;
}

std::vector<bool> wildcard_matching_upper(std::string s, std::string t) {
    int n = s.size(), m = t.size();
    assert(m > 0);
    assert(n >= m);
    std::vector<long long> a1(n), a2(n), a3(n);
    for (int i = 0; i < n; i++) {
        a1[i] = s[i] == '?' ? 0 : 1;
        a2[i] = a1[i] * (s[i] == '?' ? 0 : (long long)(s[i] - 'A' + 1));
        a3[i] = a2[i] * (s[i] == '?' ? 0 : (long long)(s[i] - 'A' + 1));
    }
    std::vector<long long> b1(m), b2(m), b3(m);
    for (int i = 0; i < m; i++) {
        b1[i] = t[i] == '?' ? 0 : 1;
        b2[i] = b1[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'A' + 1));
        b3[i] = b2[i] * (t[i] == '?' ? 0 : (long long)(t[i] - 'A' + 1));
    }
    auto f = [](const std::vector<long long> &a, std::vector<long long> &b) {
        std::reverse(b.begin(), b.end());
        std::vector c = convolution(a, b);
        return std::vector<long long>(c.begin() + b.size() - 1, c.end());
    };
    std::vector<long long> c1 = f(a3, b1);
    std::vector<long long> c2 = f(a2, b2);
    std::vector<long long> c3 = f(a1, b3);
    std::vector<bool> ret(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        ret[i] = c1[i] - c2[i] * 2 + c3[i] == 0;
    }
    return ret;
}