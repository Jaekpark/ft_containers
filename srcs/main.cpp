#include <iostream>
#include <iterator>
#include <vector>

#include "config.hpp"
#include "containers/vector.hpp"

int main(void) {
  std::vector<int> origin(5, 10);
  std::vector<int> copy(origin);

  std::cout << copy[0] << std::endl;
  // std::cout << copy.size() << std::endl;
  // std::cout << copy.capacity() << std::endl;
  return 0;
}
