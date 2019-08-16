#include <vector>
#include <numeric>
#include <cassert>

// Greatest Common Divisor (with recursion)
long long gcdWithRecursion(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return gcdWithRecursion(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return gcdWithRecursion(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    return (b > 0) ? gcdWithRecursion(b, a % b) : a;
}


// Greatest Common Divisor (without recursion)
long long gcd(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return gcd(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return gcd(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    long long t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Greatest Common Divisor of integers in an array
long long gcdOfAnArray(const std::vector<long long> &A) {
    return std::accumulate(cbegin(A), cend(A), A.front(), gcd);
}

// Least Common Multiple
long long lcm(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return lcm(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return lcm(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    return a / gcd(a, b) * b;
}

// Least Common Multiple of integers in an array
long long lcmOfAnArray(const std::vector<long long> &A) {
    return std::accumulate(cbegin(A), cend(A), A.front(), lcm);
}

int main() {

    assert(gcdOfAnArray({1, 2, 3, 4}) == 1);
    assert(gcdOfAnArray({2, 2, 2, 4}) == 2);
    assert(lcmOfAnArray({2, 2, 2, 4}) == 4);
    assert(lcmOfAnArray({2, 2, 2, -2}) == 2);

    return 0;
}