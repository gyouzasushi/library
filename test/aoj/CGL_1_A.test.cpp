#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
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
    line<double> l;
    cin >> l;
    int q;
    cin >> q;
    while (q--) {
        P p;
        cin >> p;
        cout << projection(l, p) << '\n';
    }
}
