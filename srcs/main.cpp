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
  ft::vector<int> a(10, 5);
  std::vector<int> b(10, 5);
  std::cout << *(a.begin()) << std::endl;
  std::cout << a.size() << std::endl;
  std::cout << a.max_size() << std::endl;
  std::cout << *(b.begin()) << std::endl;
  std::cout << b.size() << std::endl;
  std::cout << b.max_size() << std::endl;
  a.resize(5, 10);
  std::cout << *(a.begin()) << std::endl;
  std::cout << a.size() << std::endl;
  std::cout << a.max_size() << std::endl;
  // a.clear();
  std::cout << *(a.begin()) << std::endl;
  std::cout << a.size() << std::endl;
  std::cout << a.max_size() << std::endl;

  std::cout << a.__bits_per_word << std::endl;

  // a.destruct_at_end(a.begin());
  // std::vector<int> b;
  return 0;
}
