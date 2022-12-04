/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:01 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/03 11:39:12 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
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
	std::cout << CYAN "Default constructor called." RESET << std::endl;
	return ;
}

/*	Copy Constructor	*/
Fixed::Fixed( Fixed const & src )
{
	std::cout << CYAN "Copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

/*	Constructor from integer	*/
Fixed::Fixed( int const n ) : _raw( n << _fractionalBits )
{
	std::cout << CYAN "Int constructor called." RESET << std::endl;
	return ;
}

/*	Constructor from float		*/
Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _fractionalBits)) )
{
	std::cout << CYAN "Float constructor called." RESET << std::endl;
	return ;
}

/*	Desctructor	*/
Fixed::~Fixed( void )
{
	std::cout << CYAN "Destructor called." RESET << std::endl;
	return ;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/
Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cout << YELLOW "Copy assignment operator called." RESET << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/
int	Fixed::getRawBits( void ) const
{
	std::cout << GREEN "getRawBits member function called." RESET << std::endl;
	return ( this->_raw );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/
void	Fixed::setRawBits( int const raw )
{
	std::cout << GREEN "setRawBits member funtion called." RESET << std::endl;
	this->_raw = raw;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/
int		Fixed::toInt( void ) const
{
	return ( this->_raw >> Fixed::_fractionalBits );	
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_raw / (1 << _fractionalBits) );
}

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return ( os );
}