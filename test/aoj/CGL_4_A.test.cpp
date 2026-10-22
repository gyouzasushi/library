#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/polygon.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    int n;
    cin >> n;
    vector<P> ps(n);
    for (P& p : ps) cin >> p;
    polygon<double> ch = convex_hull(ps, false);
    int m = int(ch.size());
    int s = 0;
    for (int i = 0; i < m; i++) {
        if (sgn(ch[i].y - ch[s].y) < 0 || (sgn(ch[i].y - ch[s].y) == 0 && sgn(ch[i].x - ch[s].x) < 0)) s = i;
    }
    cout << m << '\n';
    for (int i = 0; i < m; i++) {
        const P& p = ch[(s + i) % m];
        cout << llround(p.x) << ' ' << llround(p.y) << '\n';
    }
}
