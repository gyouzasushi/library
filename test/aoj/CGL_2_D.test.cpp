#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 0.00000001
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/line.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    cout << fixed << setprecision(20);
    int q;
    cin >> q;
    while (q--) {
        segment<double> s, t;
        cin >> s >> t;
        cout << dist(s, t) << '\n';
    }
}
