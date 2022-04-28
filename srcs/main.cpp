#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a(5);

	std::cout << a.capacity() << std::endl;
	a.reserve(1);
	std::cout << a.capacity() << std::endl;
	a.reserve(10);
	std::cout << a.capacity() << std::endl;
	a.reserve(6);
	std::cout << a.capacity() << std::endl;

	return 0;
}