#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_D"
#define ERROR 0.000001

#include "../../geometry/geometry.hpp"
using namespace geometry;
int main() {
    cout << fixed << setprecision(20);
    Circle c;
    cin >> c.c >> c.r;
    int q;
    cin >> q;
    while (q--) {
        Line l;
        cin >> l;
        auto ans = cross_points(c, l);
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
}