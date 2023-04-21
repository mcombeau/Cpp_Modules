#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

# define VERBOSE 1

# define DATE 0
# define VALUE 1

#include "Colors.h"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <strings.h>
#include <sys/stat.h>

class BitcoinExchange
{
	private:
		std::map<time_t, double>_exchangeRate;

		void _fillExchangeRateTable( void );
		void _fillExchangeRateEntry( std::string line );
		void _addExchangeRateEntry( time_t date, double value );
		time_t _getEpochFromDateString( std::string & date );
		std::string _getDateFromEpoch( time_t epochDate );
		int _getYearFromString( std::string & dateStr );
		int _getMonthFromString( std::string & dateStr );
		int _getDayFromString( std::string & dateStr );
		double _getValueFromString( std::string & valueStr );
		time_t _getClosestDateInTable( time_t date );
		double _getExchangeRateOnDate( time_t date );
		void _checkInputStrings( std::string & dateStr, std::string valueStr );
		void _checkValueString( std::string & string );
		void _checkDateString( std::string & string );
		void _checkDayString( std::string & string );

	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange & src );
		~BitcoinExchange( void );

		BitcoinExchange & operator=( BitcoinExchange & src );

		void outputExchangeValueOnDate( std::string & date, std::string & value );
		double getExchangeValueOnDate( std::string & date, std::string & value );

};

std::string * splitString( std::string string, std::string sep );

#endif
