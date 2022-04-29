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

	print(a); // 1 1 , size : 2, capacity : 2
	print(b); // 2, size : 1, capacity : 1

	a.clear();
	b.clear();
	print(a); // empty, size : 0, capacity : 2
	print(b); // empty, size : 0, capacity : 1

	return 0;
}