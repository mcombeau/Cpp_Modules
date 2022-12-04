/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:09 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/03 11:45:46 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>

#define RESET "\e[0m"
#define GREEN "\e[32m"
#define RED "\e[31m"

enum	e_compare
{
	GREATER,
	LESS,
	GREATER_EQUAL,
	LESS_EQUAL,
	EQUAL,
	NOT_EQUAL,
	MIN,
	MAX
};

enum	e_binary
{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
};

enum	e_unary
{
	PRE_INCREMENT,
	PRE_DECREMENT,
	POST_INCREMENT,
	POST_DECREMENT
};

void	colorTestCompare( Fixed & a, Fixed & b, int comparator )
{
	bool	result;
	bool	expected;

	switch ( comparator )
	{
		case GREATER:
			expected = a.getRawBits() > b.getRawBits();
			result = a > b;
			break;
		case LESS:
			expected = a.getRawBits() < b.getRawBits();
			result = a < b;
			break;
		case GREATER_EQUAL:
			expected = a.getRawBits() >= b.getRawBits();
			result = a >= b;
			break;
		case LESS_EQUAL:
			expected = a.getRawBits() <= b.getRawBits();
			result = a <= b;
			break;
		case EQUAL:
			expected = a.getRawBits() == b.getRawBits();
			result = a == b;
			break;
		case NOT_EQUAL:
			expected = a.getRawBits() != b.getRawBits();
			result = a != b;
			break;
	}
	if ( result == expected )
		std::cout << GREEN << "[OK]\t";
	else
		std::cout << RED << "[KO]\t";
}

void	colorTestBinary( Fixed & a, Fixed & b, int operation )
{
	Fixed	result;
	float	expected = 0;

	switch (operation)
	{
		case ADD:
			result = a + b;
			expected = a.toFloat() + b.toFloat();
			break;
		case SUBTRACT:
			result = a - b;
			expected = a.toFloat() - b.toFloat();
			break;
		case MULTIPLY:
			result = a * b;
			expected = a.toFloat() * b.toFloat();
			break;
		case DIVIDE:
			result = a / b;
			expected = a.toFloat() / b.toFloat();
			break;
	}
	if ( result == expected )
		std::cout << GREEN << "[OK]\t";
	else
		std::cout << RED << "[KO]\t" << "expected: " << expected
			<< ", got: " << result.getRawBits() << std::endl << "\t";
}

void	colorTestUnary( Fixed & a, int operation )
{
	Fixed	result;
	int		expected = 0;

	switch ( operation )
	{
		case PRE_INCREMENT:
			expected = a.getRawBits() + 1;
			result = ++a;
			break ;
		case PRE_DECREMENT:
			expected = a.getRawBits() - 1;
			result = --a;
			break ;
		case POST_INCREMENT:
			expected = a.getRawBits();
			result = a++;
			break ;
		case POST_DECREMENT:
			expected = a.getRawBits();
			result = a--;
			break ;
	}
	if ( result.getRawBits() == expected )
		std::cout << GREEN << "[OK]\t";
	else
		std::cout << RED << "[KO]\t" << "expected: " << expected
			<< ", got: " << result.getRawBits() << std::endl << "\t";
}

void	colorTestMinMax( Fixed & a, Fixed & b, int operation )
{
	Fixed expected;
	Fixed result;

	switch ( operation )
	{
		case MIN:
			expected = ( a.getRawBits() < b.getRawBits() ) ? a : b;
			result = Fixed::min(a, b);
			break ;
		case MAX:
			expected = ( a.getRawBits() > b.getRawBits() ) ? a : b;
			result = Fixed::max(a, b);
			break ;
	}
	if ( expected == result )
		std::cout << GREEN << "[OK]\t";
	else
		std::cout << RED << "[KO]\t" << "expected: " << expected
			<< ", got: " << result.getRawBits() << std::endl << "\t";
}

