/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:38 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/18 18:22:17 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "Dog.hpp"
#include <string>
#include <iostream>

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
