#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <ctime>
#include <map>
#include <string>
#include <strings.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <limits>

class BitcoinExchange
{
	private:
		std::map<time_t, double>_exchangeRate;

		void _fillExchangeRateTable( void );
		void _fillExchangeRateEntry( std::string line );
		void _addExchangeRateEntry( time_t date, double value );
		time_t _getEpochFromDate( std::string date );
		std::string _getDateFromEpoch( time_t epochDate );
		int _getYearFromString( std::string dateStr );
		int _getMonthFromString( std::string dateStr );
		int _getDayFromString( std::string dateStr );
		double _getValueFromString( std::string valueStr );

	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange & src );
		~BitcoinExchange( void );

		BitcoinExchange & operator=( BitcoinExchange & src );

		int getExchangeValueOnDate( std::string date, int value );
		int getExchangeRateOnDate( std::string date );

};

template<typename T>
std::string error_message( T arg, std::string const message )
{
	std::stringstream ss;
	ss << "Error: " << arg << ": " << message;
	return ( ss.str() );
}

#endif
