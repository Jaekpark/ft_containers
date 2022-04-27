#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);

	std::cout << a.size() << std::endl;
	std::cout << std::distance(a.begin(), a.end()) << std::endl;
	std::cout << a.max_size() << std::endl;
	// 2
	return 0;
}