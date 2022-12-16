/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:04 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 18:32:36 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

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
