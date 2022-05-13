#include <iostream>
// #include <vector>
// #include <iterator>
#include <vector>
#include "config.hpp"
#include "container/vector.hpp"

int main(void) {
	// std::vector<int> origin;
	ft::vector<int> copy(5);

	std::cout << copy.capacity() << std::endl;
	std::cout << *(copy.begin()) << std::endl;
	// (void)a;
	return 0;
}
