#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A"
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/circle.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    circle<double> a, b;
    cin >> a >> b;
    cout << count_common_tangents(a, b) << '\n';
}
