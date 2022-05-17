#include <iostream>
#include <iterator>
#include <vector>

#include "config.hpp"
#include "containers/vector.hpp"

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

int main(void) {
  NAMESPACE::vector<int> origin(1, 10);

  std::cout << origin.size() << std::endl;
  std::cout << origin[1] << std::endl;
  return 0;
}
