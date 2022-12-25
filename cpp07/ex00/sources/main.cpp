/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/25 12:40:04 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <limits>
#include <string>

void	testSubjectExamples(void)
{
	std::cout << "---- SUBJECT TESTS" << std::endl << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl
		<< std::endl;
}

void	testInt(int a, int b)
{
	std::cout << "Pre-swap:\t";
	::printValues<int>(a, b);
	std::cout << "\t-> Max: " << ::max<int>(a, b)
		<< " / Min: " << ::min<int>(a, b) << std::endl;
	
	::swap<int>(a, b);
	
	std::cout << "Post-swap:\t";
	::printValues<int>(a, b);
	std::cout << "\t-> Max: " << ::max<int>(a, b)
		<< " / Min: " << ::min<int>(a, b) << std::endl;
	std::cout << std::endl;
}

void	testFloat(float a, float b)
{
	std::cout << "Pre-swap:\t";
	::printValues<float>(a, b);
	std::cout << "\t-> Max: " << ::max<float>(a, b)
		<< " / Min: " << ::min<float>(a, b) << std::endl;
	
	::swap<float>(a, b);
	
	std::cout << "Post-swap:\t";
	::printValues<float>(a, b);
	std::cout << "\t-> Max: " << ::max<float>(a, b)
		<< " / Min: " << ::min<float>(a, b) << std::endl;
	std::cout << std::endl;
}

void	testChar(char a, char b)
{
	std::cout << "Pre-swap:\t";
	::printValues<char>(a, b);
	std::cout << "\t-> Max: " << ::max<char>(a, b)
		<< " / Min: " << ::min<char>(a, b) << std::endl;
	
	::swap<char>(a, b);
	
	std::cout << "Post-swap:\t";
	::printValues<char>(a, b);
	std::cout << "\t-> Max: " << ::max<char>(a, b)
		<< " / Min: " << ::min<char>(a, b) << std::endl;
	std::cout << std::endl;
}

void	testString(std::string a, std::string b)
{
	std::cout << "Pre-swap:\t";
	::printValues<std::string>(a, b);
	std::cout << "\t-> Max: " << ::max<std::string>(a, b)
		<< " / Min: " << ::min<std::string>(a, b) << std::endl;
	
	::swap<std::string>(a, b);
	
	std::cout << "Post-swap:\t";
	::printValues<std::string>(a, b);
	std::cout << "\t-> Max: " << ::max<std::string>(a, b)
		<< " / Min: " << ::min<std::string>(a, b) << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	::testSubjectExamples();
	
	std::cout << "---- INT TESTS" << std::endl << std::endl;
	::testInt(42, 0);
	::testInt(-500, 300);
	::testInt(42, 42);
	::testInt(std::numeric_limits<int>::max(), std::numeric_limits<int>::min());
	
	std::cout << "---- FLOAT TESTS" << std::endl << std::endl;
	::testFloat(0.42, 42);
	::testFloat(-20.02, 500);
	::testFloat(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
	
	std::cout << "---- CHAR TESTS" << std::endl << std::endl;
	::testChar('a', 'z');
	::testChar('X', '~');
	::testChar(35, 119);
	
	std::cout << "---- STRING TESTS" << std::endl << std::endl;
	::testString("Hello!", "World");
	::testString("abracadabra", "XYZ");
	::testString("", "Clap");
	::testString("...", "!!?");
	return (0);
}
