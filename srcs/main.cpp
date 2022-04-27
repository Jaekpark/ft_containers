#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	std::vector<int>::reverse_iterator rbegin = a.rbegin();
	std::vector<int>::reverse_iterator rend = a.rend();

	std::cout << *rbegin << std::endl;
	std::cout << *rend << std::endl;

	std::cout << *(++rbegin) << std::endl;
	std::cout << *(--rend) << std::endl; 

	--rbegin;
	++rend;
	
	while (rbegin != rend) {
		std::cout << *rbegin << std::endl;
		rbegin++;
	}

	return 0;
}