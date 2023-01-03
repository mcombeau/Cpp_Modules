/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 14:03:36 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

#define NB_VALUES 20
#define LESS_VALUES 5
#define MORE_VALUES 25

void	checkArrayValuesAgainstControl(Array<int> & array, int * control);
void	testCopyConstructor(Array<int> & array);
void	testSubscriptOperator(Array<int> & array);
void	testSubscriptOperatorByIndex(Array<int> & array, int index);
void	testAssignmentOperator(Array<int> & array);

int main(void)
{
	{
		std::cout << std::endl << "------------------------------------" << std::endl
			<< "\tTESTING INT" << std::endl
			<< "------------------------------------" << std::endl;
		Array<int>	numbers(NB_VALUES);
		int	*		controlArray = new int[NB_VALUES];

		std::srand(std::time(NULL));
		for (int i = 0; i < NB_VALUES; i++)
		{
			const int	value = std::rand() % 100;
			numbers[i] = value;
			controlArray[i] = value;
		}
		::checkArrayValuesAgainstControl(numbers, controlArray);
		delete [] controlArray;
		
		::testCopyConstructor(numbers);
		::testSubscriptOperator(numbers);
		::testAssignmentOperator(numbers);
	}
	{
		std::cout << std::endl << "------------------------------------" << std::endl
			<< "\tTESTING STRING" << std::endl
			<< "------------------------------------" << std::endl;

		Array<std::string>	strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!!";
		std::cout << CYAN "String array (size " << strings.size()
			<< "):\t" << strings << RESET << std::endl;
		
		Array<std::string>	otherStrings(2);
		otherStrings[0] = "Coucou";
		otherStrings[1] = "La vie est belle.";
		std::cout << "Other strings (size " << otherStrings.size()
			<< "):\t" << otherStrings << std::endl;

		strings = otherStrings;
		std::cout << CYAN "String array (size " << strings.size()
			<< "):\t" << strings << RESET << std::endl;
		try
		{
			strings[3] = "Extra.";
			std::cout << RED "Accessed out of bounds index [3], "
				"but no exception thrown..." RESET << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cout << GREEN "Accessed out of bounds index [3], "
				"and got exception: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl << "------------------------------------" << std::endl
			<< "\tTESTING CHAR" << std::endl
			<< "------------------------------------" << std::endl;

		Array<char>	chars(NB_VALUES);
		for (int i = 0; i < NB_VALUES; i++)
			chars[i] = 'a' + i;
		std::cout << CYAN "Char array (size " << chars.size()
			<< "):\t" << chars << RESET << std::endl;
		
		Array<char>	otherChars(MORE_VALUES);
		for (int i = 0; i < MORE_VALUES; i++)
			otherChars[i] = 'Z' - i;
		std::cout << "Other Chars (size " << otherChars.size()
			<< "):\t" << otherChars << std::endl;

		chars = otherChars;
		std::cout << CYAN "Char array (size " << chars.size()
			<< "):\t" << chars << RESET << std::endl;
		try
		{
			chars[MORE_VALUES] = '~';
			std::cout << RED "Accessed out of bounds index [" << MORE_VALUES <<"], "
				"but no exception thrown..." RESET << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cout << GREEN "Accessed out of bounds index [" << MORE_VALUES << "], "
				"and got exception: " << e.what() << RESET << std::endl;
		}
	}
	return (0);
}

void	checkArrayValuesAgainstControl(Array<int> & array, int * control)
{
	bool	ok = true;
	
	std::cout << "---- CHECK ARRAY ASSIGNMENT VALUES" << std::endl;
	std::cout << "Control:\t";
	for (int i = 0; i < NB_VALUES; i++)
		std::cout << "[" << control[i] << "] ";

	std::cout << std::endl << "Array:\t\t";
	for (int i = 0; i < NB_VALUES; i++)
	{
		if (array[i] != control[i])
		{
			ok = false;
			std::cout << RED "[" << array[i] << "] " RESET;
		}
		else
			std::cout << GREEN "[" << array[i] << "] " RESET;
	}
	std::cout << std::endl << "--> Array value assignment checker: ";
	if (ok == false)
		std::cerr << RED BOLD "KO: Incorrect array values!" RESET << std::endl;
	else
		std::cout << GREEN BOLD "OK." RESET << std::endl;
	return ;
}

void	testCopyConstructor(Array<int> & array)
{
	std::cout << std::endl << "--- TEST COPY CONSTRUCTOR" << std::endl;
	bool	ok = true;
	std::cout << "Array (size " << array.size() << "):\t" << array << std::endl;
	
	Array<int> copy(array);
	std::cout << "Copy (size ";
	if (copy.size() == array.size())
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << copy.size() << RESET "):\t\t";
	for (int i = 0; i < NB_VALUES; i++)
	{
		if (copy[i] != array[i])
		{
			ok = false;
			std::cout << RED "[" << copy[i] << "] " RESET;
		}
		else
			std::cout << GREEN "[" << copy[i] << "] " RESET;
	}
	std::cout << std::endl << "--> Copy value checker: ";
	if (ok == false)
		 std::cout << RED BOLD "KO: Copy values do not match original array values."
		 	RESET << std::endl;
	else
		std::cout << GREEN BOLD "OK." RESET << std::endl;
}

void	testSubscriptOperator(Array<int> & array)
{
	std::cout << std::endl << "---- TEST SUBSCRIPT [] OPERATOR" << std::endl;
	std::cout << "Array: " << array << std::endl;
	::testSubscriptOperatorByIndex(array, 0);
	::testSubscriptOperatorByIndex(array, LESS_VALUES);
	::testSubscriptOperatorByIndex(array, NB_VALUES - 1);
	::testSubscriptOperatorByIndex(array, -1);
	::testSubscriptOperatorByIndex(array, NB_VALUES);
	::testSubscriptOperatorByIndex(array, MORE_VALUES);
	std::cout << "Result: " << array << std::endl;
}

void	testSubscriptOperatorByIndex(Array<int> & array, int index)
{
	bool	expectExecption = false;
	if (index >= NB_VALUES || index < 0)
		expectExecption = true;
	try
	{
		std::cout << "Array[" << index << "] = 0:\t";
		array[index] = 0;
		if (expectExecption)
			std::cout << RED BOLD "KO! " RESET RED "Did not throw exception. (Expected exception)" RESET << std::endl;
		else
			std::cout << GREEN BOLD "OK: " RESET GREEN "Did not throw exception." RESET << std::endl;

	}
	catch (const std::exception & e)
	{
		if (expectExecption)
			std::cout << GREEN BOLD "OK. " RESET GREEN "Got exception: " << e.what()
				<< " (Expected exception)" RESET << std::endl;
		else
			std::cout << RED BOLD "KO! " RESET RED "Got exception: " << e.what()
				<< " (Should not have thrown exception)" RESET << std::endl;
	}
}

void	testAssignmentOperator(Array<int> & array)
{
	std::cout << std::endl << "---- TEST ASSIGNMENT OPERATOR" << std::endl;
	std::cout << CYAN "Array (size " << array.size() << "):\t\t" << array << RESET << std::endl;
	Array<int> zeroArray(LESS_VALUES);
	for (int i = 0; i < LESS_VALUES; i++)
		zeroArray[i] = 0;
	std::cout << "Zero Array (size " << zeroArray.size() << "):\t\t" << zeroArray << std::endl;
	array = zeroArray;
	std::cout << CYAN "Array assigned (size " << array.size() << "):\t" << array << RESET << std::endl;
	Array<int> oneArray(MORE_VALUES);
	for (int i = 0; i < MORE_VALUES; i++)
		oneArray[i] = 1;
	std::cout << "One Array (size " << oneArray.size() << "):\t\t" << oneArray << std::endl;
	array = oneArray;
	std::cout << CYAN "Array assigned (size " << array.size() << "):\t" << array << RESET << std::endl;
}