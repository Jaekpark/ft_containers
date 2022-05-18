#include <iostream>
#include <iterator>
#include <vector>

#include "config.hpp"
#include "container/vector.hpp"
#include "type_traits/is_integral.hpp"

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

int main(void) {
  // NAMESPACE::vector<int> origin(1, 10);
	bool a = ft::is_integral<long>::value;

  // std::cout << origin.size() << std::endl;
  // std::cout << origin[1] << std::endl;
	std::cout << a << std::endl;
  return 0;
}
