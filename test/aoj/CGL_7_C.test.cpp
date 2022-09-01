#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    cout << fixed << setprecision(20);

    Polygon poly(3);
    for (Point &p : poly) cin >> p;
    Circle c = circumscribed_circle_of_triangle(poly);
    cout << c.c << ' ' << c.r << '\n';
}