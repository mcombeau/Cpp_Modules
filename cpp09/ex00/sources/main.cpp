#include "BitcoinExchange.hpp"

void checkArgs( int ac, char **av );
std::fstream * openFileStream( char * filename );
void evaluateInput( BitcoinExchange & btc, std::fstream & fs );
bool shouldLineBeEvaluated( char * line );

int	main( int ac, char **av )
{
	BitcoinExchange * btc = NULL;
	std::fstream * fs = NULL;
	try
	{
		checkArgs( ac, av );
		fs = openFileStream( av[1] );
		( void )fs;
		btc = new BitcoinExchange();
		evaluateInput( *btc, *fs );
	}
	catch ( std::exception &e )
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		return ( 1 );
	}
	delete btc;
	delete fs;
	return ( 0 );
}

void checkArgs( int ac, char **av )
{
	( void )av;
	if ( ac != 2 )
	{
		throw ( std::runtime_error( "Usage: ./btc [file].txt" ) );
	}
}

std::fstream * openFileStream( char * filename )
{
	std::fstream * fs = new std::fstream();
	fs->open( filename, std::fstream::in );
	if ( fs->fail() )
	{
		/* TODO: what if it's a directory and not a file? */
		throw ( std::runtime_error( "Could not open file \"" + std::string(
		                                filename ) + "\"" ) );
	}
	return ( fs );
}

void evaluateInput( BitcoinExchange & btc, std::fstream & fs )
{
	while ( !fs.eof() )
	{
		char line[100];
		fs.getline( line, 100 );
		if ( fs.eof() || shouldLineBeEvaluated( line ) == false )
		{
			continue;
		}
		if ( VERBOSE )
		{
			std::cout << std::endl << CYAN "Input: " << line << RESET << std::endl;
		}
		std::string * split = NULL;
		try
		{
			split = splitString( line, "|" );
			btc.outputExchangeValueOnDate( split[DATE], split[VALUE] );
		}
		catch ( std::exception & e )
		{
			std::cerr << "Error: " << e.what() << " (line: " << line << ")" << std::endl;
		}
		delete [] ( split );
	}
}

bool shouldLineBeEvaluated( char * line )
{
	std::string lineStr( line );
	if ( lineStr.empty() || lineStr == "date | value" )
	{
		return ( false );
	}
	return ( true );
}

std::string * splitString( std::string string, std::string sep )
{
	std::string * split = new std::string[2];
	size_t delim = string.find( sep, 0 );
	if ( delim == std::string::npos )
	{
		delete [] ( split );
		throw ( std::out_of_range( string + ": invalid input" ) );
	}
	split[DATE] = string.substr( 0, delim );
	split[VALUE] = string.substr( delim + sep.length(), std::string::npos );
	return ( split );
}

