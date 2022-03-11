#ifndef MATRIX_HH
#define MATRIX_HH

#include <vector>

template <typename T>
class matrix {
	public:
		template <typename ...U>
		matrix(size_t, size_t, U...);

		template <typename U>
		friend void print(matrix<U>);

	private:
		matrix(size_t, size_t, std::initializer_list<T>);

		size_t row;
		size_t col;
		std::vector<T> data;
};

#include "matrix.tt"

#endif
