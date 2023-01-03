/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 16:42:59 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>
#include <numeric>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define CYAN	"\e[36m"

#define R_MIN -50
#define R_MAX 50
#define SPAN_SIZE 10

void	testSubject(void);
void	displaySpanShortestLongest(Span & sp);
void	addNumbersToSpanOneByOne(Span & sp, unsigned int spanSize);
void	addRangeOfNumbersToSpan(Span & sp, unsigned int spanSize);

int main(void)
{
	std::srand(std::time(NULL));

	testSubject();
	{
		std::cout << std::endl << "---- TEST 0" << std::endl;
		Span sp(SPAN_SIZE);
		::displaySpanShortestLongest(sp);
	}
	{
		std::cout << std::endl << "---- TEST 1" << std::endl;
		Span sp(SPAN_SIZE);
		::addNumbersToSpanOneByOne(sp, SPAN_SIZE);
		::displaySpanShortestLongest(sp);
	}
	{
		std::cout << std::endl << "---- TEST 2" << std::endl;
		Span sp(SPAN_SIZE);
		::addRangeOfNumbersToSpan(sp, SPAN_SIZE);
		::displaySpanShortestLongest(sp);
		::addRangeOfNumbersToSpan(sp, SPAN_SIZE);
		::displaySpanShortestLongest(sp);
		::addRangeOfNumbersToSpan(sp, SPAN_SIZE);
		::displaySpanShortestLongest(sp);
	}
	return 0;
}

void	testSubject(void)
{
	std::cout << "---- SUBJECT TESTS" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Span: " << sp << std::endl;
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

void	addNumbersToSpanOneByOne(Span & sp, unsigned int spanSize)
{
	std::cout << "Adding " << spanSize + 3 << " numbers to span of size " << spanSize << ": ";
	unsigned int	i = 0;
	int	r = 0;
	try
	{
		for (; i != spanSize + 3; i++)
		{
			r = std::rand() % ((R_MAX - R_MIN) + 1) + R_MIN;
			sp.addNumber(r);
			std::cout << "[" << i + 1 << " = " << r << "] ";
		}
	}
	catch (std::exception & e)
	{
		std::cout << std::endl << RED
			"Exception: Cannot add " << i + 1 << "th number: "
			<< e.what() << " (Max range size is " << spanSize << ")." RESET
			<< std::endl << std::endl;
	}
}

void	addRangeOfNumbersToSpan(Span & sp, unsigned int spanSize)
{
	std::list<int>	numbersToAdd;
	for (unsigned int i = 0; i < spanSize / 2; i++)
		numbersToAdd.push_back(std::rand() % ((R_MAX - R_MIN) + 1) + R_MIN);
	
	std::list<int>::iterator begin = numbersToAdd.begin();
	std::list<int>::iterator end = numbersToAdd.end();

	std::cout << "Adding numbers to span: ";
	for (std::list<int>::iterator it = begin; it != end; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl;

	try
	{
		sp.addNumberRange<std::list<int> >(begin, end);
		std::cout << GREEN "OK. Number range successfully added to span." RESET << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception: Cannot add range of " << spanSize / 2 
			<< " numbers: " << e.what() 
			<< " (Max range size is " << spanSize
			<< " and span already has " << sp.getRange().size()
			<< " elements)." RESET << std::endl << std::endl;
	}
}

void	displaySpanShortestLongest(Span & sp)
{
	std::cout << "Span (size " << sp.getRange().size() << "): " << sp << std::endl;

	std::vector<int>	tmp(sp.getRange());
	
	std::sort(tmp.begin(), tmp.end());
	std::cout << CYAN "Sorted span: ";
	for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
		std::cout << "[" << *it << "] ";
	std::cout << RESET << std::endl;
	
	if (sp.getRange().size() > 2)
	{	
		std::vector<int>	difference(tmp);
	
		std::adjacent_difference(tmp.begin(), tmp.end(), difference.begin());
		difference.erase(difference.begin());
		std::cout << CYAN "Adjacent difference: ";
		for (std::vector<int>::const_iterator it = difference.begin(); it != difference.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << RESET << std::endl;
	}
	try
	{
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << "Longest: " << sp.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED "Exception: " << e.what() << RESET << std::endl << std::endl;
	}
}
