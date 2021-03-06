#include <bits/stdc++.h>

using namespace std;

const int MOD = 1234567;

vector<string> split_string(string);

/*
 * Complete the connectingTowns function below.
 */
int connectingTowns(const vector<int>& routes) {
    /*
     * Write your code here.
     */
    int result = 1;
    for (const int &i : routes) {
        result = (result * i) % MOD;
    }
    return result % MOD;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string routes_temp_temp;
        getline(cin, routes_temp_temp);

        vector<string> routes_temp = split_string(routes_temp_temp);

        vector<int> routes(static_cast<unsigned long>(n - 1));

        for (int routes_itr = 0; routes_itr < n - 1; routes_itr++) {
            int routes_item = stoi(routes_temp[routes_itr]);

            routes[routes_itr] = routes_item;
        }

        int result = connectingTowns(routes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
