#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    cout << fixed << setprecision(1);
    int n;
    cin >> n;
    Polygon poly(n);
    for (auto &p : poly) cin >> p;
    cout << poly.area() << '\n';
}