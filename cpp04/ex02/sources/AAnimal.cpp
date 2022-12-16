/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:04 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/16 17:20:38 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

AAnimal::AAnimal(void) : _type("Unknown Beast")
{
	std::cout << CYAN "Animal default constructor called." RESET << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << CYAN "Animal copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

// AAnimal::AAnimal(std::string const & type) : _type(type)
// {
// 	std::cout << CYAN "Animal type constructor called." RESET << std::endl;
// 	return ;
// }

AAnimal::~AAnimal(void)
{
	std::cout << CYAN "Animal destructor called." RESET << std::endl;
	return ;
}

AAnimal &	AAnimal::operator=(AAnimal const & src)
{
	std::cout << GREEN "Animal assignment overload operator called." RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// std::string const &	AAnimal::getType(void) const
// {
// 	return (this->_type);
// }

void	AAnimal::makeSound(void) const
{
	std::cout << RED << this->_type
		<< ": * Unidentifiable screech *" RESET << std::endl;
	return ;
}
