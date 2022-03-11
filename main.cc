#include <iostream>
#include <vector>
#include <string>
#include "matrix.hh"

int main(int argc, char* argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::vector<std::string> args(argv, argv+argc);

	for (auto const& i: args)
		std::cout << i << ' ';
	std::cout << '\n';

	matrix<int> m {3, 3, 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	print(m);

	std::cout << "Hello, world!\n";
	return 0;
}

template <typename T>
void print(matrix<T> m) {
	for (size_t i {0}; i < m.data.size(); ++i)
		std::cout << m.data[i] << ((i%m.col == m.col-1) ? '\n' : ' ');
}
