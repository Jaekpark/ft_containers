#include <iostream>
#include <vector>
#include <iterator>
#include "config.hpp"

_BEGIN_NAMESPACE_FT

class foo {
	public:
	foo(void) {
		std::cout << "hi" << std::endl;
	}
};
_END_NAMESPACE_FT


int main(void) {
	std::vector<int> a(5, 5);

	return 0;
}