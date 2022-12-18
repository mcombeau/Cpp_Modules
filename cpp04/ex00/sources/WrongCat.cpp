/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:10 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/18 18:22:38 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << CYAN "WrongCat default constructor called." RESET << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal() 
{
	std::cout << CYAN "WrongCat copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << CYAN "WrongCat destructor called." RESET << std::endl;
	return ;
}

WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	std::cout << GREEN "WrongCat assignment overload operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << YELLOW << this->_type
		<< ": * Meowwwww *" RESET << std::endl;
	return ;
}

