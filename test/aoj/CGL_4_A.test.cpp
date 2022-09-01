#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    int n;
    cin >> n;
    Polygon poly(n);
    for (auto &p : poly) cin >> p;

    Polygon ch = convex_hull(poly);
    int m = int(ch.size());
    cout << m << '\n';
    int s = 0;
    for (int i = 0; i < m; i++) {
        if (sgn(ch[i].y - ch[s].y) < 0) {
            s = i;
        } else if (sgn(ch[i].y - ch[s].y) == 0 && sgn(ch[i].x - ch[s].x) < 0) {
            s = i;
        }
    }
    for (int i = 0; i < m; i++) {
        int j = (i + s) % m;
        cout << round(ch[j].x) << ' ' << round(ch[j].y) << '\n';
    }
}