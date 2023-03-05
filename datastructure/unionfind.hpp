#pragma once
#include <algorithm>
#include <vector>
struct unionfind {
    int n;
    std::vector<int> data;
    unionfind(int _n) : n(_n), data(_n, -1) {
    }
    int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return -data[root(x)];
    }
    std::vector<std::vector<int>> groups() {
        std::vector<int> root_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            root_buf[i] = root(i);
            group_size[root_buf[i]]++;
        }
        std::vector<std::vector<int>> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            ret[root_buf[i]].push_back(i);
        }
        ret.erase(std::remove_if(
                      ret.begin(), ret.end(),
                      [&](const std::vector<int>& v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};