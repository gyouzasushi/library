#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include <iostream>

#include "datastructure/binary_trie.hpp"

int main() {
    int q;
    std::cin >> q;
    binary_trie<30> t;
    while (q--) {
        int c, x;
        std::cin >> c >> x;
        if (c == 0) {
            if (t.count(x) == 0) t.insert(x);
        } else if (c == 1) {
            if (t.count(x) == 1) t.erase(x);
        } else {
            std::cout << t.min(x) << '\n';
        }
    }
}
