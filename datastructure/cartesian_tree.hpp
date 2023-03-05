#pragma once
#include <numeric>
#include <optional>
#include <stack>
#include <vector>
template <typename T>
std::vector<int> cartesian_tree(std::vector<T> &a) {
    int n = int(a.size());
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        std::optional<int> pre = std::nullopt;
        while (!st.empty() && a[i] < a[st.top()]) {
            pre = st.top();
            st.pop();
        }
        if (pre) p[pre.value()] = i;
        if (!st.empty()) p[i] = st.top();
        st.push(i);
    }
    return p;
}