/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:04:48 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 16:40:53 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>

Span::Span(void) : _range(), _maxSize(0)
{
	return ;
}

Span::Span(unsigned int N) : _range(), _maxSize(N)
{
	return ;
}

Span::Span(Span const & src) : _range(src._range), _maxSize(src._maxSize)
{
	return ;
}

Span::~Span(void)
{
	return ;
}

Span &	Span::operator=(Span const & src)
{
	if (this != & src)
	{
		this->_maxSize = src._maxSize;
		this->_range.clear();
		this->_range.insert(this->_range.end(),
			src._range.begin(), src._range.end());
	}
	return (*this);
}

std::vector<int> const &	Span::getRange(void) const
{
	return (this->_range);
}

void	Span::addNumber(int number)
{
	if (this->_range.size() == this->_maxSize)
		throw (Span::FullRangeException());
	this->_range.push_back(number);
	return ;
}

unsigned int	Span::shortestSpan(void) const
{
	int	shortest;

	if (this->_range.size() < 2)
		throw (Span::RangeTooSmallException());

	std::vector<int>	sorted(this->_range);
	std::sort(sorted.begin(), sorted.end());

	std::vector<int>	difference(sorted);
	std::adjacent_difference(sorted.begin(), sorted.end(), difference.begin());
	shortest = *std::min_element(++(difference.begin()), difference.end());
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_range.size() < 2)
		throw (Span::RangeTooSmallException());
	unsigned int largest = *std::max_element(this->_range.begin(), this->_range.end());
	unsigned int smallest = *std::min_element(this->_range.begin(), this->_range.end());
	return (largest - smallest);
}

// template <typename T>
// void	Span::addNumberRange(typename T::iterator & begin,
// 						typename T::iterator & end)
// {
// 	unsigned int	distance = std::abs(std::distance(begin, end));
	
// 	if (distance > (this->_maxSize - this->_range.size()))
// 		throw (Span::FullRangeException());
// 	else if (distance != 0)
// 		this->_range.insert(this->_range.end(), begin, end);
// 	return ;
// }

const char *	Span::FullRangeException::what(void) const throw()
{
	return ("Too many numbers in range.");
}

const char *	Span::RangeTooSmallException::what(void) const throw()
{
	return ("Too few elements in range to calculate span.");
}

std::ostream &	operator<<(std::ostream &os, Span &obj)
{
    for (std::vector<int>::const_iterator it = obj.getRange().begin();
			it != obj.getRange().end(); ++it)
		std::cout << "[" << *it << "] ";
    return (os);
}
