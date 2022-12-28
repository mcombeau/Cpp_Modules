/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/28 18:13:50 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

#define RESET "\e[0m"
#define BOLD "\e[1m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"

void	testSubject(void);

int	main(void)
{
	::testSubject();
	return 0;
}

void	testSubject(void)
{
	std::cout << "---- SUBJECT TESTS" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack top (expecting 17): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack size (expecting 1): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "Iterating over mstack from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
}
