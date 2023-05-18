#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <ctime>

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
void printTime(std::string containerType, std::clock_t time, int elements);

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

		std::cout << std::endl << CYAN "INSERTION-MERGE SORT WITH VECTORS" RESET << std::endl;
		PmergeMe vectorSorter( array, VECTOR );
		std::clock_t start = std::clock();
		vectorSorter.sort();
		std::clock_t vectorTime = std::clock() - start;
		verifySortAccuracy(array, vectorSorter);

		std::cout << std::endl << CYAN "INSERTION-MERGE SORT WITH LISTS" RESET << std::endl;
		PmergeMe listSorter( array, LIST );
		start = std::clock();
		listSorter.sort();
		std::clock_t listTime = std::clock() - start;

		printTime("vector", vectorTime, ac - 1);
		printTime("list", listTime, ac - 1);

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

void printTime(std::string containerType, std::clock_t time, int elements)
{
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	double timeInMs = time / clock_per_ms;

	std::cout << "Time to process a range of " << elements << " elements with std::"
		<< containerType << ": " << time << " clock ticks (";
	std::cout << std::fixed;
	std::cout.precision( 6 );
	/* std::cout << timeInSecs << " s, "; */
	std::cout << timeInMs << " ms)" << std::endl;
}

void verifySortAccuracy(int * array, PmergeMe & vectorSorter)
{
	std::vector<int> control = convertArrayToVector(array);
	std::vector<int> & sortedVector = vectorSorter.getSortedVector();

	printVector(control, "Before Sort", RESET);
	std::sort(control.begin(), control.end());
	std::cout << "After Sort vector (size " << sortedVector.size() << ") contains:\t";
	bool error = false;
	for (size_t i = 0, j = 0; i < sortedVector.size() && j < control.size(); j++)
	{
		if (sortedVector[i] != control[j])
		{
			std::cout << RED "[" << control[j] << "]" RESET;
			error = true;
			continue ;
		}
		else {
			std::cout << GREEN "[" << sortedVector[i] << "]" RESET;
			i++;
		}
	}
	if (error)
	{
		std::cout << std::endl << RED BOLD "KO: incorrectly sorted vector !" RESET << std::endl;
	}
	else {
		std::cout << std::endl << GREEN BOLD "OK: vector properly sorted." RESET << std::endl;
	}
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

void printLine( std::string color, std::string key, std::string value)
{
	std::cout << color << std::setw( 40 ) << std::left << key
		<< value << RESET << std::endl;
}

template <typename T>
void printVector( std::vector<T> & vector, std::string name,
                             std::string color )
{
	std::stringstream ss;
	ss << name << " vector (size " << vector.size() << ") contains: ";
	printLine( color, ss.str(), getVectorContentsAsString( vector ) );
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
