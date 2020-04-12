#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<ll, int, custom_hash> freq;

int main() {

    int n;
    IO::read(n);
    ll a, b, temp;
    while (n--) {
        IO::read(a, b);
        ++freq[a];
        temp = a ^ b;
        if (temp != a) {
            ++freq[temp];
        }
    }
    int max_freq = -1;
    for (const auto &[k, v] : freq) {
        max_freq = max(max_freq, v);
    }
    ll min_val_with_max_freq = numeric_limits<ll>::max();
    for (const auto &[k, v] : freq) {
        if (v == max_freq) {
            min_val_with_max_freq = min(min_val_with_max_freq, k);
        }
    }
    IO::writeln(min_val_with_max_freq);

    return 0;
}