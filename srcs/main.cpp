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

int* test(std::allocator<int>& alloc, int size) {
	int* result = alloc.allocate(size);

	for (int i = 0; i < size; i++)
		alloc.construct(&result[i], i);
	for (int j = 0; j < size; j++)
		std::cout << result[j] << std::endl;
	return result;
}

int main(void) {
	std::vector<int> a;
	int size = 5;

	std::allocator<int> alloc = a.get_allocator();
	int* result = alloc.allocate(size);

	for (int i = 0; i < size; i++)
		alloc.construct(&result[i], i);
	for (int j = 0; j < size; j++)
		std::cout << result[j] << std::endl;
	for (int k = 0; k < size; k++)
		alloc.destroy(&result[k]);
	alloc.deallocate(result, size);
	return 0;
}