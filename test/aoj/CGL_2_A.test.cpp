#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    int q;
    cin >> q;
    while (q--) {
        Line l1, l2;
        cin >> l1 >> l2;
        if (!intersect(l1, l2)) {
            cout << 2 << '\n';
        } else if (sgn(dot(l1.a - l1.b, l2.a - l2.b)) == 0) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}