/**
 * Implementations of the algorithm of linear search in Cpp.
 * Compile: g++-7 -std=c++14 -Wall -O2 linearSearch.cpp -o linearSearch
 * Execute: ./linearSearch
 *
 * @author Haohu Shen
 * @date 2019/07/13
 */


#include <bits/stdc++.h>

using namespace std;

#define DEBUG

// Precondition
// 1) A is an array with length n ≥ 1 storing values of some type T that is given as input
// 2) key is an input value with type T.

// Postcondition
// 1) If the key is stored in A then the value returned is an integer i such that A[i]=key. -1 will be returned,
//    otherwise.
// 2) A and key are not changed.

template<typename T>
int linearSearch(const vector<T> &A, T key) {
    int i{0};
    int n{static_cast<int>(A.size())};
    while ((i < n) && (A[i] != key)) {
        ++i;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

template <typename T, typename Comparator>
int linearSearch(const vector<T> &A, T key, Comparator &comp) {
    int i{0};
    int n{static_cast<int>(A.size())};
    while ((i < n) && !comp(A[i], key)) {
        ++i;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

vector<int> generateArrayWithoutDuplicate(int n, int lowerbound, int upperbound) {

    // It is impossible that n is lower than 0 and n == 0 is also not allowed.
    if (n <= 0) {
        throw out_of_range("");
    }

    // It is impossible that lowerbound is greater than upperbound.
    if (lowerbound > upperbound) {
        throw out_of_range("");
    }

    // If the number between the lowerbound and the upperbound(all inclusive) are smaller than n,
    // then it is impossible to generate n unique numbers.
    if (upperbound - lowerbound + 1 < n) {
        throw out_of_range("");
    }


    random_device dev;
    mt19937 random_generator(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(static_cast<unsigned int>(lowerbound),
                                                             static_cast<unsigned int>(upperbound));
    unordered_set<int> Save;

    vector<int> result(static_cast<unsigned long>(n));
    int temp;
    for (auto &&i : result) {
        while (true) {
            temp = static_cast<int>(dist(random_generator));
            if (Save.find(temp) == Save.end()) {
                i = temp;
                Save.insert(temp);
                break;
            }
        }
    }
    return result;
}

vector<int> generateArrayWithDuplicate(int n, int lowerbound, int upperbound) {

    vector<int> result = generateArrayWithoutDuplicate(n, lowerbound, upperbound);
    random_device dev;
    uniform_int_distribution<std::mt19937::result_type> dist(0, static_cast<unsigned int>(n - 1));
    uniform_int_distribution<std::mt19937::result_type> leftOrRight(0, 1);
    mt19937 random_generator(dev());

    if (n == 2) {

        if (leftOrRight(random_generator)) {
            result.at(0) = result.at(1);
        } else {
            result.at(1) = result.at(0);
        }

    } else if (n >= 3) {

        int counter = n / 3;
        while (counter--) {
            int index = static_cast<int>(dist(random_generator));
            if (index == 0) {
                result.at(static_cast<unsigned long>(index) + 1) = result.at(static_cast<unsigned long>(index));
            } else if (index == n - 1) {
                result.at(static_cast<unsigned long>(index - 1)) = result.at(static_cast<unsigned long>(index));
            } else {
                if (leftOrRight(random_generator)) {
                    result.at(static_cast<unsigned long>(index - 1)) = result.at(static_cast<unsigned long>(index));
                } else {
                    result.at(static_cast<unsigned long>(index) + 1) = result.at(static_cast<unsigned long>(index));
                }
            }
        }

    }
    return result;
}

int main() {

#ifdef DEBUG
    random_device dev;
    mt19937 random_generator(dev());
    int n = 1000;
    uniform_int_distribution<std::mt19937::result_type> index(0, static_cast<unsigned int>(n - 1));
    int testTime = 300;

    // TESTS
    for (int i = 0; i < testTime; ++i) {
        vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        int val = A[index(random_generator)];
        assert(find(A.begin(), A.end(), val) - A.begin() == linearSearch(A, val));
    }
    cout << "Tests passed!" << endl;

    for (int i = 0; i < testTime; ++i) {
        vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        int val = A[index(random_generator)];
        assert(find(A.begin(), A.end(), val) - A.begin() == linearSearch(A, val));
    }
    cout << "Tests passed!" << endl;

    for (int i = 0; i < testTime; ++i) {
        vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        int val = *max_element(A.begin(), A.end()) + 1;
        assert(linearSearch(A, val) == -1);
    }
    cout << "Tests passed!" << endl;

    for (int i = 0; i < testTime; ++i) {
        vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        int val = *max_element(A.begin(), A.end()) + 1;
        assert(linearSearch(A, val) == -1);
    }
    cout << "Tests passed!" << endl;

    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> int {
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
        return 0;
    };
    for (int i = 0; i < testTime; ++i) {
        vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        vector<pair<int, int> > A_(A.size());
        for (size_t j = 0; j != A.size(); ++j) {
            A_.at(j) = {A.at(j), A.at(j)};
        }
        auto val = *max_element(A_.begin(), A_.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs)->bool
        {
           if (lhs.first == rhs.first) {
               return (lhs.second < rhs.second);
           }
        });
        assert(linearSearch(A_, val, cmp) != -1);
    }
    cout << "Tests passed!" << endl;

#endif
    // USAGE
    vector<int> A = {2, 3, 3, 4, 7, 7, 7, 9};
    int val = 2;
    cout << linearSearch(A, val) << endl;

    val = 7;
    cout << linearSearch(A, val) << endl;

    val = 123;
    cout << linearSearch(A, val) << endl;

    return 0;
}
