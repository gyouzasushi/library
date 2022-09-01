#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#define ERROR 0.00000001

#include "../../geometry/geometry.hpp"
using namespace geometry;
int main() {
    Point a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    while (q--) {
        Point c;
        cin >> c;
        int ans = ccw(a, b, c);
        if (ans == COUNTER_CLOCKWISE) cout << "COUNTER_CLOCKWISE" << '\n';
        if (ans == CLOCKWISE) cout << "CLOCKWISE" << '\n';
        if (ans == ONLINE_BACK) cout << "ONLINE_BACK" << '\n';
        if (ans == ONLINE_FRONT) cout << "ONLINE_FRONT" << '\n';
        if (ans == ON_SEGMENT) cout << "ON_SEGMENT" << '\n';
    }
}