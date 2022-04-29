#include <iostream>
#include <vector>

void	print(std::vector<int>& target) {
	std::vector<int>::iterator begin = target.begin();
	std::cout << "size : " << target.size()
		<< ", capacity : " << target.capacity() << std::endl;
	while (begin != target.end())
		std::cout << *(begin++) << " ";
	std::cout << std::endl;
}

int main(void) {
	std::vector<int> a(2, 1);
	std::vector<int> b(1, 2);

	print(a);
	print(b);
	a.swap(b);
	print(a);
	print(b);

	std::swap(a, b);
	print(a);
	print(b);
	return 0;
}