/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:57 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/18 15:18:57 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#define VERBOSE 0

#include "Colors.h"
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

void printLine( std::string color, std::string key, std::string value);
std::string getContentsAsString( std::vector<int> & vector );
std::string getContentsAsString( std::vector< std::pair<int, int> > & vector );
std::string getContentsAsString( std::list<int> & list );
std::string getContentsAsString( std::list< std::pair<int, int> > & list );

template <typename T>
void printContainer( std::vector<T> & vector, std::string name, std::string color )
{
	std::stringstream ss;
	ss << name << " vector (size " << vector.size() << "): ";
	printLine( color, ss.str(), getContentsAsString( vector ) );
}

template <typename T>
void printContainer( std::list<T> & list, std::string name, std::string color )
{
	std::stringstream ss;
	ss << "-- " << name << " list (size " << list.size() << "): ";
	printLine( color, ss.str(), getContentsAsString( list ) );
}

int * getArrayToSort( int ac, char **av );
int getNumber( char * nbStr, int * array, int array_size );
bool isADuplicate( int * array, int array_size, int nb );
template <typename T>
void verifySortAccuracy( int * array, int array_size, T & resultContainer );
std::vector<int> * convertArrayToVector( int * array, int array_size );
void printTime(std::string containerType, std::clock_t time, int elements);
void testPmergeMe( int ac, char **av );
std::clock_t test_vector( int * array, int array_size);
std::clock_t test_list( int * array, int array_size );

#endif
