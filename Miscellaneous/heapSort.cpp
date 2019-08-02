#include <bits/stdc++.h>

/**
 * The heapSort using minHeap for solving the 'Sorting in Place' problem.
 *
 * <p>
 * Sorting an array in non-decreasing order when array A with length >= 1,
 * storing elements from some ordered type T using heapsort.
 * </p>
 *
 * Compile: g++-7 -std=c++14 -Wall -O2 heapSort.cpp -o heapSort
 * Execute: ./heapSort
 *
 * @author Haohu Shen
 * @date 2019/07/03
 */

#define DEBUG

using namespace std;

namespace HeapSort {

    auto isRoot = [](const int &x) -> bool { return (x == 0); };
    auto parent = [](const int &x) -> int {
        if (x == 0) {
            throw out_of_range("");
        }
        return (x - 1) / 2;
    };
    auto hasLeft = [](const int &x, const int &heapSize) -> bool { return (2 * x + 1 < heapSize); };
    auto left = [](const int &x, const int &heapSize) -> int {
        if (hasLeft(x, heapSize)) {
            return 2 * x + 1;
        }
        throw out_of_range("");
    };
    auto hasRight = [](const int &x, const int &heapSize) { return (2 * x + 2 < heapSize); };
    auto right = [](const int &x, const int &heapSize) -> int {
        if (hasRight(x, heapSize)) {
            return 2 * x + 2;
        }
        throw out_of_range("");
    };

    template<typename T, typename Comparator>
    void bubbleUp(int x, vector<T> &A, const Comparator &comp) {
        while (!isRoot(x) && comp(A.at(x), A.at(parent(x))) > 0) {
            swap(A.at(x), A.at(parent(x)));
            x = parent(x);
        }
    }

    template<typename T>
    void bubbleUp(int x, vector<T> &A) {
        while (!isRoot(x) && A.at(x) > A.at(parent(x))) {
            swap(A.at(x), A.at(parent(x)));
            x = parent(x);
        }
    }

