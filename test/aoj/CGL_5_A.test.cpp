#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_5_A"
#define ERROR 0.000001
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/polygon.hpp"
using namespace std;
using namespace geo;
using P = point<double>;
int main() {
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<P> ps(n);
    for (P& p : ps) cin >> p;
    auto [i, j] = closest_pair(ps);
    cout << abs(ps[i] - ps[j]) << '\n';
}