void	testCompare( Fixed & a, Fixed & b )
{
	std::cout << std::endl
		<< "a: " << a << std::endl
		<< "b: " << b << std::endl;
	colorTestCompare( a, b, GREATER );
	std::cout << "a > b\t: " << std::boolalpha << ( a > b ) << RESET << std::endl;
	colorTestCompare( b, a, GREATER );
	std::cout << "b > a\t: " << std::boolalpha << ( b > a ) << RESET << std::endl;
	colorTestCompare( a, b, LESS );
	std::cout << "a < b\t: " << std::boolalpha << ( a < b ) << RESET << std::endl;
	colorTestCompare( b, a, LESS );
	std::cout << "b < a\t: " << std::boolalpha << ( b < a ) << RESET << std::endl;
	colorTestCompare( a, b, GREATER_EQUAL );
	std::cout << "a >= b\t: " << std::boolalpha << ( a >= b ) << RESET << std::endl;
	colorTestCompare( b, a, GREATER_EQUAL );
	std::cout << "b >= a\t: " << std::boolalpha << ( b >= a ) << RESET << std::endl;
	colorTestCompare( a, b, LESS_EQUAL );
	std::cout << "a <= b\t: " << std::boolalpha << ( a <= b ) << RESET << std::endl;
	colorTestCompare( b, a, LESS_EQUAL );
	std::cout << "b <= a\t: " << std::boolalpha << ( b <= a ) << RESET << std::endl;
	colorTestCompare( a, b, EQUAL );
	std::cout << "a == b\t: " << std::boolalpha << ( a == b ) << RESET << std::endl;
	colorTestCompare( b, a, EQUAL );
	std::cout << "b == a\t: " << std::boolalpha << ( b == a ) << RESET << std::endl;
	colorTestCompare( a, b, NOT_EQUAL );
	std::cout << "a != b\t: " << std::boolalpha << ( a != b ) << RESET << std::endl;
	colorTestCompare( b, a, NOT_EQUAL );
	std::cout << "b != a\t: " << std::boolalpha << ( b != a ) << RESET << std::endl;
}

void	testBinary( Fixed & a, Fixed & b )
{
	std::cout << std::endl
		<< "a: " << a << std::endl
		<< "b: " << b << std::endl;
	colorTestBinary( a, b, ADD );
	std::cout << "a + b = " << a << " + " << b << " = " << ( a + b ) << RESET << std::endl;
	colorTestBinary( a, b, SUBTRACT );
	std::cout << "a - b = " << a << " - " << b << " = " << ( a - b ) << RESET << std::endl;
	colorTestBinary( a, b, MULTIPLY );
	std::cout << "a * b = " << a << " * " << b << " = " << ( a * b ) << RESET << std::endl;
	colorTestBinary( a, b, DIVIDE );
	std::cout << "a / b = " << a << " / " << b << " = " << ( a / b ) << RESET << std::endl;
}

void	testUnary( Fixed & a )
{
	std::cout << std::endl << "a: " << a << std::endl;
	colorTestUnary( a, PRE_INCREMENT );
	std::cout << "++a = " << ++a << RESET << std::endl;
	colorTestUnary( a, PRE_DECREMENT );
	std::cout << "--a = " << --a << RESET << std::endl;
	colorTestUnary( a, POST_INCREMENT );
	std::cout << "a++ = " << a++ << " -> " << a << RESET << std::endl;
	colorTestUnary( a, POST_DECREMENT );
	std::cout << "a-- = " << a-- << " -> " << a << RESET << std::endl;
}

void	testMinMax( Fixed & a, Fixed & b )
{
	std::cout << std::endl
		<< "a: " << a << std::endl
		<< "b: " << b << std::endl;
	colorTestMinMax( a, b, MIN );
	std::cout << "min( a, b ) = " << Fixed::min( a, b ) << RESET << std::endl;
	colorTestMinMax( b, a, MIN );
	std::cout << "min( b, a ) = " << Fixed::min( b, a ) << RESET << std::endl;
	colorTestMinMax( a, b, MAX );
	std::cout << "max( a, b ) = " << Fixed::max( a, b ) << RESET << std::endl;
	colorTestMinMax( b, a, MAX );
	std::cout << "max( b, a ) = " << Fixed::max( b, a ) << RESET << std::endl;
}

void	subjectTests( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int	main( void )
{
	Fixed a( 42.5f );
	Fixed b;

	std::cout << std::endl
		<< "---- Subject tests" << std::endl;
	subjectTests();

	std::cout << std::endl
		<< "---- Comparison operator tests" << std::endl;
	testCompare( a, b );
	b = a;
	testCompare( a, b );

	std::cout << std::endl
		<< "---- Binary operator tests" << std::endl;
	testBinary( a, b );
	a = a + b + 0.25f;
	b = 1700;
	testBinary( a, b );
	a = 8;
	b = -35;
	testBinary( a, b );
	a = INT_MIN;
	b  = INT_MAX;
	testBinary( a, b );

	std::cout << std::endl
		<< "---- Unary operator tests" << std::endl;
	testUnary( a );
	a = 20;
	testUnary( a );

	std::cout << std::endl
		<< "---- Min Max function tests" << std::endl;
	b = -35;
	testMinMax( a, b );

	return ( 0 );
}
