#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 6) {
    cout << 1 << endl;
  }
  else if (n == 7) {
    cout << 2 << endl;
  }
  else {
    cout << n + 2 << endl;
  }
  return 0;
}