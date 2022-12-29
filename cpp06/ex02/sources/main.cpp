/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/29 13:57:13 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "Colors.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *	generate(void)
{
	int	rnb = std::rand() % 3;

	switch (rnb)
	{
		case 0:
			std::cout << "Generated: " CYAN "A" RESET;
			return (new A);
		case 1:
			std::cout << "Generated: " YELLOW "B" RESET;
			return (new B);
		case 2:
			std::cout << "Generated: " PURPLE "C" RESET;
			return (new C);
	}
	return (NULL);
}

void	identify(Base * p)
{
	std::cout << "Identified as pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << CYAN "A" RESET;
	else if (dynamic_cast<B *>(p))
		std::cout << YELLOW "B" RESET;
	else if (dynamic_cast<C *>(p))
		std::cout << PURPLE "C" RESET;
	else
		std::cout << RED "Unknown" RESET;
}

void	identify(Base & p)
{
	std::cout << "Identified as reference: ";
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << CYAN "A" RESET;
	}
	catch (std::exception & e) { }
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << YELLOW "B" RESET;
	}
	catch (std::exception & e) { }
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << PURPLE "C" RESET;
	}
	catch (std::exception & e) { }
}

int	main(void)
{
	Base *	p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 25; i++)
	{
		std::cout << "Test [" << i << "]:\t";
		p = generate();
		std::cout << ", ";
		identify(p);
		std::cout << ", ";
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}
