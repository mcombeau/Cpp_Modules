#ifndef REVERSE_POLISH_NOTATION_HPP
#define REVERSE_POLISH_NOTATION_HPP

#include "Colors.h"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

#define VERBOSE 1

class RPN
{
	private:
		std::stack<int> _calculator;

		void _calculate( std::string & input );
		void _checkInput( std::string & input );
		void _checkOperandValidity( int operand, std::string element );
		void _checkCalculatorValidity( void );
		std::string _getNextElement( std::string & input );
		void _handleElement( std::string element );
		void _handleOperand( std::string element );
		void _handleOperator( std::string element );
		int _getNextOperand( void );
		int _calculateOperation( std::string operation, int first, int second );
		bool _isOperand( std::string string );
		bool _isOperator( std::string string );
		void _printCalculatorContents( void );
		std::string _getCalculatorContentsAsString( void );

		RPN( void );

	public:
		RPN( std::string input );
		RPN( RPN & src );
		~RPN( void );

		RPN & operator=( RPN & src );

		int getResult( void );

		class NoMoreInputException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
};

#endif
