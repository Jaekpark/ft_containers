#include <iostream>
#include "config.hpp"

_BEGIN_NAMESPACE_FT

class foo {
	public:
	foo(void) {
		std::cout << "hi" << std::endl;
	}
};
_END_NAMESPACE_FT

using namespace ft;

int main(void) {
	ft::foo a;
	return 0;
}