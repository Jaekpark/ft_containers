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
	std::vector<int> a; // empty.
	
	// a.pop_back(); // Undefined behavior
	a.push_back(1); // add 1
	print(a); // size : 1 , capacity : 1 | a -> 1
	a.push_back(2); // add 2
	print(a); // size : 2, capacity : 2 | a -> 1 2
	a.pop_back();
	print(a); // size : 1, capacity: 2 | a -> 1
	return 0;
}