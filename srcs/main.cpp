#include <time.h>

#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

#include "config.hpp"
#include "container/vector.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

int main(void) {
  clock_t start, end;
  start = clock();
  ft::vector<int> a;
  ft::vector<int> a_1(5, 77);
  bool is_valid = ft::is_convertible<ft::vector<int>::iterator,
                                     ft::vector<int>::iterator>::value;
  std::cout << is_valid << std::endl;
  ft::vector<int>::iterator iter = a.begin();
  std::cout << ft::is_iterator<ft::vector<int>::iterator>::value << std::endl;
  a.assign(a_1.begin(), a_1.end());
  std::cout << "size : " << a.size() << std::endl;
  std::cout << "capacity : " << a.capacity() << std::endl;
  for (ft::vector<int>::iterator it = a.begin(); it != a.end(); it++) {
    std::cout << *it << std::endl;
  }
  end = clock();
  std::cout << end - start << std::endl;
  std::cout << "---------------" << std::endl;

  start = clock();

  std::vector<int> b(10, 1);
  std::cout << "size : " << b.size() << std::endl;
  std::cout << "capacity : " << b.capacity() << std::endl;
  // std::vector<int>::iterator i = b.insert(b.begin(), 10);
  for (std::vector<int>::iterator it1 = b.begin(); it1 != b.end(); it1++) {
    std::cout << *it1 << std::endl;
  }
  // std::cout << *i << std::endl;
  std::cout << "size : " << b.size() << std::endl;
  std::cout << "capacity : " << b.capacity() << std::endl;
  end = clock();
  std::cout << end - start << std::endl;
  // a.erase(a.begin(), a.end());
  // a.erase(a.begin());
  // std::cout << a.size() << std::endl;
  // std::cout << a.capacity() << std::endl;
  // std::cout << *a.begin() << std::endl;
  // std::cout << a.bits_per_word << std::endl;
  // a.destruct_at_end(a.begin());
  // std::vector<int> b;
  return 0;
}