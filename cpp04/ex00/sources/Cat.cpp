/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:10 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 18:32:02 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

Cat::Cat(void) : Animal()
{
	std::cout << CYAN "Cat default constructor called." RESET << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat const & src) : Animal() 
{
	std::cout << CYAN "Cat copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << CYAN "Cat destructor called." RESET << std::endl;
	return ;
}

Cat &	Cat::operator=(Cat const & src)
{
	std::cout << GREEN "Cat assignment overload operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << this->_type
		<< ": * Meowwwww *" RESET << std::endl;
	return ;
}

