/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2023/01/03 19:19:42 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#define RESET "\e[0m"
#define BOLD "\e[1m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"

void	testSubject(void);
void	testCharDequeMutantStack(void);
void	testStringVectorMutantStack(void);
void	testFloatListMutantStack(void);

int	main(void)
{
	::testSubject();
	::testCharDequeMutantStack();
	// ::testStringVectorMutantStack();
	// ::testFloatListMutantStack();
	return 0;
}

void	testSubject(void)
{
	std::cout << std::endl << "---- SUBJECT TESTS" << std::endl;
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

template <typename T>
void	printMutantStackSize(std::string name, MutantStack<T> mutantStack)
{
	std::cout << name << " is empty: " << std::boolalpha << mutantStack.empty()
		<< " (size = " << mutantStack.size() << ")." << std::endl;
	return ;
}

template <typename T>
void	printMutantStackTop(std::string name, MutantStack<T> mutantStack)
{
	std::cout << name << " top: ";
	if (!mutantStack.empty())
		std::cout << "[" << mutantStack.top() << "]";
	else
		std::cout << "Nothing (empty stack)";
	std::cout << std::endl;
	return ;
}

template <typename T>
void	printMutantStackWithIterator(std::string name, MutantStack<T> mutantStack)
{
	std::cout << "Iterator: " << name << " contents begin to end: ";
	typename MutantStack<T>::iterator it = mutantStack.begin();
	typename MutantStack<T>::iterator ite = mutantStack.end();
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl
		<< "Iterator: " << name << " contents end to begin: ";
	it = mutantStack.begin();
	ite--;
	for (; ite >= it; --ite)
		std::cout << "[" << *ite << "] ";
	std::cout << std::endl;
}

template <typename T>
void	printMutantStackWithConstIterator(std::string name, MutantStack<T> const mutantStack)
{
	std::cout << "Const iterator: " << name << " contents begin to end: ";
	typename MutantStack<T>::const_iterator it = mutantStack.begin();
	typename MutantStack<T>::const_iterator ite = mutantStack.end();
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl
		<< "Const iterator: " << name << " contents end to begin: ";
	it = mutantStack.begin();
	ite--;
	for (; ite >= it; --ite)
		std::cout << "[" << *ite << "] ";
	std::cout << std::endl;
}

template <typename T>
void	printMutantStackWithReverseIterator(std::string name, MutantStack<T> mutantStack)
{
	std::cout << "Reverse iterator: " << name << " contents rbegin to rend: ";
	typename MutantStack<T>::reverse_iterator itr = mutantStack.rbegin();
	typename MutantStack<T>::reverse_iterator itre = mutantStack.rend();
	for (; itr != itre; ++itr)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl
		<< "Reverse iterator: " << name << " contents rend to rbegin: ";
	itr = mutantStack.rbegin();
	itre--;
	for (; itre >= itr; --itre)
		std::cout << "[" << *itre << "] ";
	std::cout << std::endl;
}

template <typename T>
void	printMutantStackWithConstReverseIterator(std::string name, MutantStack<T> const mutantStack)
{
	std::cout << "Const reverse iterator: " << name << " contents rbegin to rend: ";
	typename MutantStack<T>::const_reverse_iterator itr = mutantStack.rbegin();
	typename MutantStack<T>::const_reverse_iterator itre = mutantStack.rend();
	for (; itr != itre; ++itr)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl
		<< "Const reverse iterator: " << name << " contents rend to rbegin: ";
	itr = mutantStack.rbegin();
	itre--;
	for (; itre >= itr; --itre)
		std::cout << "[" << *itre << "] ";
	std::cout << std::endl;
}

void	testCharDequeMutantStack(void)
{
	std::cout << std::endl << "---- MUTANT STACK CHAR DEQUE TESTS" << std::endl;
	
	MutantStack< char, std::deque<char> >	mutantStack;
	std::cout << std::endl << "-- Created empty char mutant stack with deque container." << std::endl;

	::printMutantStackSize("MS", mutantStack);
	for (int i = 0; i < 26; i++)
		mutantStack.push('a' + i);
	std::cout << std::endl << "-- Pushed alphabet to mutant stack with push()." << std::endl;
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);
	::printMutantStackWithReverseIterator("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);

	MutantStack< char, std::deque<char> > const	constMutantStack(mutantStack);
	std::cout << std::endl << "-- Contructed const mutant stack copy." << std::endl;
	::printMutantStackSize("CMS", constMutantStack);
	::printMutantStackWithConstIterator("CMS", constMutantStack);
	::printMutantStackWithConstReverseIterator("CMS", constMutantStack);
	::printMutantStackTop("CMS", constMutantStack);

	std::cout << std::endl << "-- Emptying original mutant stack with pop()." << std::endl;
	for (int i = 0; i < 26; i++)
		mutantStack.pop();
	::printMutantStackSize("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
}

void	testStringVectorMutantStack(void)
{

}

void	testFloatListMutantStack(void)
{

}
