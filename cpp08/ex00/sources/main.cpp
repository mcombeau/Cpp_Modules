/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/26 15:10:17 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define CYAN	"\e[36m"

void	testSearchVector(std::vector<int> & container, int toFind);

int main(void)
{
	std::vector<int>	container;
	for (int i = -4; i < 10; i++)
		container.push_back(i * 2);
	
	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl;

	testSearchVector(container, 0);
	testSearchVector(container, 10);
	testSearchVector(container, -6);
	testSearchVector(container, 42);
	testSearchVector(container, -1);
	testSearchVector(container, 12);
	testSearchVector(container, 17);
	return (0);
}

void	testSearchVector(std::vector<int> & container, int toFind)
{
	std::cout << std::endl << "--- Searching for " BOLD CYAN "[" << toFind << "]" RESET << std::endl;
	bool	expectToFind = false;
	int		result = 0;

	std::cout << "Vector container: ";
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
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
		result = *(easyfind(container, toFind));
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
