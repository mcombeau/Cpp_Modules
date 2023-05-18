/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:16:22 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/18 15:16:22 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int * getArrayToSort( int ac, char **av );
int getNumber( char * nbStr, int * array );
bool isADuplicate( int * array, int nb );
template <typename T>
void verifySortAccuracy( int * array, T & resultContainer );
std::vector<int> & convertArrayToVector(int * array);
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

		std::cout << CYAN "---- Insertion-merge sort with std::vector" RESET << std::endl;
		PmergeMe vectorSorter( array, VECTOR );
		std::clock_t start = std::clock();
		vectorSorter.sort();
		std::clock_t vectorTime = std::clock() - start;
		verifySortAccuracy(array, vectorSorter.getSortedVector());

		std::cout << std::endl << CYAN "---- Insertion-merge sort with std::list" RESET << std::endl;
		PmergeMe listSorter( array, LIST );
		start = std::clock();
		listSorter.sort();
		std::clock_t listTime = std::clock() - start;
		verifySortAccuracy(array, listSorter.getSortedList());

		std::cout << std::endl << CYAN "---- Timing" RESET << std::endl;
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
	std::cout << timeInMs << " ms)" << std::endl;
}

template <typename T>
void verifySortAccuracy( int * array, T & resultContainer )
{
	std::vector<int> control = convertArrayToVector(array);

	printContainer(control, "Before Sort", RESET);
	std::sort(control.begin(), control.end());

	std::vector<int>::iterator controlit = control.begin();
	typename T::iterator resultit = resultContainer.begin();
	for ( ; resultit != resultContainer.end() && controlit != control.end(); controlit++)
	{
		if ( *resultit != *controlit )
		{
			printContainer( resultContainer, "After Sort", RED );
			printContainer(control, "Expected", CYAN);
			std::cout << std::endl << RED BOLD ">>> KO: incorrectly sorted !" RESET << std::endl;
			return ;
		}
		resultit++;
	}
		printContainer( resultContainer, "After Sort", GREEN );
		std::cout << std::endl << GREEN BOLD ">>> OK: properly sorted." RESET << std::endl;
}

int * getArrayToSort( int ac, char **av )
{
	int * array = new int[ac];
	int i = 0;
	while ( av[i + 1] )
	{
		int nb = getNumber( av[i + 1], array );
		array[i] = nb;
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
	std::cout << color << std::setw( 35 ) << std::left << key
		<< value << RESET << std::endl;
}

std::string getContentsAsString( std::vector<int> & vector )
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

std::string getContentsAsString( std::vector< std::pair<int, int> > & vector )
{
	std::stringstream ss;
	if ( vector.empty() )
	{
		return ( "" );
	}
	std::vector< std::pair<int, int> >::iterator it = vector.begin();
	for ( ; it != vector.end(); it++ )
	{
		ss << "[" << it->first << "--"  << it->second << "]";
	}
	return ( ss.str() );
}

std::string getContentsAsString( std::list<int> & list )
{
	std::stringstream ss;
	if ( list.empty() )
	{
		return ( "" );
	}
	std::list<int>::iterator it = list.begin();
	for ( ; it != list.end(); it++ )
	{
		ss << "[" << *it << "]";
	}
	return ( ss.str() );
}

std::string getContentsAsString( std::list< std::pair<int, int> > & list )
{
	std::stringstream ss;
	if ( list.empty() )
	{
		return ( "" );
	}
	std::list< std::pair<int, int> >::iterator it = list.begin();
	for ( ; it != list.end(); it++ )
	{
		ss << "[" << it->first << "--"  << it->second << "]";
	}
	return ( ss.str() );
}
