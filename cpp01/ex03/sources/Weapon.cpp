/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:18 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 15:18:21 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

#define RESET "\e[0m"
#define GREEN "\e[32m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Constructor	*/
Weapon::Weapon( std::string const type ) : _type( type )
{
	return ;
}

/*	Desctructor	*/
Weapon::~Weapon( void )
{
	return ;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const	&Weapon::getType( void ) const
{
	return ( this->_type );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Weapon::setType( std::string const newType )
{
	if ( newType.empty() && !(this->getType().empty()) )
	{
		std::cout << GREEN
			<< "The " << this->getType() << " vanishes!"
			<< RESET << std::endl;
	}
	else if ( !(this->getType().empty()) )
	{
		std::cout << GREEN
			<< "The " << this->getType() << " magically turns into a " << newType
			<< RESET << std::endl;
	}
	else
	{
		std::cout << GREEN
			<< "A " << newType << " magically appears!"
			<< RESET << std::endl;
	}
	this->_type = newType;
	return ;
}
