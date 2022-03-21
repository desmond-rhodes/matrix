#ifndef MATRIX_HH
#define MATRIX_HH

#include <vector>
#include <tuple>

template <typename T>
class matrix {
	public:
		template <typename... U> matrix(size_t, size_t, U...);

		size_t row() const;
		size_t col() const;

		std::pair<size_t, size_t> dimension() const;

		T& operator()(size_t, size_t);
		T const& operator()(size_t, size_t) const;

		matrix<T>& operator+=(matrix<T> const&);
		matrix<T>& operator-=(matrix<T> const&);
		matrix<T>& operator*=(T const&);
		matrix<T>& operator/=(T const&);

		matrix<T> transpose() const;

	private:
		matrix(size_t, size_t, std::initializer_list<T>);

		size_t _row;
		size_t _col;
		std::vector<T> _data;
};

template <typename T> bool operator==(matrix<T> const&, matrix<T> const&);
template <typename T> bool operator!=(matrix<T> const&, matrix<T> const&);

template <typename T> matrix<T> operator+(matrix<T> const&, matrix<T> const&);
template <typename T> matrix<T> operator+(matrix<T>&&, matrix<T> const&);
template <typename T> matrix<T> operator+(matrix<T> const&, matrix<T>&&);

template <typename T> matrix<T> operator-(matrix<T> const&, matrix<T> const&);
template <typename T> matrix<T> operator-(matrix<T>&&, matrix<T> const&);

template <typename T> matrix<T> operator*(T const&, matrix<T> const&);
template <typename T> matrix<T> operator*(T const&, matrix<T>&&);
template <typename T> matrix<T> operator*(matrix<T> const&, T const&);
template <typename T> matrix<T> operator*(matrix<T>&&, T const&);

template <typename T> matrix<T> operator/(matrix<T> const&, T const&);
template <typename T> matrix<T> operator/(matrix<T>&&, T const&);

template <typename T> matrix<T> operator*(matrix<T> const&, matrix<T> const&);
template <typename T> matrix<T>& operator*=(matrix<T>&, matrix<T> const&);

#include "matrix.tt"

#endif
