#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Write Your Code Here
    if (a > 9)
        printf("Greater than 9\n");
    switch (a) {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 5:
            printf("five\n");
            break;
        case 6:
            printf("six\n");
            break;
        case 7:
            printf("seven\n");
            break;
        case 8:
            printf("eight\n");
            break;
        case 9:
            printf("nine\n");
            break;
    }

    return 0;
}
