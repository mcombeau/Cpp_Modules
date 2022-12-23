/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:54 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/23 19:04:53 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_CLASS_H
# define CONVERTER_CLASS_H

# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

class Converter
{
	public:
		Converter(void);
		Converter(Converter const & src);
		Converter(std::string const & input);
		~Converter();

		Converter &	operator=(Converter const & src);

		class	NotALiteralException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		int		getAsInt(void) const;
		float	getAsFloat(void) const;
		double	getAsDouble(void) const;
		char	getAsChar(void) const;

		bool	isCharConversionOk(void) const;
		bool	isIntConversionOk(void) const;

		std::string	getCharConversionMessage(void) const;
		std::string getIntConversionMessage(void) const;

		static int const	intMax;
		static int const	intMin;
		static float const	floatMax;
		static float const	floatMin;
		static char const	charMax;
		static char const	charMin;

	private:
		enum	e_flags
		{
			OK = 0x00,
			INT_OVERFLOW = 0x01,
			CHAR_OVERFLOW = 0x02,
			CHAR_UNPRINTABLE = 0x04
		};
		enum	e_types
		{
			DEFAULT = 0,
			INTEGER,
			FLOAT,
			DOUBLE,
			CHARACTER,
			NON_NUM
		};

		int		_type;
		char	_asChar;
		int		_asInt;
		float	_asFloat;
		double	_asDouble;
		int		_errorFlags;

		void	_convertScalar(std::string const & input);
		void	_extractType(std::string const & input);
		bool	_extractInt(std::string const & input);
		bool	_extractFloat(std::string const & input);
		bool	_extractDouble(std::string const & input);
		bool	_extractChar(std::string const & input);
		bool	_extractNonNumeric(std::string const & input);
		void	_castScalarsFromInt(void);
		void	_castScalarsFromFloat(void);
		void	_castScalarsFromDouble(void);
		void	_castScalarsFromChar(void);
		void	_setConversionErrorFlags(void);
};

std::ostream &	operator<<(std::ostream & os, Converter const & converter);

#endif