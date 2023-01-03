/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:59 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <cmath>

void	multiplyIntByTwo(int & i);
void	roundDouble(double & d);
void	capitalizeChar(char & c);
void	capitalizeString(std::string & s);
void	appendSuffixString(std::string & s);

int	main(void)
{
	{
		std::cout << "---- EMPTY ARRAY TEST" << std::endl;
		
		int	intArray[] = {};
		size_t	arraySize = 0;

		std::cout << "Empty int array:\t\t";
		::printArray<int>(intArray, arraySize);

		::iter<int>(intArray, arraySize, ::addOne<int>);
		
		std::cout << "Empty int array add 1 iter:\t";
		::printArray<int>(intArray, arraySize);
		
		::iter<int>(intArray, arraySize, ::multiplyIntByTwo);
		
		std::cout << "Empty int array double iter:\t";
		::printArray<int>(intArray, arraySize);

	}
	{
		std::cout << std::endl << "---- INT ARRAY TEST" << std::endl;
		
		int	intArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		size_t	arraySize = 10;

		std::cout << "Int array:\t\t";
		::printArray<int>(intArray, arraySize);

		::iter<int>(intArray, arraySize, ::addOne<int>);
		
		std::cout << "Int array add 1 iter:\t";
		::printArray<int>(intArray, arraySize);
		
		::iter<int>(intArray, arraySize, ::multiplyIntByTwo);
		
		std::cout << "Int array double iter:\t";
		::printArray<int>(intArray, arraySize);

	}
	{
		std::cout << std::endl << "---- DOUBLE ARRAY TEST" << std::endl;
		
		double doubleArray[] = {0.2, 1.489, 20.5, 11.0};
		size_t	arraySize = 4;
		
		std::cout << "Double array:\t\t\t";
		::printArray<double>(doubleArray, arraySize);
		
		::iter<double>(doubleArray, arraySize, ::addOne<double>);
		
		std::cout << "Double array add 1 iter:\t";
		::printArray<double>(doubleArray, arraySize);
		
		::iter<double>(doubleArray, arraySize, ::roundDouble);
		
		std::cout << "Double array round iter:\t";
		::printArray<double>(doubleArray, arraySize);
	}
	{
		std::cout << std::endl << "---- CHAR ARRAY TEST" << std::endl;
		
		char charArray[] = {'a', 'b', 'c', 'd', 'e'};
		size_t	arraySize = 5;
		
		std::cout << "Char array:\t\t\t";
		::printArray<char>(charArray, arraySize);
		
		::iter<char>(charArray, arraySize, ::addOne<char>);
		
		std::cout << "Char array add 1 iter:\t\t";
		::printArray<char>(charArray, arraySize);
		
		::iter<char>(charArray, arraySize, ::capitalizeChar);
		
		std::cout << "Char array to upper iter:\t";
		::printArray<char>(charArray, arraySize);
	}
	{
		std::cout << std::endl << "---- STRING ARRAY TEST" << std::endl;
		
		std::string stringArray[] = {"Hello", "world", "!"};
		size_t	arraySize = 3;
		
		std::cout << "String array:\t\t\t";
		::printArray<std::string>(stringArray, arraySize);
		
		::iter<std::string>(stringArray, arraySize, ::capitalizeString);
		
		std::cout << "String array to upper iter:\t";
		::printArray<std::string>(stringArray, arraySize);

		::iter<std::string>(stringArray, arraySize, ::appendSuffixString);
	
		std::cout << "String array append iter:\t";
		::printArray<std::string>(stringArray, arraySize);
	}
	return (0);
}

void	multiplyIntByTwo(int & i)
{
	i *= 2;
	return ;
}

void	roundDouble(double & d)
{
	d = ::round(d);
	return ;
}

void	capitalizeChar(char & c)
{
	c = std::toupper(c);
	return ;
}

void	capitalizeString(std::string & s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); it++)
		*it = std::toupper(*it);
	return ;
}

void	appendSuffixString(std::string & s)
{
	s += "_suffix";
	return ;
}
