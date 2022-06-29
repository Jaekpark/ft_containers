#include <iostream>
#include <type_traits>

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

template <long X, long Y>
struct Euclidean {
  static const long gcd = Euclidean<Y, X % Y>::gcd;
  static const long lcm = (X * Y) / gcd;
};

template <long X>
struct Euclidean<X, 0> {
  static const long gcd = X;
};

int main() {
  typedef Euclidean<2345234, 2344> euc_t;
  cout << euc_t::lcm << endl;

  long mul = 2345234L * 2344L;
  cout << mul / 2 << endl;
}
