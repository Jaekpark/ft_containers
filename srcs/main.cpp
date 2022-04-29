#include <iostream>
#include <vector>
#include <memory>

void	print(std::vector<int>& target) {
	std::vector<int>::iterator begin = target.begin();
	std::cout << "size : " << target.size()
		<< ", capacity : " << target.capacity() << std::endl;
	while (begin != target.end())
		std::cout << *(begin++) << " ";
	std::cout << std::endl;
}

int main(void) {
	std::vector<int> a(3, 1);
	std::vector<int> b(1, 11);

	a.push_back(12);
	print(a);
	print(b);
	std::cout << (a < b) << std::endl;
	return 0;
}