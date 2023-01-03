/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:17:50 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 19:15:10 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_CLASS_H
# define MUTANT_STACK_CLASS_H

#include <stack>
#include <ostream>
#include <algorithm>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		typedef typename std::stack<T, C>::container_type::iterator					iterator;
		typedef typename std::stack<T, C>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T, C>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T, C>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack<T, C>(void) : std::stack<T, C>() {};
		MutantStack<T, C>(MutantStack<T, C> const & src) : std::stack<T, C>(src) {};
		~MutantStack<T, C>(void) {};

		MutantStack<T, C> &	operator=(MutantStack<T, C> const & src) {
			if (this != &src)
				this->c = src.c;
			return (*this);
		}

		MutantStack<T, C>::iterator	begin(void) {
			return (this->c.begin());
		}

		MutantStack<T, C>::iterator	end(void) {
			return (this->c.end());
		}

		MutantStack<T, C>::const_iterator	begin(void) const {
			return (this->c.begin());
		}

		MutantStack<T, C>::const_iterator	end(void) const {
			return (this->c.end());
		}

		MutantStack<T, C>::reverse_iterator	rbegin(void) {
			return (this->c.rbegin());
		}

		MutantStack<T, C>::reverse_iterator	rend(void) {
			return (this->c.rend());
		}

		MutantStack<T, C>::const_reverse_iterator	rbegin(void) const {
			return (this->c.rbegin());
		}

		MutantStack<T, C>::const_reverse_iterator	rend(void) const {
			return (this->c.rend());
		}
};

#endif
