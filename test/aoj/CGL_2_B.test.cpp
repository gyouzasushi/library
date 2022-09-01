#include <bits/stdc++.h>
using namespace std;

#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"
#include "../../geometry/geometry.hpp"

using namespace geometry;
int main() {
    int q;
    cin >> q;
    while (q--) {
        Segment s1, s2;
        cin >> s1 >> s2;
        cout << intersect(s1, s2) << '\n';
    }
}