#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	std::cout << a.back() << std::endl; // 2

	std::vector<int> b;
	std::cout << b.back() << std::endl; // segmentation fault

	return 0;
}