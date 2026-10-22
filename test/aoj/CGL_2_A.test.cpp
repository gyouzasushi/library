#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/line.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    int q;
    cin >> q;
    while (q--) {
        line<double> l, m;
        cin >> l >> m;
        if (parallel(l, m)) cout << 2 << '\n';
        else if (orthogonal(l, m)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
