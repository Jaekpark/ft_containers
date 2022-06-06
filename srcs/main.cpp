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
  ft::vector<int> a(4, 1);

  std::cout << a.size() << std::endl;
  a.erase(a.begin(), a.end());
  // a.erase(a.begin());
  std::cout << a.size() << std::endl;
  // std::cout << a.bits_per_word << std::endl;
  // a.destruct_at_end(a.begin());
  // std::vector<int> b;
  return 0;
}
