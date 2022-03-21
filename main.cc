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
	std::cout << "2M\n" << 2.0 * m << '\n';
	std::cout << "M\n-\n2\n" << m / 2.0 << '\n';

	matrix<unsigned int> const f0 {2, 2, 1u, 1u, 1u, 0u};
	size_t const n {10};

	matrix<unsigned int> fn {2, 2, 1u, 0u, 0u, 1u};
	std::cout << "Fibonacci matrix\n";
	for (size_t i {0}; i < n; ++i) {
		fn *= f0;
		std::cout << "F" << i << '\n' << fn << '\n';
	}

	matrix<double> i3 {3, 3, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

	std::cout << "I == I   " << (i3 == i3) << '\n';
	std::cout << "I == I^T " << (i3 == i3.transpose()) << '\n';
	std::cout << "I == I+I " << (i3 == i3 + i3) << '\n';
	std::cout << "M == I   " << (m == i3) << '\n';
	std::cout << "M != 2M  " << (m != 2.0 * m) << '\n';

	matrix<double> a {3, 3, 2.0, 3.0, 5.0, 7.0, 11.0, 13.0, 17.0, 19.0, 23.0};

	std::cout << '\n';
	std::cout << "A\n" << a << '\n';

	a.row_swap(0, 2);
	std::cout << "bi <-> bj\n";
	std::cout << "~~~~~~~~~\n";
	std::cout << "A\n" << a << '\n';

	a.row_times(1.0 / a(1, 1), 1);
	std::cout << "k bi\n";
	std::cout << "~~~~\n";
	std::cout << "A\n" << a << '\n';

	a.row_add(a(2, 2) / a(0, 2) * -1.0, 0, 2);
	std::cout << "k bi + bj\n";
	std::cout << "~~~~~~~~~\n";
	std::cout << "A\n" << a << '\n';

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
