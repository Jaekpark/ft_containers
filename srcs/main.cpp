#include <iostream>
#include <vector>
#include <exception>

int main(void) {
	std::vector<int> a;

	a.push_back(10);
	a.push_back(11);

	try {
		std::cout << a.at(0) << std::endl;
		std::cout << a.at(1) << std::endl;
		std::cout << a.at(2) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}