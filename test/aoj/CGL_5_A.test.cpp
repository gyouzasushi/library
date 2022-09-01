#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_5_A"
#define ERROR 0.000001

#include "../../geometry/geometry.hpp"
using namespace geometry;
int main() {
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<Point> ps(n);
    for (auto &p : ps) cin >> p;
    cout << closest_pair(ps).first << '\n';
}