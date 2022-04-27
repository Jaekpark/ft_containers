#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> a(0);

	std::vector<int>::iterator iter = a.begin();

	std::cout << &iter << std::endl;

	return 0;
}