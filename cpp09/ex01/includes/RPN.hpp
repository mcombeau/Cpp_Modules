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

class RPN
{
	private:
		std::stack<int> _calculator;

		void _calculate( std::string & input );
		void _checkInput( std::string & input );
		std::string _getNextElement( std::string & input );
		void _handleElement( std::string element );
		bool _isOperand( std::string string );
		bool _isOperator( std::string string );

		RPN( void );

	public:
		RPN( std::string input );
		RPN( RPN & src );
		~RPN( void );

		RPN & operator=( RPN & src );

		int getResult( void ) const;

		class NoMoreInputException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
};

#endif
