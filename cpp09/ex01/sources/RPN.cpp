#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <exception>
#include <limits>
#include <sstream>
#include <stdexcept>

RPN::RPN( void ) {}

RPN::RPN( std::string input )
{
	_checkInput( input );
	/* TODO: parse, add to stack and calculate */
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

int RPN::getResult( void ) const
{
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
		catch ( RPN::NoMoreInputException & e )
		{
			std::cout << CYAN "Caught no more input exception: " << e.what() << RESET <<
			          std::endl;
			break;
		}
	}
}

void RPN::_handleElement( std::string element )
{
	/* TODO: what if there are only operators / only operands in input ?? */
	if ( _isOperator( element ) )
	{
		/* TODO: if there are more than 2 elems in _calculator stack, throw error */
		/* else, pop elems, do calc and push result */
		std::cout << element << " is operator yay !" << std::endl;
	}
	else if ( _isOperand( element ) )
	{
		int operand = std::atoi( element.c_str() );
		if ( operand >= 10 )
		{
			throw ( std::out_of_range ( element + ": operand cannot be above 9" ) );
		}
		if ( operand <= -10 )
		{
			throw ( std::out_of_range ( element + ": operand cannot be below -9 " ) );
		}
		_calculator.push( operand );
	}
	else
	{
		throw ( std::out_of_range( element + ": invalid element" ) );
	}
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
	std::cout << string << ": is operand" << std::endl;
	return ( true );
}

bool RPN::_isOperator( std::string string )
{
	std::string operands = "+-*/";
	size_t pos = string.find_first_not_of( operands, 0 );
	if ( pos == std::string::npos && string.length() == 1 )
	{
		std::cout << string << ": is operator" << std::endl;
		return ( true );
	}
	return ( false );
}

std::string RPN::_getNextElement( std::string & input )
{
	static size_t i = 0;
	while ( i <= input.length() )
	{
		size_t begin = i;
		size_t end = input.find( " ", begin );
		if ( end == std::string::npos )
		{
			end = input.length();
		}
		std::string elem = input.substr( begin, end - begin );
		std::cout << YELLOW "Elem [begin " << begin << "][end " << end << "]: [" <<
		          elem << "]" RESET << std::endl;
		i = end + 1;
		return ( elem );
	}
	throw ( RPN::NoMoreInputException() );
}

void RPN::_checkInput( std::string & input )
{
	std::string allowed = "0123456789+-*/ ";
	size_t pos = input.find_first_not_of( allowed, 0 );
	if ( pos != std::string::npos )
	{
		throw ( std::out_of_range ( input + ": invalid input" ) );
	}
}

const char * RPN::NoMoreInputException::what( void ) const throw()
{
	return ( "end of input" );
}
