/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:04 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/18 18:22:29 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("Unknown Beast")
{
	std::cout << CYAN "WrongAnimal default constructor called." RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << CYAN "WrongAnimal copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type)
{
	std::cout << CYAN "WrongAnimal type constructor called." RESET << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << CYAN "WrongAnimal destructor called." RESET << std::endl;
	return ;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout << GREEN "WrongAnimal assignment overload operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED << this->_type
		<< ": * Unidentifiable screech *" RESET << std::endl;
	return ;
}
