#include "PmergeMe.hpp"
#include <cstdlib>
#include <exception>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>

int * getArrayToSort( int ac, char **av );
int getNumber( char * nbStr, int * array );
bool isADuplicate( int * array, int nb );

int	main( int ac, char **av )
{
	if ( ac < 2 )
	{
		std::cerr << RED "Usage: ./PmergeMe [integers to sort]" RESET << std::endl;
		return ( 1 );
	}
	int * array = NULL;
	try
	{
		int * array = getArrayToSort( ac, av );
		PmergeMe vectorMerger( array, VECTOR );
		vectorMerger.sort();
		delete [] array;
	}
	catch ( std::exception & e )
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		if ( array )
		{
			delete [] array;
		}
	}
	return ( 0 );
}

int * getArrayToSort( int ac, char **av )
{
	int * array = new int[ac];
	int i = 0;
	while ( av[i + 1] )
	{
		int nb = getNumber( av[i + 1], array );
		array[i] = nb;
		/* std::cout << CYAN "array[" << i << "] = " << array[i] << RESET << std::endl; */
		i++;
	}
	return ( array );
}

int getNumber( char * nbStr, int * array )
{
	long nb = atol( nbStr );
	std::stringstream intMax;
	intMax << std::numeric_limits<int>::max();
	if ( nb < 1 || nb > std::numeric_limits<int>::max() )
	{
		throw ( std::out_of_range( std::string( nbStr ) +
		                           ": must be a positive integer between 1 and " + intMax.str() ) );
	}
	if ( isADuplicate( array, nb ) )
	{
		throw ( std::out_of_range( std::string( nbStr ) + ": duplicate number" ) );
	}
	return ( nb );
}

bool isADuplicate( int * array, int nb )
{
	for ( int i = 0; array[i]; i++ )
	{
		if ( array[i] == nb )
		{
			return ( true );
		}
	}
	return ( false );
}
