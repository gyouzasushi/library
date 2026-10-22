#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G"
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
    circle<double> a, b;
    cin >> a >> b;
    for (const P& p : common_tangents(a, b)) cout << p << '\n';
}
