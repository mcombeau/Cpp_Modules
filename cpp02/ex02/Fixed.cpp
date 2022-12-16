/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:01 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/16 10:42:23 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define RESET "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

#define PRINT_MESSAGE 0
/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Fixed::Fixed( void ) : _raw( 0 )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Default constructor called." RESET << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed( int const n ) : _raw( n << _fractionalBits )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Int constructor called." RESET << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _fractionalBits)) )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Float constructor called." RESET << std::endl;
	return ;
}

Fixed::~Fixed( void )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Destructor called." RESET << std::endl;
	return ;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Fixed &	Fixed::operator=( Fixed const & src )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << YELLOW "Copy assignment operator called." RESET << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}

bool	Fixed::operator>( Fixed const & rhs ) const
{
	// TODO for repush: can simply
	//	return ( this->_raw > rhs.getRawBits() );
	if ( this->_raw > rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	if ( this->_raw < rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	if ( this->_raw >= rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	if ( this->_raw <= rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	if ( this->_raw == rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	if ( this->_raw != rhs.getRawBits() )
		return ( true );
	return ( false );
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() + rhs.toFloat() ) );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() - rhs.toFloat() ) );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() * rhs.toFloat() ) );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() / rhs.toFloat() ) );
}

Fixed &	Fixed::operator++( void ) // Prefix, i.e. ++fixed
{
	this->_raw += 1;
	return ( *this );
}

Fixed Fixed::operator++( int ) // Postfix, i.e. fixed++
{
	Fixed	tmp( *this );

	++(*this);
	return ( tmp );
}

Fixed &	Fixed::operator--( void ) // Prefix, i.e. --fixed
{
	this->_raw -= 1;
	return ( *this );
}

Fixed Fixed::operator--( int ) // Postfix, i.e. fixed--
{
	Fixed	tmp( *this );

	--(*this);
	return ( tmp );
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/
int	Fixed::getRawBits( void ) const
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << GREEN "getRawBits member function called." RESET << std::endl;
	return ( this->_raw );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/
void	Fixed::setRawBits( int const raw )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << GREEN "setRawBits member funtion called." RESET << std::endl;
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

Fixed &	Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if ( lhs <= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed const &	Fixed::min( Fixed const & lhs, Fixed const & rhs )
{
	if ( lhs <= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed &	Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if ( lhs >= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed const &	Fixed::max( Fixed const & lhs, Fixed const & rhs )
{
	if ( lhs >= rhs )
		return ( lhs );
	return ( rhs );
}

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return ( os );
}