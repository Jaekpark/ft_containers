#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a;

	a.push_back(11);
	a.push_back(12);
	a.push_back(13);

	std::vector<int>::iterator begin = a.begin();
	std::vector<int>::iterator end = a.end();
	
	std::cout << *begin << std::endl;
	std::cout << *end << std::endl;

	while (begin != end) {
		std::cout << *begin << std::endl;
		begin++;
	}
	
	std::cout << *end << std::endl;
	std::cout << *(--end) << std::endl;

	return 0;
}