/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:40 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/24 12:51:24 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include "Colors.h"

#define	PRINT_MSG 0

int const	Converter::intMax = std::numeric_limits<int>::max();
int const	Converter::intMin = std::numeric_limits<int>::min();
float const	Converter::floatMax = std::numeric_limits<float>::max();
float const	Converter::floatMin = std::numeric_limits<float>::min();
char const	Converter::charMax = std::numeric_limits<char>::max();
char const	Converter::charMin = std::numeric_limits<char>::min();

Converter::Converter(void) : _type(DEFAULT),
							 _asChar(0),
							 _asInt(0),
							 _asFloat(0),
							 _asDouble(0),
							 _errorFlags(OK)
{
	if (PRINT_MSG == 1)
		std::cout << CYAN "Converter default constructor called." RESET << std::endl;
	return ;
}

Converter::Converter(Converter const &src) : _type(src._type),
											 _asChar(src._asChar),
											 _asInt(src._asInt),
											 _asFloat(src._asFloat),
											 _asDouble(src._asDouble),
											 _errorFlags(src._errorFlags)
{
	if (PRINT_MSG == 1)
		std::cout << CYAN "Converter copy constructor called." RESET << std::endl;
	return ;
}

Converter::Converter(std::string const &input) : _type(DEFAULT),
												 _asChar(0),
												 _asInt(0),
												 _asFloat(0),
												 _asDouble(0),
												 _errorFlags(OK)
{
	if (PRINT_MSG == 1)
		std::cout << CYAN "Converter input constructor called." RESET << std::endl;
	this->_convertScalar(input);
	return ;
}

Converter::~Converter(void)
{
	if (PRINT_MSG == 1)
		std::cout << CYAN "Converter destructor called." RESET << std::endl;
	return ;
}

Converter &	Converter::operator=(Converter const &src)
{
	if (PRINT_MSG == 1)
		std::cout << CYAN "Converter assignment operator overload called." RESET << std::endl;
	this->_asChar = src._asChar;
	this->_asInt = src._asInt;
	this->_asFloat = src._asFloat;
	this->_asDouble = src._asDouble;
	this->_errorFlags = src._errorFlags;
	return (*this);
}

int	Converter::getAsInt(void) const
{
	return (this->_asInt);
}

float	Converter::getAsFloat(void) const
{
	return (this->_asFloat);
}

double	Converter::getAsDouble(void) const
{
	return (this->_asDouble);
}

char	Converter::getAsChar(void) const
{
	return (this->_asChar);
}

void	Converter::_convertScalar(std::string const &input)
{
	_extractType(input);
	switch (this->_type)
	{
		case INTEGER:
			_castScalarsFromInt();
			break;
		case FLOAT:
			_castScalarsFromFloat();
			break;
		case DOUBLE:
			_castScalarsFromDouble();
			break;
		case CHARACTER:
			_castScalarsFromChar();
			break;
		case NON_NUM:
			break;
		default:
			throw(Converter::NotALiteralException());
	}
}

void	Converter::_extractType(std::string const & input)
{
	if (_extractInt(input))
		this->_type = INTEGER;
	else if (_extractFloat(input))
		this->_type = FLOAT;
	else if (_extractDouble(input))
		this->_type = DOUBLE;
	else if (_extractChar(input))
		this->_type = CHARACTER;
	else if (_extractNonNumeric(input))
		this->_type = NON_NUM;
	return ;
}

bool	Converter::_extractInt(std::string const & input)
{
	char *end;
	long nb = std::strtol(input.c_str(), &end, 10);

	if (end == input.c_str() || *end != '\0')
		return (false);
	if (nb > intMax || nb < intMin)
	{
		_errorFlags += INT_OVERFLOW;
		return (false);
	}
	this->_asInt = static_cast<int>(nb);
	return (true);
}

bool	Converter::_extractFloat(std::string const & input)
{
	char	*end;
	float	nb = std::strtof(input.c_str(), &end);
	
	if (end == input.c_str() || *end != 'f')
		return (false);
	if (*end == 'f' && (end + 1 && *(end + 1) != '\0'))
		return (false);
	this->_asFloat = nb;
	return (true);
}

bool	Converter::_extractDouble(std::string const & input)
{
	char *end;
	double nb;
	size_t	pos;

	pos = input.find('.');
	if (pos == std::string::npos)
		return (false);
	nb = std::strtod(input.c_str(), &end);
	if (end == input.c_str() || *end != '\0')
		return (false);
	this->_asDouble = nb;
	return (true);
}

bool	Converter::_extractChar(std::string const & input)
{
	if (input.length() == 1)
	{
		this->_asChar = input[0];
		if (!std::isprint(input[0]))
			_errorFlags += CHAR_UNPRINTABLE;
		return (true);
	}
	return (false);
}

