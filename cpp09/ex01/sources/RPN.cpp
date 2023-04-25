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

void RPN::_handleElement( std::string element )
{
	if ( _isOperator( element ) )
	{
		_handleOperator( element );
	}
	else if ( _isOperand( element ) )
	{
		_handleOperand( element );
	}
	else
	{
		throw ( std::out_of_range( element + ": invalid element" ) );
	}
}

void RPN::_handleOperand( std::string element )
{
	int operand = std::atoi( element.c_str() );
	_checkOperandValidity( operand, element );
	_calculator.push( operand );
	/* _printCalculatorContents(); */
}

void RPN::_handleOperator( std::string element )
{
	int second = _getNextOperand();
	int first = _getNextOperand();
	if ( VERBOSE )
	{
		std::cout << CYAN << "Calculating [" << first << " " << second << " " <<
		          element << "] : ";
	}
	int res = _calculateOperation( element, first, second );
	if ( VERBOSE )
	{
		std::cout << first << " " << element << " " << second << " = " << res << RESET
		          << std::endl;
	}
	_calculator.push( res );
	/* _printCalculatorContents(); */
}

int RPN::_getNextOperand( void )
{
	if ( _calculator.empty() )
	{
		throw ( std::out_of_range( "invalid input: not enough operands for operators" ) );
	}
	int operand = _calculator.top();
	_calculator.pop();

	return ( operand );
}

int RPN::_calculateOperation( std::string operation, int first, int second )
{
	int res = 0;
	if ( operation == "+" )
	{
		res = first + second;
	}
	else if ( operation == "-" )
	{
		res = first - second;
	}
	else if ( operation == "*" )
	{
		res = first * second;
	}
	else if ( operation == "/" )
	{
		res = first / second;
	}
	else
	{
		throw ( std::runtime_error( operation + ": invalid operator !" ) );
	}
	return ( res );
}

bool RPN::_isOperand( std::string string )
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

bool RPN::_isOperator( std::string string )
{
	std::string operands = "+-*/";
	size_t pos = string.find_first_not_of( operands, 0 );
	if ( pos == std::string::npos && string.length() == 1 )
	{
		return ( true );
	}
	return ( false );
}

std::string RPN::_getNextElement( std::string & input )
{
	static size_t i = 0;
	while ( i <= input.length() )
	{
		while ( isblank( input[i] ) )
		{
			i++;
		}
		size_t begin = i;
		size_t end = input.find( " ", begin );
		if ( end == std::string::npos )
		{
			end = input.length();
		}
		std::string elem = input.substr( begin, end - begin );
		i = end + 1;
		return ( elem );
	}
	throw ( RPN::EndOfInputException() );
}

void RPN::_checkInput( std::string & input )
{
	std::string requiredDigits = "0123456789";
	std::string requiredOperands = "+-*/";
	std::string allowed = requiredDigits + requiredOperands + " ";
	size_t pos = input.find_first_not_of( allowed, 0 );
	if ( pos != std::string::npos )
	{
		throw ( std::out_of_range ( input +
		                            ": invalid input: can only contain " + allowed ) );
	}
	pos = input.find_first_of( requiredDigits, 0 );
	if ( pos == std::string::npos )
	{
		throw ( std::out_of_range ( input +
		                            ": invalid input: requires at least one digit" ) );
	}
	pos = input.find_first_of( requiredOperands, 0 );
	if ( pos == std::string::npos )
	{
		throw ( std::out_of_range ( input +
		                            ": invalid input: requires at least one operator +-*/" ) );
	}
}

void RPN::_checkOperandValidity( int operand, std::string element )
{
	if ( operand >= 10 )
	{
		throw ( std::out_of_range ( element + ": operand cannot be above 9" ) );
	}
	if ( operand <= -10 )
	{
		throw ( std::out_of_range ( element + ": operand cannot be below -9 " ) );
	}
}

void RPN::_checkCalculatorValidity( void )
{
	if ( _calculator.size() != 1 )
	{
		throw ( std::out_of_range( "invalid input: missing operator(s): result contains "
		                           + _getCalculatorContentsAsString() ) );
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

void RPN::_printCalculatorContents( void )
{
	if ( !VERBOSE )
	{
		return ;
	}
	std::cout << PURPLE << "Calculator contains: ";
	std::string contents = _getCalculatorContentsAsString();
	std::cout << contents << RESET << std::endl;
}

const char * RPN::EndOfInputException::what( void ) const throw()
{
	return ( "end of input" );
}
