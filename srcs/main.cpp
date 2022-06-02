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
  int a = 0;

  std::true_type;

  decltype(a);
  return 0;
}
