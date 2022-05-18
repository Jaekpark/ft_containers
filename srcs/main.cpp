#include <iostream>
#include <iterator>
#include <vector>
#include <type_traits>

#include "config.hpp"
#include "container/vector.hpp"
#include "type_traits/is_integral.hpp"
#include "type_traits/enable_if.hpp"

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

int main(void) {
	int tmp[] = {5,6,7,9};
  // NAMESPACE::vector<int> origin(5, 10);
  ft::vector<int> temp(&tmp[0], &tmp[3]);

  // std::cout << origin.size() << std::endl;
  // std::cout << origin[0] << std::endl;
	std::cout << temp.size() << std::endl;
	std::cout << temp[3] << std::endl;
  return 0;
}
