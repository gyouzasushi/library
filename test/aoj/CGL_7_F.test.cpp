#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_F"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    cout << fixed << setprecision(20);
    Point p;
    Circle c;
    cin >> p >> c.c >> c.r;
    auto ans = tangent_points(c, p);
    cout << ans[0] << ' ' << ans[1] << '\n';
}