/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/28 18:23:26 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define CYAN	"\e[36m"

template <typename T>
void	testSearch(std::string containerType, T & container, int toFind);

int main(void)
{
	{
		std::cout << std::endl << "---- TEST VECTOR CONTAINER" << std::endl;
		
		std::vector<int>	container;

		std::cout << "Vector container: ";
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::testSearch("Vector", container, 0);
		std::cout << std::endl;

		for (int i = -4; i < 10; i++)
			container.push_back(i * 2);
		
		std::cout << "Vector container: ";
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::testSearch("Vector", container, 0);
		::testSearch("Vector", container, 10);
		::testSearch("Vector", container, -6);
		::testSearch("Vector", container, 42);
		::testSearch("Vector", container, -1);
		::testSearch("Vector", container, 12);
		::testSearch("Vector", container, 17);
	}
	{
		std::cout << std::endl << "---- TEST LIST CONTAINER" << std::endl;
		std::list<int>	container;

		std::cout << "List container: ";
		for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::testSearch("List", container, 0);
		std::cout << std::endl;
		
		for (int i = -4; i < 20; i++)
			container.push_front(i * 10 + i);
		
		std::cout << "List container: ";
		for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::testSearch("List", container, 0);
		::testSearch("List", container, 99);
		::testSearch("List", container, -44);
		::testSearch("List", container, 42);
		::testSearch("List", container, -1);
		::testSearch("List", container, 22);
		::testSearch("List", container, 17);
	}
	{
		std::cout << std::endl << "---- TEST DEQUE CONTAINER" << std::endl;
		std::deque<int>	container;

		std::cout << "Deque container: ";
		for (std::deque<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::testSearch("Deque", container, 0);
		std::cout << std::endl;

		for (int i = 0; i < 15; i++)
			container.push_back((i - 4) * 100 + i + 3);
		
		std::cout << "Deque container: ";
		for (std::deque<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::testSearch("Deque", container, 7);
		::testSearch("Deque", container, 916);
		::testSearch("Deque", container, -296);
		::testSearch("Deque", container, -1);
		::testSearch("Deque", container, 42);
		::testSearch("Deque", container, 202);
		::testSearch("Deque", container, 512);
	}
	return (0);
}

template <typename T>
void	testSearch(std::string containerType, T & container, int toFind)
{
	std::cout << std::endl << "- Searching for " BOLD CYAN "[" << toFind << "]" RESET << std::endl;
	bool	expectToFind = false;
	int		result = 0;

	std::cout << containerType << " container: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == toFind && expectToFind == false)
		{
			expectToFind = true;
			std::cout << BOLD YELLOW;
		}
		std::cout << "[" << *it << "] " RESET;
	}
	std::cout << std::endl;
	try
	{
		result = *(::easyfind(container, toFind));
		if (expectToFind == false)
			std::cout << RED BOLD "KO. " RESET
				RED "Easyfind found " << result << ". (Expected exception!)" RESET << std::endl;
		else
			std::cout << GREEN BOLD "OK. " RESET GREEN << "Found " << result << ", as expected." RESET << std::endl;
	}
	catch (std::exception & e)
	{
		if (expectToFind == false)
			std::cout << GREEN BOLD "OK. " RESET GREEN "Easyfind threw exception: " << e.what()
				<< ". (Expected exception.)" RESET << std::endl;
		else
			std::cout << RED BOLD "KO. " RESET RED "Easyfind threw exception: " << e.what()
				<< ". (Expected to find element in container!)" RESET << std::endl;
	}
}
