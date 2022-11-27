/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:06:45 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 15:11:48 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Zombie::Zombie( void )
{
	std::cout << "A zombie appeared!" << std::endl;
	return ;
}

Zombie::Zombie( std::string name ) : _name( name )
{
	std::cout << "A zombie named " << this->_getName() << " appeared!" << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_getName()
			<< ": Uuuggghhhhuuhhh... nooo braiiiinz... deaaad agaiiiiiin...."
			<< std::endl;
	return ;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string Zombie::_getName( void ) const
{
	return (this->_name);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Zombie::setName( std::string const name )
{
	this->_name = name;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	Zombie::announce( void )
{
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}