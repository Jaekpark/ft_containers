#include <iostream>

using namespace std;

template <typename T>
T add(T t1, T t2) {
  return t1 + t2;
}

template <class T>
class Calculator {
 public:
  T add(T t1, T t2) { return t1 + t2; }
  T sub(T t1, T t2) { return t1 - t2; }
  T mul(T t1, T t2) { return t1 * t2; }
  T div(T t1, T t2) { return t1 / t2; }
};

int main() {
  // int a = 10;
  // int b = 5;
  double a = 12.423;
  double b = 42.23;

  char c1 = 'a';
  char c2 = 'b';

  string s1 = "abc";
  string s2 = "def";

  cout << add<int>(a, b) << endl;
  cout << add<char>(c1, c2) << endl;
  cout << add<string>(s1, s2) << endl;

  // Calculator<int> calc;
  Calculator<double> calc;

  cout << calc.add(a, b) << endl;
  cout << calc.sub(a, b) << endl;
  cout << calc.mul(a, b) << endl;
  cout << calc.div(a, b) << endl;
}