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
#include "utils.hpp"
#include <cstring>

int	main( int ac, char **av )
{
	if ( ac < 2 )
	{
		std::cerr << RED "Usage: ./PmergeMe [integers to sort]" RESET << std::endl;
		return ( 1 );
	}
	try
	{
		testPmergeMe( ac, av );
	}
	catch ( std::exception & e )
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		return ( 1 );
	}
	return ( 0 );
}

void testPmergeMe( int ac, char **av )
{
	int array_size = ac - 1;
	int * array = getArrayToSort( array_size, av );
	
	std::clock_t vectorTime = test_vector( array, array_size );
	std::clock_t listTime = test_list( array, array_size );
	
	std::cout << std::endl << CYAN "---- Timing" RESET << std::endl;
	printTime("vector", vectorTime, ac - 1);
	printTime("list", listTime, ac - 1);

	delete [] array;
}

std::clock_t test_vector( int * array, int array_size)
{
	std::cout << CYAN "---- Insertion-merge sort with std::vector" RESET << std::endl;
	PmergeMe vectorSorter( array, array_size, VECTOR );
	std::clock_t start = std::clock();
	vectorSorter.sort();
	std::clock_t vectorTime = std::clock() - start;
	verifySortAccuracy( array, array_size, vectorSorter.getSortedVector() );
	return ( vectorTime );
}

std::clock_t test_list( int * array, int array_size )
{
	std::cout << std::endl << CYAN "---- Insertion-merge sort with std::list" RESET << std::endl;
	PmergeMe listSorter( array, array_size, LIST );
	std::clock_t start = std::clock();
	listSorter.sort();
	std::clock_t listTime = std::clock() - start;
	verifySortAccuracy( array, array_size, listSorter.getSortedList() );
	return ( listTime );
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
void verifySortAccuracy( int * array, int array_size, T & resultContainer )
{
	std::vector<int> * control = convertArrayToVector( array, array_size );

	printContainer( *control, "Before Sort", RESET );
	std::sort(control->begin(), control->end());

	std::vector<int>::iterator controlit = control->begin();
	typename T::iterator resultit = resultContainer.begin();
	for ( ; resultit != resultContainer.end() && controlit != control->end(); controlit++)
	{
		if ( *resultit != *controlit )
		{
			printContainer( resultContainer, "After Sort", RED );
			printContainer( *control, "Expected", CYAN );
			std::cout << std::endl << RED BOLD ">>> KO: incorrectly sorted !" RESET << std::endl;
			delete control;
			return ;
		}
		resultit++;
	}
	printContainer( resultContainer, "After Sort", GREEN );
	std::cout << std::endl << GREEN BOLD ">>> OK: properly sorted." RESET << std::endl;
	delete control;
}

int * getArrayToSort( int array_size, char **av )
{
	int * array = new int[array_size];
	for (int x = 0; x < array_size; x++)
	{
		array[x] = 0;
	}
	for ( int i = 0; av[i + 1] && i < array_size; i++ )
	{
		int nb = getNumber( av[i + 1], array, array_size );
		array[i] = nb;
	}
	return ( array );
}

int getNumber( char * nbStr, int * array, int array_size )
{
	long nb = atol( nbStr );
	std::stringstream intMax;
	intMax << std::numeric_limits<int>::max();
	if ( nb < 1 || nb > std::numeric_limits<int>::max() )
	{
		delete [] array;
		throw ( std::out_of_range( std::string( nbStr ) +
		                           ": must be a positive integer between 1 and " + intMax.str() ) );
	}
	if ( isADuplicate( array, array_size, nb ) )
	{
		delete [] array;
		throw ( std::out_of_range( std::string( nbStr ) + ": duplicate number" ) );
	}
	return ( nb );
}

bool isADuplicate( int * array, int array_size, int nb )
{
	for ( int i = 0; i < array_size; i++ )
	{
		if ( array[i] == nb )
		{
			return ( true );
		}
	}
	return ( false );
}

std::vector<int> * convertArrayToVector( int * array, int array_size )
{
	std::vector<int> * vector = new std::vector<int>();
	for ( int i = 0; i < array_size; i++ )
	{
		vector->push_back(array[i]);
	}
	return ( vector );
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
