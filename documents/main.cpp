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

template <class T, T v>
struct meta {
  // typedef T value_type;
  // typedef meta type;
  static const T value = v;
  // operator value_type() const { return value; }
  // const value_type operator()() const { return value; }
};

template <class T>
struct something {
  T value;
  something(T v = 0) : value(v) {}
};

int main() {
  something<int> a(10);
  cout << a.value << endl;
}
