#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_set<int> A{
        0, 2, 3, 4, 5, 6, 8, 12, 30, 32, 33, 34, 35, 36, 38, 40, 42, 43,
        44, 45, 46, 48, 50, 52, 53, 54, 55, 56, 58, 60, 62, 63, 64, 65,
        66, 68, 80, 82, 83, 84, 85, 86, 88
};

int main() {

    int a;
    cin >> a;
    if (A.find(a) == A.end()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}