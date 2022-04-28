#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a;

	a.push_back(10);
	a.push_back(11);

	std::cout << "a.size : " << a.size() << ", a.capacity : " << a.capacity() << std::endl;
	std::cout << a[0] << std::endl; // 10
	std::cout << a[1] << std::endl; // 11
	std::cout << a[2] << std::endl; // no element, 0
	std::cout << "a.size : " << a.size() << ", a.capacity : " << a.capacity() << std::endl;

	a.reserve(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	std::cout << "a.size : " << a.size() << ", a.capacity : " << a.capacity() << std::endl;
	std::cout << a[0] << std::endl; // 1
	std::cout << a[1] << std::endl; // 2
	std::cout << a[2] << std::endl; // 3, but it's not en element of 'a'.
	std::cout << "a.size : " << a.size() << ", a.capacity : " << a.capacity() << std::endl;

	std::vector<int>::iterator begin = a.begin();
	std::vector<int>::iterator end = a.end();

	while (begin != end) {
		std::cout << *begin << std::endl;
		begin++;
	} // 1, 2
	std::cout << *end << std::endl;
	return 0;
}