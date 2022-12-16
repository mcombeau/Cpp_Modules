/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:04 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 18:32:27 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

Animal::Animal(void) : _type("Unknown Beast")
{
	std::cout << CYAN "Animal default constructor called." RESET << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
	std::cout << CYAN "Animal copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Animal::Animal(std::string const & type) : _type(type)
{
	std::cout << CYAN "Animal type constructor called." RESET << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << CYAN "Animal destructor called." RESET << std::endl;
	return ;
}

Animal &	Animal::operator=(Animal const & src)
{
	std::cout << GREEN "Animal assignment overload operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << RED << this->_type
		<< ": * Unidentifiable screech *" RESET << std::endl;
	return ;
}
