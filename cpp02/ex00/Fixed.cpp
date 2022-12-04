/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:01 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 14:13:10 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#define RESET "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Default Constructor	*/
Fixed::Fixed( void ) : _raw( 0 )
{
	std::cerr << CYAN "Default constructor called." RESET << std::endl;
	return ;
}

/*	Copy Constructor	*/
Fixed::Fixed( Fixed const & src )
{
	std::cerr << CYAN "Copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

/*	Desctructor	*/
Fixed::~Fixed( void )
{
	std::cerr << CYAN "Destructor called." RESET << std::endl;
	return ;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/
Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cerr << YELLOW "Copy assignment operator called." RESET << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/
int	Fixed::getRawBits( void ) const
{
	std::cerr << GREEN "getRawBits member function called." RESET << std::endl;
	return ( this->_raw );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/
void	Fixed::setRawBits( int const raw )
{
	std::cerr << GREEN "setRawBits member funtion called." RESET << std::endl;
	this->_raw = raw;
	return ;
}
