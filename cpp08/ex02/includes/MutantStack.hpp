/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:17:50 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 17:22:18 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_CLASS_H
# define MUTANT_STACK_CLASS_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack<T>(void) : std::stack<T>() {};
		MutantStack<T>(MutantStack<T> const & src) : std::stack<T>(src) {};
		~MutantStack<T>(void) {};

		MutantStack<T> &	operator=(MutantStack<T> const & src) {
			if (this != &src)
				this->c = src.c;
			return (*this);
		}

		MutantStack<T>::iterator	begin(void) {
			return (this->c.begin());
		}

		MutantStack<T>::iterator	end(void) {
			return (this->c.end());
		}

		MutantStack<T>::const_iterator	begin(void) const {
			return (this->c.begin());
		}

		MutantStack<T>::const_iterator	end(void) const {
			return (this->c.end());
		}

		MutantStack<T>::reverse_iterator	rbegin(void) {
			return (this->c.rbegin());
		}

		MutantStack<T>::reverse_iterator	rend(void) {
			return (this->c.rend());
		}

		MutantStack<T>::const_reverse_iterator	rbegin(void) const {
			return (this->c.rbegin());
		}

		MutantStack<T>::const_reverse_iterator	rend(void) const {
			return (this->c.rend());
		}
};

#endif
