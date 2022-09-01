#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C"
#define ERROR 0.00000001

#include "../../geometry/geometry.hpp"
using namespace geometry;
int main() {
    cout << fixed << setprecision(20);
    int q;
    cin >> q;
    while (q--) {
        Segment s1, s2;
        cin >> s1 >> s2;
        cout << cross_point(s1, s2) << '\n';
    }
}