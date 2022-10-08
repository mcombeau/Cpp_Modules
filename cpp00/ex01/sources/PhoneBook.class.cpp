/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:13 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/08 18:26:58 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _index(0) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

std::string	PhoneBook::_getInput(std::string const prompt) {
	std::string	input;

	std::cout << "Please enter a " << prompt << ": ";
	std::getline(std::cin, input);
	return (input);
}

void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

void 	PhoneBook::addContact(void)
{
	std::string	input;

	std::cerr << "Adding contact at index " << _index << std::endl;
	while (1) {
		input = _getInput("first name");
		if (this->_contactList[_index].setFirstname(input))
			break ;
	}
	while (1) {
		input = _getInput("last name");
		if (this->_contactList[_index].setLastname(input))
			break ;
	}
	while (1) {
		input = _getInput("nickname");
		if (this->_contactList[_index].setNickname(input))
			break ;
	}
	while (1) {
		input = _getInput("phone number");
		if (this->_contactList[_index].setNumber(input))
			break ;
	}
	while (1) {
		input = _getInput("darkest secret");
		if (this->_contactList[_index].setSecret(input))
			break ;
	}
	std::cout << "All right! Your new contact #" << _index << " is :" << std::endl;
	this->_contactList[_index].displayContactInfo();
	_incrementIndex();
}
