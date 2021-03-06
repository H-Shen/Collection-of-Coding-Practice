// https://open.kattis.com/problems/cats
//
#pragma GCC optimize("Ofast")
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;


namespace FastIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char inputBuffer[MAXSIZE];
    static char *ptr1 = inputBuffer + MAXSIZE;
    static char *ptr2 = inputBuffer + MAXSIZE;
    static char outputBuffer[MAXSIZE];
    static char *ptr = outputBuffer;

    inline static
    char getcharUsingFread() {
        if (ptr1 == ptr2) {
            ptr1 = inputBuffer;
            ptr2 = inputBuffer + fread(inputBuffer, 1, MAXSIZE, stdin);
            if (ptr1 == ptr2) {
                return EOF;
            }
        }
        return *ptr1++;
    }

    inline static
    void putcharWithFwrite(const char &ch) {
        if (ptr - outputBuffer == MAXSIZE) {
            fwrite(outputBuffer, 1, MAXSIZE, stdout);
            ptr = outputBuffer;
        }
        *ptr++ = ch;
    }

    template<class T>
    inline static
    void writeIntWithFwrite(T x) {
        if (x < 0) {
            x = -x;
            putcharWithFwrite('-');
        }
        static int storeDigits[40];
        int top = 0;
        do {
            storeDigits[top++] = x % 10;
            x /= 10;
        } while (x);
        while (top) {
            putcharWithFwrite(static_cast<T>(storeDigits[--top]) + 48);
        }
    }

    void flushAfterWriteIntWithFwrite() {
        fwrite(outputBuffer, 1, ptr - outputBuffer, stdout);
    }

    template<typename T>
    inline static
    void readIntUsingFread(T &x) {
        x = 0;
        bool isNeg = false;
        char ch = getcharUsingFread();

        // skip all non digit characters
        while (!isdigit(ch)) {
            if (ch == '-') {
                isNeg = true;
            }
            ch = getcharUsingFread();
        }

        while (isdigit(ch)) {
            x = x * 10 + static_cast<T>(ch ^ 48);
            ch = getcharUsingFread();
        }
        x = isNeg ? -x : x;
    }
}


namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

// The collection of methods and data structures for Kruskal's algorithm
namespace Kruskal {
    struct Edge {
        int u, v;
        int w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &lhs, const Edge &rhs) {
        return (lhs.w < rhs.w);
    }
    int init(vector<Edge> E, int number_of_nodes) {
        int cost = 0;
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                cost += w;
            }
        }
        return cost;
    }
}

int main() {

    int t, m, c, n;
    FastIO::readIntUsingFread<int>(t);
    while (t--) {
        FastIO::readIntUsingFread<int>(m);
        FastIO::readIntUsingFread<int>(c);
        n = c * (c - 1) / 2;
        vector<Kruskal::Edge> E(n);
        for (auto &[u, v, w] : E) {
            FastIO::readIntUsingFread<int>(u);
            FastIO::readIntUsingFread<int>(v);
            FastIO::readIntUsingFread<int>(w);
        }
        auto distance = Kruskal::init(E, c);
        if (m >= distance + c) {
            FastIO::putcharWithFwrite('y');
            FastIO::putcharWithFwrite('e');
            FastIO::putcharWithFwrite('s');
        } else {
            FastIO::putcharWithFwrite('n');
            FastIO::putcharWithFwrite('o');
        }
        FastIO::putcharWithFwrite('\n');
    }
    FastIO::flushAfterWriteIntWithFwrite();
    return 0;
}
