#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/polygon.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    cout << fixed << setprecision(1);
    int n;
    cin >> n;
    polygon<double> poly(n);
    for (P& p : poly) cin >> p;
    cout << area(poly) << '\n';
}
