#include <exception>
#include <ios>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"
#include "Colors.h"
#include <sstream>

void checkArgs( int ac, char **av );
std::fstream & openFileStream( char * filename );
void evaluateInput( BitcoinExchange & btc, std::fstream & fs );

int	main( int ac, char **av )
{
	checkArgs( ac, av );
	std::fstream & fs = openFileStream( av[1] );
	( void )fs;
	BitcoinExchange * btc = NULL;
	try
	{
		btc = new BitcoinExchange();
		evaluateInput( *btc, fs );
	}
	catch ( std::exception &e )
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return ( 1 );
	}

	delete btc;
	delete &fs;
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

std::fstream & openFileStream( char * filename )
{
	std::cout << CYAN "Opening filestream" RESET << std::endl;
	std::fstream * fs = new std::fstream();
	fs->open( filename, std::fstream::in );
	if ( fs->fail() )
	{
		/* TODO: what if it's a directory and not a file? */
		std::cerr << RED "Error : Could not open file \"" << filename << "\"" RESET <<
		          std::endl;
	}
	return ( *fs );
}

void evaluateInput( BitcoinExchange & btc, std::fstream & fs )
{
	char line[100];
	fs.getline( line, 100 );
	while ( !fs.eof() )
	{
		char line[100];
		fs.getline( line, 100 );
		/* if ( !fs.eof() && line[0] != '\0' ) */
		/* { */
		/* 	size_t delim = line.find( "|", 0 ); */
		/* 	if ( delim == std::string::npos ) */
		/* 	{ */
		/* 		throw ( std::out_of_range( line + ": invalid input" ) ); */
		/* 	} */
		/* 	std::string dateStr = line.substr( 0, delim ); */
		/* 	std::string valueStr = line.substr( delim + 1, std::string::npos ); */
		/* 	std::string dateStr = line.substr( */
		/* 	btc.calculateValue( std::string( line ) ); */
	}
	( void )btc;
}

