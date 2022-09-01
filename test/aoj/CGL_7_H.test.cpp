#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_H"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    Polygon poly(n);
    Circle c;
    c.c = {0, 0};
    cin >> c.r;
    for (Point &p : poly) cin >> p;
    cout << area_of_intersection(c, poly) << '\n';
}