#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

const double pi = acos(-1);

int main() {
    int r;
    cin >> r;
    double s1 = pi * r * r;
    double s2 = r * r * 2;
    printf("%.4lf\n%.4lf\n", s1, s2);
    return 0;
}