    template<typename T, typename Comparator>
    void bubbleDown(int x, int heapSize, vector<T> &A, const Comparator &comp) {
        while (hasLeft(x, heapSize)) {
            if (hasRight(x, heapSize)) {
                if (comp(A.at(left(x, heapSize)), A.at(right(x, heapSize))) >= 0) {
                    if (comp(A.at(left(x, heapSize)), A.at(x)) > 0) {
                        swap(A.at(left(x, heapSize)), A.at(x));
                        x = left(x, heapSize);
                    } else {
                        break;
                    }
                } else if (comp(A.at(right(x, heapSize)), A.at(x)) > 0) {
                    swap(A.at(right(x, heapSize)), A.at(x));
                    x = right(x, heapSize);
                } else {
                    break;
                }
            } else if (comp(A.at(left(x, heapSize)), A.at(x)) > 0) {
                swap(A.at(left(x, heapSize)), A.at(x));
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    }

    template<typename T>
    void bubbleDown(int x, int heapSize, vector<T> &A) {
        while (hasLeft(x, heapSize)) {
            if (hasRight(x, heapSize)) {
                if (A.at(left(x, heapSize)) >= A.at(right(x, heapSize))) {
                    if (A.at(left(x, heapSize)) > A.at(x)) {
                        swap(A.at(left(x, heapSize)), A.at(x));
                        x = left(x, heapSize);
                    } else {
                        break;
                    }
                } else if (A.at(right(x, heapSize)) > A.at(x)) {
                    swap(A.at(right(x, heapSize)), A.at(x));
                    x = right(x, heapSize);
                } else {
                    break;
                }
            } else if (A.at(left(x, heapSize)) > A.at(x)) {
                swap(A.at(left(x, heapSize)), A.at(x));
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    }

    template<typename T, typename Comparator>
    void heapSort(vector<T> &A, const Comparator &comp) {
        try {

            int heapSize = 1;
            int i = 1;
            int len = static_cast<int>(A.size());

            while (i < len) {
                if (heapSize < len) {
                    int x = heapSize;
                    A.at(x) = A.at(i);
                    ++heapSize;
                    bubbleUp(x, A, comp);
                } else {
                    throw out_of_range("");
                }
                ++i;
            }
            i = len - 1;
            while (i > 0) {
                T largest;
                if (heapSize == 0) {
                    throw out_of_range("");
                } else {
                    auto temp = A.at(heapSize - 1);
                    --heapSize;
                    if (heapSize == 0) {
                        largest = temp;
                    } else {
                        largest = A.at(0);
                        A.at(0) = temp;
                        bubbleDown(0, heapSize, A, comp);
                    }
                }
                A.at(i) = largest;
                --i;
            }
        } catch (...) {}
    }

    template<typename T>
    void heapSort(vector<T> &A) {
        try {
            int heapSize = 1;
            int i = 1;
            int len = static_cast<int>(A.size());

            while (i < len) {
                if (heapSize < len) {
                    int x = heapSize;
                    A.at(x) = A.at(i);
                    ++heapSize;
                    bubbleUp(x, A);
                } else {
                    throw out_of_range("");
                }
                ++i;
            }
            i = len - 1;
            while (i > 0) {
                T largest;
                if (heapSize == 0) {
                    throw out_of_range("");
                } else {
                    T temp = A.at(heapSize - 1);
                    --heapSize;
                    if (heapSize == 0) {
                        largest = temp;
                    } else {
                        largest = A.at(0);
                        A.at(0) = temp;
                        bubbleDown(0, heapSize, A);
                    }
                }
                A.at(i) = largest;
                --i;
            }
        } catch (...) {}
    }
}


int main() {

#ifdef DEBUG
    ios_base::sync_with_stdio(false);

    // Initialize a random number generator.
    random_device dev;
    mt19937 random_generator(dev());

    // Make every entry of the array, the time of tests and the length of the array to be random.
    uniform_int_distribution<std::mt19937::result_type> dist(static_cast<unsigned int>(INT_MIN), INT_MAX);
    uniform_int_distribution<std::mt19937::result_type> test_time_dist(50, 1000);
    uniform_int_distribution<std::mt19937::result_type> len_dist(500, 1000);

    int test_time = test_time_dist(random_generator);
    while (test_time--) {

        vector<int> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = static_cast<int>(dist(random_generator));
        }
        vector<int> A_copy(A.begin(), A.end());

        HeapSort::heapSort(A);
        sort(A_copy.begin(), A_copy.end());
        assert(A == A_copy);
    }
    cout << "Tests passed!" << endl;

    class Widget {
    private:
        int first;
        int second;
    public:
        Widget() : first(0), second(0) {};

        Widget(int first_, int second_) : first(first_), second(second_) {}

        bool operator!=(const Widget &rhs) const {
            return (first != rhs.first);
        }

        bool operator<(const Widget &rhs) const {
            return (first < rhs.first);
        }

        bool operator==(const Widget &rhs) const {
            return (first == rhs.first);
        }

        bool operator>(const Widget &rhs) const {
            return (first > rhs.first);
        }

        bool operator>=(const Widget &rhs) const {
            return (first >= rhs.first);
        }

        Widget &operator=(Widget other) {
            first = other.first;
            second = other.second;
            return *this;
        }

        explicit operator string() const {
            return "(" + to_string(first) + ", " + to_string(second) + ")";
        }
    };
    test_time = test_time_dist(random_generator);
    while (test_time--) {
        vector<Widget> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = Widget(static_cast<int>(dist(random_generator)), static_cast<int>(dist(random_generator)));
        }
        vector<Widget> A_copy(A.begin(), A.end());
        HeapSort::heapSort(A);
        sort(A_copy.begin(), A_copy.end());
        assert(A == A_copy);
    }
    cout << "Tests passed!" << endl;

    test_time = test_time_dist(random_generator);
    while (test_time--) {
        vector<pair<int, int> > A(len_dist(random_generator));
        for (auto &&i : A) {
            i = {static_cast<int>(dist(random_generator)), static_cast<int>(dist(random_generator))};
        }
        vector<pair<int, int> > A_copy(A.begin(), A.end());

        sort(A_copy.begin(), A_copy.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
            if (lhs.first == rhs.first) {
                return (lhs.second < rhs.second);
            }
            return (lhs.first < rhs.first);
        });
        HeapSort::heapSort(A, [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> int {
            if (lhs.first == rhs.first) {
                if (lhs.second > rhs.second) {
                    return 1;
                } else if (lhs.second < rhs.second) {
                    return -1;
                }
                return 0;
            } else if (lhs.first > rhs.first) {
                return 1;
            }
            return -1;
        });
        assert(A_copy == A);
    }
    cout << "Tests passed!" << endl;

#endif

    return 0;
}
