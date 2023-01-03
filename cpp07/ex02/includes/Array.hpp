/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:34:49 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 14:19:26 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP_CLASS_H
# define ARRAY_TPP_CLASS_H

# include <iostream>

template <typename T = int>
class Array
{
	public:
		class OutOfBoundsException : public std::exception {
			public:
				virtual char const *	what(void) const throw() {
					return ("Array out of bounds.");
				}
		};
		
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const & src) : _array(new T[src._size]), _size(src._size) {
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}
		~Array(void) { delete [] _array; }

		Array &	operator=(Array const & src) {
			if (this == &src)
				return (*this);
			if (this->_size != src._size) {
				delete [] _array;
				this->_size = src._size;
				this->_array = new T[this->_size];
			}
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
			return (*this);
		}

		T &	operator[](unsigned int index) {
			if (index >= this->_size)
				throw (OutOfBoundsException());
			return (this->_array[index]);
		}

		unsigned int	size(void) const {
			return (this->_size);
		}	

	private:
		T *				_array;
		unsigned int	_size;
};

template <typename T>
std::ostream &	operator<<(std::ostream &os, Array<T> &obj) {
    for (unsigned int i = 0; i < obj.size(); ++i) {
        os << "[" << obj[i] << "] ";
    }
    return (os);
}

#endif
