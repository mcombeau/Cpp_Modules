#include <exception>
#include <ios>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"
#include "Colors.h"

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "Usage: ./btc [file].txt" << std::endl;
		return ( 0 );
	}
	std::fstream fs;
	fs.open( av[1], std::fstream::in );
	if ( fs.fail() )
	{
		std::cerr << "Error : Could not open file \"" << av[1] << "\"" << std::endl;
	}
	BitcoinExchange * btc = new BitcoinExchange();

	delete btc;

	return ( 0 );
}
