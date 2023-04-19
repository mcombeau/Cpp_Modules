#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <strings.h>
#include <utility>

BitcoinExchange::BitcoinExchange( void )
{
	_fillExchangeRateTable();
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
		throw ( std::runtime_error( "Error: Could not open data file" ) );
	}
	char line[100];
	fs.getline( line, 100 );
	while ( !fs.eof() )
	{
		char line[100];
		fs.getline( line, 100 );
		if ( !fs.eof() && line[0] != '\0' )
		{
			_addExchangeRateEntry( std::string( line ) );
		}
	}

}

void BitcoinExchange::_addExchangeRateEntry( std::string line )
{
	size_t lenToDelim = line.find( ",", 0 );
	std::string dateStr = line.substr( 0, lenToDelim );
	std::string valueStr = line.substr( lenToDelim + 1, std::string::npos );
	float value = std::strtof( valueStr.c_str(), NULL );
	std::cout << "Date: [" << dateStr << "], value: [" << valueStr << "][";
	std::cout << std::fixed;
	std::cout.precision( 2 );
	std::cout << value << "]" << std::endl;
	time_t date = _convertDate( dateStr );
	( void )date;
	/* _exchangeRate.insert( std::pair<time_t, double>( date, value ) ); */

}

time_t BitcoinExchange::_convertDate( std::string dateStr )
{
	struct tm tm;
	bzero( &tm, sizeof( tm ) );
	size_t lenYear = dateStr.find( "-", 0 );
	std::string year = dateStr.substr( 0, lenYear );
	tm.tm_year = std::atoi( year.c_str() );

	size_t lenMon = dateStr.find( "-", lenYear + 1 );
	std::string month = dateStr.substr( lenYear + 1, lenMon );
	tm.tm_mon = std::atoi( month.c_str() );

	size_t lenDay = dateStr.find( "\0", lenMon + 1 );
	std::string day = dateStr.substr( lenMon + 1, lenDay );
	tm.tm_mday = std::atoi( day.c_str() );

	time_t date = mktime( &tm );
	std::cout << "Date: " << dateStr << " is year [" << tm.tm_year << "] month [" <<
	          tm.tm_mon << "] day [" << tm.tm_mday << "]" << " which is " << date <<
	          std::endl;

	return ( date );
}
