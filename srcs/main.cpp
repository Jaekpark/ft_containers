#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	std::vector<int>::iterator b = a.begin();
	std::vector<int>::iterator e = a.end();

	std::cout << "before" << std::endl;
	while(b != e) {
		std::cout << *b << " ";
		b++;
	}
	std::cout << std::endl << "after" << std::endl;

	a.resize(7, 1);
	b = a.begin();
	e = a.end();
	while(b != e) {
		std::cout << *b << " ";
		b++;
	}
	std::cout << std::endl;
	return 0;
}