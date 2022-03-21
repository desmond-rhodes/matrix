#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "matrix.hh"

template <typename T> std::ostream& operator<<(std::ostream&, matrix<T> const&);

int main(int argc, char* argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::vector<std::string> args(argv, argv+argc);

	for (auto const& i : args)
		std::cout << i << ' ';
	std::cout << '\n';

	matrix<double> m {4, 4, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};

	std::cout << "M\n" << m << '\n';
	std::cout << "M^T\n" << m.transpose() << '\n';
	std::cout << "M + M^T\n" << m + m.transpose() << '\n';
	std::cout << "M - M^T\n" << m - m.transpose() << '\n';

	std::cout << "Hello, world!\n";
	return 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, matrix<T> const& m) {
	std::vector<size_t> align(m.col(), 0);
	for (size_t i {0}; i < m.row(); ++i)
		for (size_t j {0}; j < m.col(); ++j) {
			std::ostringstream oss;
			oss << m(i, j);
			if (align[j] < oss.str().length())
				align[j] = oss.str().length();
		}
	for (size_t i {0}; i < m.row(); ++i)
		for (size_t j {0}; j < m.col(); ++j) {
			os.width(align[j]);
			os << m(i, j) << ((j != m.col()-1) ? ' ' : '\n');
		}
	return os;
}
