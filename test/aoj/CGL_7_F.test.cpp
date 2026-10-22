#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_F"
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
    P p;
    circle<double> o;
    cin >> p >> o;
    vector<P> ps = tangent_points(o, p);
    cout << ps[0] << '\n' << ps[1] << '\n';
}
