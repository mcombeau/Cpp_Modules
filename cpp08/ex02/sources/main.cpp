/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/04 15:45:16 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

void	testSubject(void);
void	testCharDequeMutantStack(void);
void	testFloatVectorMutantStack(void);
void	testIntListMutantStack(void);
void	testStringListMutantStack(void);
template <typename T, typename C>
void	printMutantStackSize(std::string name, MutantStack<T, C> mutantStack);
template <typename T, typename C>
void	printMutantStackTop(std::string name, MutantStack<T, C> mutantStack);
template <typename T, typename C>
void	printMutantStackWithIterator(std::string name, MutantStack<T, C> mutantStack);
template <typename T, typename C>
void	printMutantStackWithConstIterator(std::string name, MutantStack<T, C> const mutantStack);
template <typename T, typename C>
void	printMutantStackWithReverseIterator(std::string name, MutantStack<T, C> mutantStack);
template <typename T, typename C>
void	printMutantStackWithConstReverseIterator(std::string name, MutantStack<T, C> const mutantStack);

int	main(void)
{
	::testSubject();
	::testCharDequeMutantStack();
	::testFloatVectorMutantStack();
	::testIntListMutantStack();
	::testStringListMutantStack();
	return 0;
}

void	testSubject(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "----          SUBJECT TESTS          ----" << std::endl
		<< "=========================================" << std::endl;
	{
		std::cout << std::endl << "-- Mutant Stack:" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Stack top (expecting 17): " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Stack size (expecting 1): " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "Iterating over mstack from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "-- List:" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "List \"top\" (back) (expecting 17): " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "Stack size (expecting 1): " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::cout << "Iterating over mstack list from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	testCharDequeMutantStack(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "----  MUTANT STACK CHAR DEQUE TESTS  ----" << std::endl
		<<  "=========================================" << std::endl;
	
	MutantStack< char, std::deque<char> >	mutantStack;
	std::cout << std::endl << GREEN "-- Created empty char mutant stack with deque container." RESET << std::endl;

	::printMutantStackSize("MS", mutantStack);
	for (int i = 0; i < 26; i++)
		mutantStack.push('a' + i);
	std::cout << std::endl << GREEN "-- Pushed alphabet to mutant stack with push()." RESET << std::endl;
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);
	::printMutantStackWithReverseIterator("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);

	MutantStack< char, std::deque<char> > const	constMutantStack(mutantStack);
	std::cout << std::endl << GREEN "-- Contructed const mutant stack copy." RESET << std::endl;
	::printMutantStackSize("CMS", constMutantStack);
	::printMutantStackWithConstIterator("CMS", constMutantStack);
	::printMutantStackWithConstReverseIterator("CMS", constMutantStack);
	::printMutantStackTop("CMS", constMutantStack);

	std::cout << std::endl << GREEN "-- Emptying original mutant stack with pop()." RESET << std::endl;
	for (int i = 0; i < 26; i++)
		mutantStack.pop();
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
}

void	testFloatVectorMutantStack(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "---- MUTANT STACK FLOAT VECTOR TESTS ----" << std::endl
		<<  "=========================================" << std::endl;
	
	MutantStack< float, std::vector<float> >	mutantStack;
	std::cout << std::endl << GREEN "-- Created empty float mutant stack with vector container." RESET << std::endl;

	::printMutantStackSize("MS", mutantStack);
	for (int i = 1; i < 10; i++)
		mutantStack.push(0.3f * i);
	std::cout << std::endl << GREEN "-- Pushed floats to mutant stack with push()." RESET << std::endl;
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);
	::printMutantStackWithReverseIterator("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);

	MutantStack< float, std::vector<float> > const	constMutantStack(mutantStack);
	std::cout << std::endl << GREEN "-- Contructed const mutant stack copy." RESET << std::endl;
	::printMutantStackSize("CMS", constMutantStack);
	::printMutantStackWithConstIterator("CMS", constMutantStack);
	::printMutantStackWithConstReverseIterator("CMS", constMutantStack);
	::printMutantStackTop("CMS", constMutantStack);

	std::cout << std::endl << GREEN "-- Erasing 6 elements from original mutant stack with pop()." RESET << std::endl;
	for (size_t i = 0; i < 6; i++)
		mutantStack.pop();
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);

	std::cout << std::endl << GREEN "-- Emptying all elements from original mutant stack with pop()." RESET << std::endl;
	for (size_t i = 0; i < 3; i++)
		mutantStack.pop();
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
}

