#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <strings.h>
#include <utility>
#include <time.h>
#include "Colors.h"

BitcoinExchange::BitcoinExchange( void )
{
	try
	{
		_fillExchangeRateTable();
	}
	catch ( std::exception &e )
	{
		std::string error = e.what();
		throw ( std::runtime_error( "Invalid exchange rate data: " + error ) );
	}
}

BitcoinExchange::BitcoinExchange( BitcoinExchange & src )
{
	( void )src;
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange & src )
{
	( void )src;
	return ( *this );
}


void BitcoinExchange::_fillExchangeRateTable( void )
{
	std::fstream fs;
	fs.open( "data/data.csv", std::fstream::in );
	if ( fs.fail() )
	{
		throw ( std::runtime_error( "Could not open data file" ) );
	}
	char line[100];
	fs.getline( line, 100 );
	while ( !fs.eof() )
	{
		char line[100];
		fs.getline( line, 100 );
		if ( !fs.eof() && line[0] != '\0' )
		{
			_fillExchangeRateEntry( std::string( line ) );
		}
	}
}

void BitcoinExchange::_fillExchangeRateEntry( std::string line )
{
	/* std::cout << "Line: " << line << std::endl; */

	size_t delim = line.find( ",", 0 );
	if ( delim == std::string::npos )
	{
		throw ( std::out_of_range( line + ": invalid input" ) );
	}
	std::string dateStr = line.substr( 0, delim );
	std::string valueStr = line.substr( delim + 1, std::string::npos );
	/* std::cout << PURPLE << "Str: [" << dateStr << "] [" << valueStr << "]" << RESET */
	/*           << std::endl; */

	time_t date = _getEpochFromDate( dateStr );
	double value = _getValueFromString( valueStr );

	/* std::cout << YELLOW << "Val: [" << _getDateFromEpoch( date ) << "] ["; */
	/* std::cout << std::fixed; */
	/* std::cout.precision( 2 ); */
	/* std::cout << value << "]" << RESET << std::endl; */

	_addExchangeRateEntry( date, value );

	/* std::map<time_t, double>::iterator it = _exchangeRate.find( date ); */
	/* std::cout << BRIGHT_YELLOW << "Map: [" << it->first << "] ["; */
	/* std::cout << std::fixed; */
	/* std::cout.precision( 2 ); */
	/* std::cout << it->second << "]" << RESET << std::endl << std::endl; */
	/* std::cout << BRIGHT_YELLOW << "Map: [" << _getDateFromEpoch( */
	/*               it->first ) << "] ["; */
	/* std::cout << std::fixed; */
	/* std::cout.precision( 2 ); */
	/* std::cout << it->second << "]" << RESET << std::endl << std::endl; */
}

void BitcoinExchange::_addExchangeRateEntry( time_t date, double value )
{
	std::map<time_t, double>::iterator it = _exchangeRate.find( date );
	if ( it != _exchangeRate.end() )
	{
		it->second = value;
	}
	else
	{
		_exchangeRate.insert( std::pair<time_t, double>( date, value ) );
	}
}

time_t BitcoinExchange::_getEpochFromDate( std::string dateStr )
{
	if ( dateStr.empty() )
	{
		throw ( std::runtime_error( "no date provided" ) );
	}
	struct tm tm;
	bzero( &tm, sizeof( tm ) );
	tm.tm_year = _getYearFromString( dateStr ) - 1900;
	tm.tm_mon = _getMonthFromString( dateStr ) - 1;
	tm.tm_mday = _getDayFromString( dateStr );

	time_t date = mktime( &tm );
	return ( date );
}

int BitcoinExchange::_getYearFromString( std::string dateStr )
{
	size_t lenYear = dateStr.find( "-", 0 );
	std::string yearStr = dateStr.substr( 0, lenYear );
	int year = std::atoi( yearStr.c_str() );
	if ( year < 0 || year > 2050 )
	{
		throw std::out_of_range( dateStr + ": invalid year" );
	}
	return ( year );
}

int BitcoinExchange::_getMonthFromString( std::string dateStr )
{
	size_t lenYear = dateStr.find( "-", 0 ) + 1;
	size_t lenMon = dateStr.find( "-", lenYear ) - lenYear;
	std::string monthStr = dateStr.substr( lenYear, lenMon );
	int month = std::atoi( monthStr.c_str() );
	if ( month < 1 || month > 12 )
	{
		throw std::out_of_range( dateStr + ": invalid month" );
	}
	return ( month );
}

int BitcoinExchange::_getDayFromString( std::string dateStr )
{
	size_t lenYear = dateStr.find( "-", 0 ) + 1;
	size_t lenMon = dateStr.find( "-", lenYear ) + 1;
	size_t lenDay = dateStr.length() - lenMon;
	std::string dayStr = dateStr.substr( lenMon, lenDay );
	int day = std::atoi( dayStr.c_str() );
	if ( day < 1 || day > 31 )
	{
		throw std::out_of_range( dateStr + ": invalid day" );
	}
	return ( day );
}

std::string BitcoinExchange::_getDateFromEpoch( time_t epochDate )
{
	struct tm * date = localtime( &epochDate );
	std::stringstream ss;

	ss << std::setfill( '0' ) << std::setw( 4 ) << date->tm_year + 1900;
	ss << "-" << std::setfill( '0' ) << std::setw( 2 ) << date->tm_mon + 1;
	ss << "-" << std::setfill( '0' ) << std::setw( 2 ) << date->tm_mday;
	return ( ss.str() );
}

double BitcoinExchange::_getValueFromString( std::string valueStr )
{
	if ( valueStr.empty() )
	{
		throw ( std::runtime_error( "no value provided" ) );
	}
	double value = std::strtod( valueStr.c_str(), NULL );
	if ( value < 0 )
	{
		throw ( std::out_of_range( valueStr + ": not a positive value" ) );
	}
	else if ( value > std::numeric_limits<int>::max() )
	{
		throw ( std::out_of_range( valueStr + ": value too large" ) );
	}
	return ( value );
}
