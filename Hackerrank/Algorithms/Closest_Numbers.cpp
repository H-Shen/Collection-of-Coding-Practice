#include <bits/stdc++.h>

using namespace std;

const int MAX = numeric_limits<int>::max();

int main() {
    int n, i;
    scanf("%d", &n);
    vector<int> a(static_cast<size_t>(n));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());

    int minVal = MAX;
    for (i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] < minVal) {
            minVal = a[i + 1] - a[i];
        }
    }

    bool firstCase = true;
    for (i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] == minVal) {
            if (firstCase) {
                printf("%d %d", a[i], a[i + 1]);
                firstCase = false;
            }
            else {
                printf(" %d %d", a[i], a[i + 1]);
            }
        }
    }

    putchar('\n');
    return 0;
}
