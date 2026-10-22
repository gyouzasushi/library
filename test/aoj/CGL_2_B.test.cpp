#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/line.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    int q;
    cin >> q;
    while (q--) {
        segment<double> s, t;
        cin >> s >> t;
        cout << intersect(s, t) << '\n';
    }
}