bool	Converter::_extractNonNumeric(std::string const & input)
{
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
	{
		_errorFlags += INT_OVERFLOW;
		_errorFlags += CHAR_OVERFLOW;
		_asFloat = std::numeric_limits<float>::infinity();
		_asDouble = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "-inf" || input == "-inff")
	{
		_errorFlags += INT_OVERFLOW;
		_errorFlags += CHAR_OVERFLOW;
		_asFloat = (-1) * std::numeric_limits<float>::infinity();
		_asDouble = (-1) * std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "nan" || input == "nanf")
	{
		_errorFlags += INT_OVERFLOW;
		_errorFlags += CHAR_OVERFLOW;
		_asFloat = std::numeric_limits<float>::quiet_NaN();
		_asDouble = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	return (false);
}

void	Converter::_castScalarsFromInt(void)
{
	_setConversionErrorFlags();
	this->_asFloat = static_cast<float>(this->_asInt);
	this->_asDouble = static_cast<double>(this->_asInt);
	this->_asChar = static_cast<char>(this->_asInt);
	if (!std::isprint(this->_asChar))
		_errorFlags += CHAR_UNPRINTABLE;
}

void	Converter::_castScalarsFromFloat(void)
{
	_setConversionErrorFlags();
	this->_asInt = static_cast<int>(this->_asFloat);
	this->_asDouble = static_cast<double>(this->_asFloat);
	this->_asChar = static_cast<char>(this->_asFloat);
	if (!std::isprint(this->_asChar))
		_errorFlags += CHAR_UNPRINTABLE;
}

void	Converter::_castScalarsFromDouble(void)
{
	_setConversionErrorFlags();
	this->_asInt = static_cast<int>(this->_asDouble);
	this->_asFloat = static_cast<float>(this->_asDouble);
	this->_asChar = static_cast<char>(this->_asDouble);
	if (!std::isprint(this->_asChar))
		_errorFlags += CHAR_UNPRINTABLE;
}

void	Converter::_castScalarsFromChar(void)
{
	_setConversionErrorFlags();
	this->_asInt = static_cast<int>(this->_asChar);
	this->_asFloat = static_cast<float>(this->_asChar);
	this->_asDouble = static_cast<double>(this->_asChar);
}

void	Converter::_setConversionErrorFlags(void)
{
	switch (_type)
	{
		case INTEGER:
			if (this->_asInt > charMax || this->_asInt < charMin)
				this->_errorFlags += CHAR_OVERFLOW;
			break ;
		case FLOAT:
			if (this->_asFloat > charMax || this->_asFloat < charMin)
				this->_errorFlags += CHAR_OVERFLOW;
			if (this->_asFloat > intMax || this->_asFloat < intMin)
				this->_errorFlags += INT_OVERFLOW;
			break ;
		case DOUBLE:
			if (this->_asDouble > charMax || this->_asDouble < charMin)
				this->_errorFlags += CHAR_OVERFLOW;
			if (this->_asDouble > intMax || this->_asDouble < intMin)
				this->_errorFlags += INT_OVERFLOW;
			break ;
		default:
			return ;
	}
}

bool	Converter::isCharConversionOk(void) const
{
	if (this->_errorFlags & CHAR_OVERFLOW
		|| this->_errorFlags & CHAR_UNPRINTABLE)
		return (false);
	return (true);
}

bool	Converter::isIntConversionOk(void) const
{
	if (this->_errorFlags & INT_OVERFLOW
		|| this->_errorFlags & INT_OVERFLOW)
		return (false);
	return (true);
}

std::string	Converter::getCharConversionMessage(void) const
{
	if (this->_errorFlags & CHAR_OVERFLOW)
		return ("impossible");
	if (this->_errorFlags & CHAR_UNPRINTABLE)
		return ("not displayable");
	return ("unknown error");
}

std::string	Converter::getIntConversionMessage(void) const
{
	if (this->_errorFlags & INT_OVERFLOW)
		return ("impossible");
	return ("unknown error");
}

const char *	Converter::NotALiteralException::what(void) const throw()
{
	return ("Input is not a literal scalar type (char, int, float or double).");
}

std::ostream &	operator<<(std::ostream &os, Converter const &converter)
{
	os << "- as char\t: ";
	if (converter.isCharConversionOk() == true)
		os << "\'" << converter.getAsChar() << "\'";
	else
		os << converter.getCharConversionMessage();
	os << "\n- as int\t: ";
	if (converter.isIntConversionOk() == true)
		os << converter.getAsInt();
	else
		os << converter.getIntConversionMessage();
	os << "\n- as float\t: ";
		if (converter.getAsFloat() == static_cast<int>(converter.getAsFloat()))
			os << std::fixed << std::setprecision(1) << converter.getAsFloat() << "f";
		else
			os << converter.getAsFloat() << "f";
	os << "\n- as double\t: "
		<< converter.getAsDouble();
	return (os);
}