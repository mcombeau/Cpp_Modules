/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:38 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/16 13:02:13 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << CYAN "Dog default constructor called." RESET << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog const & src) : Animal(src._type)
{
	std::cout << CYAN "Dog copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << CYAN "Dog destructor called." RESET << std::endl;
	return ;
}

Dog &	Dog::operator=(Dog const & src)
{
	std::cout << GREEN "Dog assignment overload operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << this->_type
		<< ": * Arf! Arf! Arf! *" RESET << std::endl;
	return ;
}
