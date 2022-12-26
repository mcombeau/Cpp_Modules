/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:04:12 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/26 17:51:29 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

# include <vector>
# include <iostream>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		~Span();

		Span &	operator=(Span const & src);

		std::vector<int> const &	getRange(void) const;

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		template <typename T>
		void			fillFromIntContainer(T const & container);

		class	FullRangeException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
		class	RangeTooSmallException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
		
	private:
		std::vector<int>	_range;
		unsigned int		_maxSize;
};

std::ostream &	operator<<(std::ostream &os, Span &obj);

#endif
