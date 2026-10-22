#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_H"
#define ERROR 0.00001
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/circle.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    cout << fixed << setprecision(20);
    int n;
    double r;
    cin >> n >> r;
    polygon<double> poly(n);
    for (P& p : poly) cin >> p;
    cout << area_of_intersection(circle<double>(P(0, 0), r), poly) << '\n';
}
