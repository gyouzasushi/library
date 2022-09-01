#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR 0.00000001

#include "../../geometry/geometry.hpp"
using namespace geometry;
int main() {
    cout << fixed << setprecision(20);
    Line l;
    cin >> l;
    int q;
    cin >> q;
    while (q--) {
        Point p;
        cin >> p;
        cout << l.reflection(p) << '\n';
    }
}