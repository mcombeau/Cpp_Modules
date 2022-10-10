/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:13 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/10 17:30:11 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _index(-1), _abort(false) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

std::string	PhoneBook::_getInput(std::string const prompt) {
	std::string	input;

	std::cout << "Please enter " << prompt << ": " << std::endl << "> ";
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_abort = true;
		std::cout << std::endl;
		return(std::string());
	}
	input = trimBlank(input);
	return (input);
}

void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

std::string	PhoneBook::trimBlank(std::string str) {
	std::string	blank = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(blank);
	end = str.find_last_not_of(blank);
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

bool 	PhoneBook::addContact(void) {
	std::string	input;

	_incrementIndex();
	std::cout << std::endl << "+------------ New Contact Menu -------------+" << std::endl << std::endl;
	while (!_abort) {
		input = _getInput("a first name");
		if (_abort || this->_contactList[_index].setFirstname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("a last name");
		if (_abort || this->_contactList[_index].setLastname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("a nickname");
		if (_abort || this->_contactList[_index].setNickname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("a phone number");
		if (_abort || this->_contactList[_index].setNumber(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("a darkest secret");
		if (_abort || this->_contactList[_index].setSecret(input))
			break ;
	}
	if (_abort) {
		_abort = false;
		return (false);
	}
	std::cout << "Contact successfully saved." << std::endl;
	return (true);
}

void	PhoneBook::displayContact(int index) {
	if (index >= 0 && index <= 7) {
		if (this->_contactList[index].displayContactInfo())
			return ;
	}
	std::cout << "That contact does not exist!" << std::endl;
}

void PhoneBook::_printTableString(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

void	PhoneBook::_printContactInfoToTable(int const index) {
	if (this->_contactList[index].isEmpty())
		return ;
	std::cout << "|" << std::setw(10) << index << "|";
	_printTableString(this->_contactList[index].getFirstname());
	_printTableString(this->_contactList[index].getLastname());
	_printTableString(this->_contactList[index].getNickname());
	std::cout << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return ;
}

void	PhoneBook::_displayContactTable(void) {
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++) {
		_printContactInfoToTable(i);
	}
	std::cout << std::endl;
	return ;
}


bool	PhoneBook::_displayContactByIndex(std::string const input) {

	int			index;

	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_contactList[index].displayContactInfo())
				return (true);
			else {
				std::cout << "No record at index [" << index << "]. Please ADD a contact and try again." << std::endl;
				return (false);
			}
		}
	}
	std::cout << "\'" << input << "' is not a valid index (0-7). Please try again." << std::endl;
	return (false);
}

bool	PhoneBook::searchContact(void) {
	std::string	input;

	std::cout << std::endl << "+-------------- Search Menu ----------------+" << std::endl << std::endl;
	if (_index == -1) {
		std::cout << "No contacts in record. Please ADD a contact first." << std::endl;
		return (true);
	}
	this->_displayContactTable();
	input = _getInput("the index of the contact to display");
	if (input.empty())
		return (false);
	this->_displayContactByIndex((std::string const)input);
	return (true);
}
