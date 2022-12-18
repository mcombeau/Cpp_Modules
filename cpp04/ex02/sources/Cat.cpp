/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:10 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/18 18:24:29 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.h"
#include <string>
#include <iostream>

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	std::cout << CYAN "Cat default constructor called." RESET << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat const & src) : AAnimal(), _brain(NULL) 
{
	std::cout << CYAN "Cat copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << CYAN "Cat destructor called." RESET << std::endl;
	delete this->_brain;
	return ;
}

Cat &	Cat::operator=(Cat const & src)
{
	std::cout << GREEN "Cat assignment overload operator called." RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Brain *	Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << this->_type
		<< ": * Meowwwww *" RESET << std::endl;
	return ;
}

