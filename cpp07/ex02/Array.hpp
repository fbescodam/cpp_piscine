/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 19:08:06 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/03 20:28:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <array>

template <typename T>
class Array
{
	private:
		// array initializor
		void initArray(unsigned int n) {
			this->n = n;
			this->arr = new T[n];
		};

	public:
		// constructors
		Array() {
			this->initArray(0);
		}
		Array(const unsigned int n) {
			this->initArray(n);
		};

		// copy constructor (calls copy operator)
		Array(const Array& other) {
			*this = other;
		};

		// copy operator
		Array& operator = (const Array& other) {
			this->initArray(other.size());
			for (size_t i = 0; i < this->n; i++)
				this->arr[i] = other[i];
			return (*this);
		};

		// destructor
		~Array() {
			if (this->arr)
				delete[] this->arr;
		};

		// subscript operator
		T& operator [] (size_t index) const {
			if (index < 0 || index >= this->n)
				throw std::exception();
			return this->arr[index];
		};

		// member functions
		size_t size(void) const {
			return this->n;
		};

	private:
		unsigned int	n;
		T*				arr;
};
