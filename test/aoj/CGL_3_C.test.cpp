#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C"
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
    polygon<double> poly(n);
    for (P& p : poly) cin >> p;
    int q;
    cin >> q;
    while (q--) {
        P p;
        cin >> p;
        cout << contains(poly, p) << '\n';
    }
}
