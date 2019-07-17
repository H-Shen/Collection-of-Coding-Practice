#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/

template <class T>
class AddElements {
T element;
public:
AddElements (T arg) {element=arg;}
};

template <>
class AddElements <int> {
    int element;
public:
    AddElements (int arg) {element=arg;}
    int add (int x)
    {
    element += x;
    return element;
    }
};

template <>
class AddElements <double> {
    double element;
public:
    AddElements (double arg) {element=arg;}
    double add (double x)
    {
    element += x;
    return element;
    }
};

template <>
class AddElements <string> {
    string element;
public:
    AddElements (string arg) {element=arg;}
    string concatenate (string x)
    {
    element = element + x;
    return element;
    }
};
int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
