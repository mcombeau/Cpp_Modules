#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <vector>

int * getArrayToSort( int ac, char **av );
int getNumber( char * nbStr, int * array );
bool isADuplicate( int * array, int nb );
void verifySortAccuracy(int * array, PmergeMe & vectorSorter);
std::vector<int> & convertArrayToVector(int * array);
template <typename T>
void printVector( std::vector<T> & vector, std::string name,
                             std::string color );
std::string getVectorContentsAsString( std::vector<int> & vector );
std::string getVectorContentsAsString( std::vector< std::pair<int, int> > & vector );

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
		PmergeMe vectorSorter( array, VECTOR );
		vectorSorter.sort();
		verifySortAccuracy(array, vectorSorter);
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

void verifySortAccuracy(int * array, PmergeMe & vectorSorter)
{
	std::vector<int> control = convertArrayToVector(array);
	std::vector<int> & sortedVector = vectorSorter.getSortedVector();

	std::sort(control.begin(), control.end());
	if (control.size() != sortedVector.size())
	{
		std::cout << RED BOLD "KO: incorrectly sorted vector !" RESET << std::endl;
		return ;
	}
	for (size_t i = 0; i < control.size(); i++)
	{
		if (sortedVector[i] != control[i])
		{
			std::cout << RED BOLD "KO: incorrectly sorted vector !" RESET << std::endl;
			return ;
		}
	}
	std::cout << GREEN BOLD "OK: vector properly sorted." RESET << std::endl;
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

std::vector<int> & convertArrayToVector(int * array)
{
	std::vector<int> * vector = new std::vector<int>();
	for (int i = 0; array[i]; i++)
	{
		vector->push_back(array[i]);
	}
	return (*vector);
}

template <typename T>
void printVector( std::vector<T> & vector, std::string name,
                             std::string color )
{
	std::cout << color << name
	          << " vector (size " << vector.size() << ") contains:\t"
	          << getVectorContentsAsString( vector ) << RESET << std::endl;
}

std::string getVectorContentsAsString( std::vector<int> & vector )
{
	std::stringstream ss;
	if ( vector.empty() )
	{
		return ( "" );
	}
	std::vector<int>::iterator it = vector.begin();
	for ( ; it != vector.end(); it++ )
	{
		ss << "[" << *it << "]";
	}
	return ( ss.str() );
}

std::string getVectorContentsAsString(
    std::vector< std::pair<int, int> > & vector )
{
	std::stringstream ss;
	if ( vector.empty() )
	{
		return ( "" );
	}
	std::vector< std::pair<int, int> >::iterator it = vector.begin();
	for ( ; it != vector.end(); it++ )
	{
		std::cout << "[" << it->first << "--"  << it->second << "]";
	}
	return ( ss.str() );
}
