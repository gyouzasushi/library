#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C"
#define ERROR 0.00001
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/polygon.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    polygon<double> poly(n);
    for (P& p : poly) cin >> p;
    int q;
    cin >> q;
    while (q--) {
        line<double> l;
        cin >> l;
        cout << area(convex_cut(poly, l)) << '\n';
    }
}
