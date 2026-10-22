#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_C"
#define ERROR 0.000001
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/circle.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    cout << fixed << setprecision(20);
    P a, b, c;
    cin >> a >> b >> c;
    circle<double> o = circumcircle(a, b, c);
    cout << o.c << ' ' << o.r << '\n';
}
