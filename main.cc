#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "matrix.hh"

template <typename T> std::ostream& operator<<(std::ostream&, matrix<T> const&);

int main(int argc, char* argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::vector<std::string> args(argv, argv+argc);

	for (auto const& i: args)
		std::cout << i << ' ';
	std::cout << '\n';

	matrix<double> I {2, 2, 1.0, 0.0, 0.0, 1.0};
	matrix<double> A {2, 2, 1.0, 2.0, 3.0, 4.0};
	matrix<double> B {2, 2, 5.0, 6.0, 7.0, 8.0};
	matrix<double> v {2, 1, 9.0, 10.0};

	std::cout << "I\n" << I << "\n\n";
	std::cout << "A\n" << A << "\n\n";
	std::cout << "B\n" << B << "\n\n";
	std::cout << "v\n" << v << "\n\n";
	std::cout << "I == I " << (I == I) << "\n\n";
	std::cout << "A != A " << (A != A) << "\n\n";
	std::cout << "I == A " << (I == A) << "\n\n";
	std::cout << "A != I " << (A != I) << "\n\n";
	std::cout << "A*I\n" << A*I << "\n\n";
	std::cout << "I*A\n" << I*A << "\n\n";
	std::cout << "Av\n" << (A*v) << "\n\n";
	std::cout << "Bv\n" << (B*v) << "\n\n";
	std::cout << "AI == IA " << (A*I == I*A) << "\n\n";
	std::cout << "AB == BA " << (A*B == B*A) << "\n\n";
	std::cout << "I == v " << (I == v) << "\n\n";

	matrix<unsigned long long> F0 {2, 2, 1ul, 1ul, 1ul, 0ul};
	matrix<unsigned long long> Fn {2, 2, 1ul, 0ul, 0ul, 1ul};
	std::cout << "Fibonacci matrix\n\n";
	for (size_t i {0}; i < 10; ++i)
		std::cout << (Fn *= F0) << "\n\n";

	std::cout << "Hello, world!\n";
	return 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, matrix<T> const& m) {
	std::vector<size_t> align(m.col());
	for (auto& i : align)
		i = 0;

	for (size_t i {0}; i < m.row(); ++i) {
		for (size_t j {0}; j < m.col(); ++j) {
			auto length {std::to_string(m(i, j)).size()};
			if (align[j] < length)
				align[j] = length;
		}
	}

	for (size_t i {0}; i < m.row(); ++i) {
		for (size_t j {0}; j < m.col(); ++j) {
			os << std::setw(align[j]) << std::to_string(m(i, j));
			if (j != m.col()-1)
				os << ' ';
		}
		if (i != m.row()-1)
			os << '\n';
	}

	return os;
}
