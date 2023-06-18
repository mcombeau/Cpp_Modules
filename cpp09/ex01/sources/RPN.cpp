/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:49:05 by mcombeau          #+#    #+#             */
/*   Updated: 2023/04/25 12:49:05 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN( void ) {}

RPN::RPN( std::string input )
{
	_checkInput( input );
	_calculate( input );
}

RPN::RPN( RPN & src )
{
	this->_calculator = src._calculator;
}

RPN::~RPN( void ) {}

RPN & RPN::operator=( RPN & src )
{
	this->_calculator = src._calculator;
	return ( *this );
}

int RPN::getResult( void )
{
	_checkCalculatorValidity();
	return ( _calculator.top() );
}

void RPN::_calculate( std::string & input )
{
	if ( VERBOSE )
	{
		std::cout << YELLOW "  Oper\t:\tCalculator Stack" RESET << std::endl;
	}
	while ( 1 )
	{
		try
		{
			std::string elem = _getNextElement( input );
			_handleElement( elem );
		}
		catch ( RPN::EndOfInputException & e )
		{
			break;
		}
	}
}

void RPN::_handleElement( std::string & element )
{
	if ( VERBOSE )
	{
		std::cout << CYAN << "  " << element << "\t:\t";
	}
	if ( _isOperator( element ) )
	{
		_handleOperator( element );
	}
	else if ( _isOperand( element ) )
	{
		_handleOperand( element );
	}
	if ( VERBOSE )
	{
		std::cout << _getCalculatorContentsAsString() << RESET << std::endl;
	}
}

void RPN::_handleOperand( std::string & element )
{
	int operand = std::atoi( element.c_str() );
	_calculator.push( operand );
}

void RPN::_handleOperator( std::string & element )
{
	int second = _getNextOperand();
	int first = _getNextOperand();
	int res = _calculateResult( element, first, second );
	_calculator.push( res );
}

int RPN::_getNextOperand( void )
{
	if ( _calculator.empty() )
	{
		throw ( std::out_of_range( "invalid input: missing operands for operator" ) );
	}
	int operand = _calculator.top();
	_calculator.pop();
	return ( operand );
}

int RPN::_calculateResult( std::string & operation, int first, int second )
{
	int res = 0;
	switch ( operation[0] )
	{
		case '+':
			res = first + second;
			break;
		case '-':
			res = first - second;
			break;
		case '*':
			res = first * second;
			break;
		case '/':
			res = _handleDivision( first, second );
			break;
		default:
			throw ( std::runtime_error( operation + ": invalid operator !" ) );
	}
	return ( res );
}

int RPN::_handleDivision( int first, int second )
{
	if ( second == 0 )
	{
		std::stringstream ss;
		ss << first << " " << second << " /" << ": Illegal operation: cannot divide by 0!";
		throw ( std::runtime_error( ss.str() ) );
	}
	return ( first / second );
}

bool RPN::_isOperand( std::string & string ) const
{
	std::string::iterator it = string.begin();
	for ( ; it != string.end(); it++ )
	{
		if ( it != string.begin() && !std::isdigit( *it ) )
		{
			return ( false );
		}
	}
	return ( true );
}

bool RPN::_isOperator( std::string & string ) const
{
	std::string operators = "+-*/";
	size_t pos = string.find_first_not_of( operators, 0 );
	if ( pos == std::string::npos && string.length() == 1 )
	{
		return ( true );
	}
	return ( false );
}

std::string RPN::_getNextElement( std::string & input )
{
	static std::string::iterator it = input.begin();
	for ( ; it != input.end(); it++ )
	{
		if ( *it == ' ' )
		{
			continue;
		}
		std::string elem = std::string( 1, *it );
		it++;
		return ( elem );
	}
	throw ( RPN::EndOfInputException() );
}

void RPN::_checkInput( std::string & input )
{
	std::string requiredDigits = "0123456789";
	std::string requiredOperators = "+-*/";
	std::string allowed = requiredDigits + requiredOperators + " ";

	size_t pos = input.find_first_not_of( allowed, 0 );
	if ( pos != std::string::npos )
	{
		throw ( std::out_of_range ( "invalid input: can only contain " + allowed ) );
	}
	pos = input.find_first_of( requiredDigits, 0 );
	if ( pos == std::string::npos )
	{
		throw ( std::out_of_range ( "invalid input: requires at least one of " +
		                            requiredDigits ) );
	}
	pos = input.find_first_of( requiredOperators, 0 );
	if ( pos == std::string::npos )
	{
		throw ( std::out_of_range ( "invalid input: requires at least one of " +
		                            requiredOperators ) );
	}
}

void RPN::_checkCalculatorValidity( void )
{
	if ( _calculator.size() != 1 )
	{
		throw ( std::out_of_range( "invalid input: missing operator(s)" ) );
	}
}

std::string RPN::_getCalculatorContentsAsString( void )
{
	std::stringstream contents;
	std::stack<int> copy = _calculator;

	while ( !copy.empty() )
	{
		int nb = copy.top();
		copy.pop();
		contents << "[" << nb << "]";
	}
	return ( contents.str() );
}

const char * RPN::EndOfInputException::what( void ) const throw()
{
	return ( "end of input" );
}
