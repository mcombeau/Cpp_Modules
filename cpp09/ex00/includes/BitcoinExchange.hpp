#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <ctime>
#include <map>
#include <string>
#include <strings.h>
#include <cstring>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<time_t, double>_exchangeRate;

		void _fillExchangeRateTable( void );
		void _addExchangeRateEntry( std::string line );
		time_t _convertDate( std::string date );

	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange & src );
		~BitcoinExchange( void );

		BitcoinExchange & operator=( BitcoinExchange & src );

		int getExchangeValueOnDate( std::string date, int value );
		int getExchangeRateOnDate( std::string date );

};
#endif
