#include "BitcoinExchange.hpp"

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

void BitcoinExchange::outputExchangeValueOnDate( std::string & dateStr,
        std::string & valueStr )
{
	_checkInputStrings( dateStr, valueStr );
	time_t date = _getEpochFromDateString( dateStr );
	double value = _getValueFromString( valueStr );
	time_t closestEpoch = _getClosestDateInTable( date );
	std::string closestDate = _getDateFromEpoch( closestEpoch );
	double exchangeRate = _getExchangeRateOnDate( date );
	double exchangeValue = getExchangeValueOnDate( dateStr, valueStr );

	if ( VERBOSE )
	{
		std::cout << YELLOW << "Closest exchange data: " << closestDate << " -> ";
		std::cout << std::fixed;
		std::cout.precision( 2 );
		std::cout << _exchangeRate[closestEpoch] << RESET << std::endl;
	}
	std::cout << "[" << _getDateFromEpoch( date ) << "] " << value << " * ";
	std::cout << std::fixed;
	std::cout.precision( 2 );
	std::cout << exchangeRate << " = " << exchangeValue << std::endl;
}

double BitcoinExchange::getExchangeValueOnDate( std::string & dateStr,
        std::string & valueStr )
{
	_checkInputStrings( dateStr, valueStr );
	double rate = _getExchangeRateOnDate( _getEpochFromDateString( dateStr ) );
	double value = _getValueFromString( valueStr );
	return ( value * rate );
}

double BitcoinExchange::_getExchangeRateOnDate( time_t date )
{
	time_t closestDate = _getClosestDateInTable( date );
	return ( _exchangeRate[closestDate] );
}

time_t BitcoinExchange::_getClosestDateInTable( time_t date )
{
	std::map<time_t, double>::iterator it = _exchangeRate.find( date );
	if ( date < _exchangeRate.begin()->first )
	{
		return ( _exchangeRate.begin()->first );
	}
	for ( int i = 0; it == _exchangeRate.end(); i++ )
	{
		time_t newDate = date - i * 24 * 60 * 60;
		it = _exchangeRate.find( newDate );
	}
	return ( it->first );
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
	std::string * split = splitString( line, "," );
	_checkDateString( split[DATE] );
	_checkValueString( split[VALUE] );

	time_t date = _getEpochFromDateString( split[DATE] );
	double value = _getValueFromString( split[VALUE] );

	_addExchangeRateEntry( date, value );
	delete [] ( split );
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

time_t BitcoinExchange::_getEpochFromDateString( std::string & dateStr )
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

int BitcoinExchange::_getYearFromString( std::string & dateStr )
{
	size_t lenYear = dateStr.find( "-", 0 );
	std::string yearStr = dateStr.substr( 0, lenYear );
	int year = std::atoi( yearStr.c_str() );
	if ( yearStr.empty() || year < 0 || year > 2050 )
	{
		throw std::out_of_range( dateStr + ": invalid date" );
	}
	return ( year );
}

int BitcoinExchange::_getMonthFromString( std::string & dateStr )
{
	size_t lenYear = dateStr.find( "-", 0 ) + 1;
	size_t lenMon = dateStr.find( "-", lenYear ) - lenYear;
	std::string monthStr = dateStr.substr( lenYear, lenMon );
	int month = std::atoi( monthStr.c_str() );
	if ( monthStr.empty() || month < 1 || month > 12 )
	{
		throw std::out_of_range( dateStr + ": invalid date" );
	}
	return ( month );
}

int BitcoinExchange::_getDayFromString( std::string & dateStr )
{
	size_t lenYear = dateStr.find( "-", 0 ) + 1;
	size_t lenMon = dateStr.find( "-", lenYear ) + 1;
	size_t lenDay = dateStr.length() - lenMon;
	std::string dayStr = dateStr.substr( lenMon, lenDay );
	try
	{
		_checkDayString( dayStr );
	}
	catch ( std::exception & e )
	{
		throw std::out_of_range( dateStr + ": invalid date" );
	}
	int day = std::atoi( dayStr.c_str() );
	if ( dayStr.empty() || day < 1 || day > 31 )
	{
		throw std::out_of_range( dateStr + ": invalid date" );
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

double BitcoinExchange::_getValueFromString( std::string & valueStr )
{
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

void BitcoinExchange::_checkInputStrings( std::string & dateStr,
        std::string valueStr )
{
	_checkDateString( dateStr );
	_checkValueString( valueStr );
}

void BitcoinExchange::_checkValueString( std::string & string )
{
	std::string required = "0123456789";
	size_t pos = string.find_first_of( required, 0 );
	if ( string.empty() || pos == std::string::npos )
	{
		throw ( std::runtime_error( "no value provided" ) );
	}
	std::string::iterator it = string.begin();
	for ( ; it != string.end(); it++ )
	{
		if ( std::isalpha( *it ) || !std::isprint( *it ) )
		{
			throw ( std::runtime_error( "invalid value" ) );
		}
	}
}

void BitcoinExchange::_checkDateString( std::string & string )
{
	std::string required = "0123456789-";
	size_t pos = string.find_first_of( required, 0 );
	if ( string.empty() || pos == std::string::npos )
	{
		throw ( std::runtime_error( "no date provided" ) );
	}
	std::string::iterator it = string.begin();
	for ( ; it != string.end(); it++ )
	{
		if ( std::isalpha( *it ) || !std::isprint( *it ) )
		{
			throw ( std::runtime_error( "invalid date" ) );
		}
	}
}

void BitcoinExchange::_checkDayString( std::string & string )
{
	std::string::iterator it = string.begin();
	for ( ; it != string.end(); it++ )
	{
		if ( std::isdigit( *it ) == false && isblank( *it ) == false )
		{
			throw std::out_of_range( "invalid date" );
		}
	}
}
