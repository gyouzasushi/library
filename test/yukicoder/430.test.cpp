#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <iostream>
#include <string>

#include "string/aho_corasick.hpp"
#include "string/trie.hpp"
int main() {
    std::string s;
    int m;
    std::cin >> s >> m;
    trie<26, 'A'> t;
    for (int i = 0; i < m; i++) {
        std::string c;
        std::cin >> c;
        t.insert(c);
    }
    aho_corasick ac(t);
    long long ans = 0;
    int v = 0;
    for (char ch : s) {
        v = ac.next(v, ch);
        ans += ac.count(v);
    }
    std::cout << ans << '\n';
}
