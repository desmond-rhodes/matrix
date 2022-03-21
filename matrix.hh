#ifndef MATRIX_HH
#define MATRIX_HH

#include <vector>

template <typename T>
class matrix {
	public:
		template <typename... U> matrix(size_t, size_t, U...);

		size_t row() const;
		size_t col() const;

		T& operator()(size_t, size_t);
		T const& operator()(size_t, size_t) const;

		matrix<T> transpose() const;

	private:
		matrix(size_t, size_t, std::initializer_list<T>);

		size_t _row;
		size_t _col;
		std::vector<T> _data;
};

#include "matrix.tt"

#endif