void	testIntListMutantStack(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "----   MUTANT STACK INT LIST TESTS   ----" << std::endl
		<< "=========================================" << std::endl;
	
	MutantStack< int, std::list<int> >	mutantStack;
	std::cout << std::endl << GREEN "-- Created empty int mutant stack with list container." RESET << std::endl;

	::printMutantStackSize("MS", mutantStack);
	for (int i = 0; i < 10; i++)
		mutantStack.push(i);
	std::cout << std::endl << GREEN "-- Pushed numbers to mutant stack with push()." RESET << std::endl;
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);
	::printMutantStackWithReverseIterator("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);

	MutantStack< int, std::list<int> > const	constMutantStack(mutantStack);
	std::cout << std::endl << GREEN "-- Contructed const mutant stack copy." RESET << std::endl;
	::printMutantStackSize("CMS", constMutantStack);
	::printMutantStackWithConstIterator("CMS", constMutantStack);
	::printMutantStackWithConstReverseIterator("CMS", constMutantStack);
	::printMutantStackTop("CMS", constMutantStack);

	std::cout << std::endl << GREEN "-- Emptying original mutant stack with pop()." RESET << std::endl;
	for (size_t i = 0; i < 10; i++)
		mutantStack.pop();
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
}

void	testStringListMutantStack(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "----  MUTANT STACK STRING LIST TESTS ----" << std::endl
		<< "=========================================" << std::endl;
	
	MutantStack< std::string, std::list<std::string> >	mutantStack;
	std::cout << std::endl << GREEN "-- Created empty string mutant stack with list container." RESET << std::endl;

	::printMutantStackSize("MS", mutantStack);
	mutantStack.push("Hello");
	mutantStack.push("Coucou");
	mutantStack.push("Hola");
	mutantStack.push("Salutations");
	mutantStack.push("Bonjour");
	std::cout << std::endl << GREEN "-- Pushed strings to mutant stack with push()." RESET << std::endl;
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);
	::printMutantStackWithReverseIterator("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);

	MutantStack< std::string, std::list<std::string> > const	constMutantStack(mutantStack);
	std::cout << std::endl << GREEN "-- Contructed const mutant stack copy." RESET << std::endl;
	::printMutantStackSize("CMS", constMutantStack);
	::printMutantStackWithConstIterator("CMS", constMutantStack);
	::printMutantStackWithConstReverseIterator("CMS", constMutantStack);
	::printMutantStackTop("CMS", constMutantStack);

	std::cout << std::endl << GREEN "-- Emptying original mutant stack with pop()." RESET << std::endl;
	mutantStack.pop();
	mutantStack.pop();
	mutantStack.pop();
	mutantStack.pop();
	mutantStack.pop();
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
}

template <typename T, typename C>
void	printMutantStackSize(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << name << " is empty: " << std::boolalpha << mutantStack.empty()
		<< " (size = " << mutantStack.size() << ")." << std::endl;
	return ;
}

template <typename T, typename C>
void	printMutantStackTop(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << name << " top: ";
	if (!mutantStack.empty())
		std::cout << "[" << mutantStack.top() << "]";
	else
		std::cout << "Nothing (empty stack)";
	std::cout << std::endl;
	return ;
}

template <typename T, typename C>
void	printMutantStackWithIterator(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << CYAN "Iterator: " RESET << name << " contents begin to end: ";
	typename MutantStack<T, C>::iterator it = mutantStack.begin();
	typename MutantStack<T, C>::iterator ite = mutantStack.end();
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl
		<< CYAN "Iterator: " RESET << name << " contents end to begin: ";
	it = mutantStack.begin();
	ite--;
	for (; ite != it; --ite)
		std::cout << "[" << *ite << "] ";
	std::cout << "[" << *ite << "] ";
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithConstIterator(std::string name, MutantStack<T, C> const mutantStack)
{
	std::cout << YELLOW "Const iterator: " RESET << name << " contents begin to end: ";
	typename MutantStack<T, C>::const_iterator it = mutantStack.begin();
	typename MutantStack<T, C>::const_iterator ite = mutantStack.end();
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl
		<< YELLOW "Const iterator: " RESET << name << " contents end to begin: ";
	it = mutantStack.begin();
	ite--;
	for (; ite != it; --ite)
		std::cout << "[" << *ite << "] ";
	std::cout << "[" << *ite << "] ";
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithReverseIterator(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << BLUE "Reverse iterator: " RESET << name << " contents rbegin to rend: ";
	typename MutantStack<T, C>::reverse_iterator itr = mutantStack.rbegin();
	typename MutantStack<T, C>::reverse_iterator itre = mutantStack.rend();
	for (; itr != itre; ++itr)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl
		<< BLUE "Reverse iterator: " RESET << name << " contents rend to rbegin: ";
	itr = mutantStack.rbegin();
	itre--;
	for (; itre != itr; --itre)
		std::cout << "[" << *itre << "] ";
	std::cout << "[" << *itre << "] ";
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithConstReverseIterator(std::string name, MutantStack<T, C> const mutantStack)
{
	std::cout << PURPLE "Const reverse iterator: " RESET << name << " contents rbegin to rend: ";
	typename MutantStack<T, C>::const_reverse_iterator itr = mutantStack.rbegin();
	typename MutantStack<T, C>::const_reverse_iterator itre = mutantStack.rend();
	for (; itr != itre; ++itr)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl
		<< PURPLE "Const reverse iterator: " RESET << name << " contents rend to rbegin: ";
	itr = mutantStack.rbegin();
	itre--;
	for (; itre != itr; --itre)
		std::cout << "[" << *itre << "] ";
	std::cout << "[" << *itre << "] ";
	std::cout << std::endl;
}
