/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:19:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 14:04:51 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

#define RESET "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

# define PRINT_MESSAGE 0

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/
Point::Point( void ) : _x( 0 ), _y( 0 )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << "Point default constructor called." << std::endl;
	return ;
}

Point::Point( Fixed const x, Fixed const y ) : _x( x ), _y( y )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << "Point fixed constructor called." << std::endl;
	return ;
}

Point::Point( Point const & src ) : _x( src.getX() ), _y( src.getY() )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << "Point copy constructor called." << std::endl;
	return ;
}

Point::~Point( void )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << "Point destructor called." << std::endl;
	return ;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/
Point &	Point::operator=( Point const & rhs )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << "Point assignment operator called." << std::endl;
	if ( this != &rhs )
	{
		Point copy(rhs.getX(), rhs.getY());
		*this = copy;
	}
	return ( *this );
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/
Fixed const &	Point::getX( void ) const
{
	return ( this->_x );
}

Fixed const &	Point::getY( void ) const
{
	return ( this->_y );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/
