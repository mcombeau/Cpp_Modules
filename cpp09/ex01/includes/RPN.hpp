/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:50:38 by mcombeau          #+#    #+#             */
/*   Updated: 2023/04/25 12:50:38 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_POLISH_NOTATION_HPP
#define REVERSE_POLISH_NOTATION_HPP

#include "Colors.h"
#include <cctype>
#include <cstddef>
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
		std::string _getNextElement( std::string & input );
		void _handleElement( std::string & element );
		void _handleOperand( std::string & element );
		void _handleOperator( std::string & element );
		int _getNextOperand( void );
		int _calculateResult( std::string & operation, int first, int second );
		int _handleDivision( int first, int second );

		bool _isOperand( std::string & string ) const;
		bool _isOperator( std::string & string ) const;

		void _checkInput( std::string & input );
		void _checkCalculatorValidity( void );

		std::string _getCalculatorContentsAsString( void );

		RPN( void );

	public:
		RPN( std::string input );
		RPN( RPN & src );
		~RPN( void );

		RPN & operator=( RPN & src );

		int getResult( void );

		class EndOfInputException : public std::exception
		{
			public:
				virtual const char * what( void ) const throw();
		};
};

#endif
