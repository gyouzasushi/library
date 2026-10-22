#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_E"
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
    circle<double> a, b;
    cin >> a >> b;
    vector<P> ps = cross_points(a, b);
    cout << ps[0] << ' ' << ps[1] << '\n';
}
