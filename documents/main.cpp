#include <iostream>
#include <iterator>
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

template <class T>
class my_array {
 private:
  size_t sz;
  T* arr;

 public:
  my_array(const size_t size = 0) : sz(size) {
    arr = new T[sz];
    for (size_t i = 0; i < size; i++) *arr++ = T();
  }
  my_array(const T& value, size_t size = 0) : sz(size) {
    arr = new T[size];
    for (int i = 0; i < size; i++) arr[i] = value;
  }
  template <class Iter>
  my_array(
      Iter first, Iter last,
      typename enable_if<!is_integral<Iter>::value, Iter>::type* = nullptr) {
    ptrdiff_t dist = last - first;
    arr = new T[dist];
    sz = dist;
    for (size_t i = 0; i < dist; i++) arr[i] = *first++;
  }
  my_array(my_array& other) {
    sz = other.size();
    arr = new T[sz];
    size_t count = other.size();
    for (size_t i = 0; i < other.size(); i++) arr[i] = other[i];
  }
  my_array operator=(my_array& other) {
    if (this->sz) delete[] arr;
    sz = 0;
    if (!other.empty()) {
      sz = other.size();
      arr = new T[sz];
      this->assign(&other[0], &other[other.size()]);
    }
    return *this;
  }

  ~my_array() {
    if (arr) delete[] arr;
  }
  template <class Iter>
  void assign(Iter first, Iter last) {
    // while (first++ != last) *arr++ = *first
    while (first != last) *(arr++) = *first++;
  }
  T& operator[](size_t pos) { return arr[pos]; }
  size_t size() const { return sz; }
  bool empty() const { return this->size() == 0; }
};

// void print(char* t) { cout << "char : " << t << endl; }
void print(std::string t) { cout << "str : " << t << endl; }
// void print(const char* t) { cout << "const char : " << t << endl; }
// void print(std::string t) { cout << "string : " << t << endl; }
template <class T>
void print(T t) {
  cout << "template : " << t << endl;
}

template <class T>
typename T::value_type print(typename T::value_type t) {
  return t;
}

template <class T>
typename T::value_type sum(T& x, T& y) {
  cout << "T::value_type sum : " << x + y << endl;
  return x + y;
}

// template <class T>
// T sum(T& x, T& y,
//       typename enable_if<!is_integral<T>::value, T>::type* = nullptr) {
//   cout << "T.value" << endl;
//   return x.value + y.value;
// }

// template <class T>
// T sum(T& x, T& y) {
//   cout << "T sum : " << x + y << endl;
//   return x + y;
// }

template <class T>
struct my_data {
  typedef T value_type;
  value_type value;

  my_data(const T& val = 0) : value(val){};
};

template <long X>
struct Euclidean<X, 0> {
  static const long gcd = X;
};

int main() {
  int a = 10;
  int b = 20;
  cout << sum(a, b) << endl;
  my_data<int> c(10);
  my_data<int> d(20);
  cout << sum(c, d) << endl;
}
