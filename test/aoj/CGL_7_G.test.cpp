#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G"
#define ERROR 0.00001

#include "../../geometry/geometry.hpp"
using namespace geometry;
int main() {
    cout << fixed << setprecision(20);
    Circle c1, c2;
    cin >> c1.c >> c1.r >> c2.c >> c2.r;
    auto ans = common_tangents(c1, c2);
    for (Point p : ans) cout << p << '\n';
}