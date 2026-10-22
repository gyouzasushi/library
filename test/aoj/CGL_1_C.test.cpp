#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/line.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    P a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    while (q--) {
        P c;
        cin >> c;
        int s = ccw(a, b, c);
        if (s > 0) cout << "COUNTER_CLOCKWISE" << '\n';
        if (s < 0) cout << "CLOCKWISE" << '\n';
        if (s == 0) {
            if (sgn(dot(b - a, c - a)) < 0) cout << "ONLINE_BACK" << '\n';
            else if (sgn(dot(a - b, c - b)) < 0) cout << "ONLINE_FRONT" << '\n';
            else cout << "ON_SEGMENT" << '\n';
        }
    }
}
