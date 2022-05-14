#include <iostream>
#include <iterator>
#include <vector>

#include "config.hpp"
#include "containers/vector.hpp"

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

int main(void) {
  NAMESPACE::vector<int> origin(1);

  // origin.reserve(10);
  // origin.push_back(1);
  std::cout << origin.size() << std::endl;
  std::cout << origin.front() << std::endl;
  return 0;
}
