/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:13 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/13 16:00:31 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Constructor	*/
PhoneBook::PhoneBook(void) : _index(-1), _abort(false) {
	return ;
}

/*	Destructor	*/
PhoneBook::~PhoneBook(void) {
	return ;
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

/*	Prompts the user for input.
	Returns a string containing the user's input, trimmed of leading and
	trailling whitespaces.
	Returns an empty string if input is empty or EOF and flags this case.  */
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

/*	Increments the pvirate index variable. If the index goes beyond 7, sets the
	index back to 0.	*/
void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

/*	Displays the list of recorded contacts in table form.	*/
void	PhoneBook::_displayContactTable(void) const {
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++) {
		_printContactInfoToTable(i);
	}
	std::cout << std::endl;
	return ;
}

/*	Displays a table line filled with the contact at index's information.
	Displays nothing if the contact is empty.	*/
void	PhoneBook::_printContactInfoToTable(int const index) const {
	if (this->_contactList[index].isEmpty())
		return ;
	std::cout << "|" << std::setw(10) << index << "|";
	_printTableString(this->_contactList[index].getFirstname());
	_printTableString(this->_contactList[index].getLastname());
	_printTableString(this->_contactList[index].getNickname());
	std::cout	<< std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	return ;
}

/*	Formats and prints a 10 character-wide cell in the contact table.
	If the string to display is too long, truncates it and adds a ".".	*/
void PhoneBook::_printTableString(std::string str) const {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

/*	Analyses user input and displays contact information for the requested
	index, or an error message if the input is invalid.	*/
bool	PhoneBook::_displayContactByIndex(std::string const input) const {

	int			index;

	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_contactList[index].displayContactInfo())
				return (true);
			else {
				std::cout << "Error: No record at index [" << index << "]. Please ADD a contact and try again." << std::endl;
				return (false);
			}
		}
	}
	std::cout << "Error: \'" << input << "' is not a valid index (a digit between 0 and 7). Please try again later." << std::endl;
	return (false);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

/*	Trims the whitespace at the beginning and end of a string.
	Returns the trimmed string.
	Returns the string if there is no whitespace to trim.	*/
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

/*	Adds a contact at the next index. Prompts the user for contact
	information. Aborts the process if input was empty or EOF.	*/
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

/*	Displays the information for contact at the specified index.
	Displays an error message if the contact could not be displayed (should
	never occur).	*/
void	PhoneBook::displayContact(int index) const {
	if (index >= 0 && index <= 7) {
		if (this->_contactList[index].displayContactInfo())
			return ;
	}
	std::cout << "Error: No record for the requested contact." << std::endl;
}

/*	Displays a table containing basic information for recorded contacts, then
	prompts the user for an index to display complete contact information.
	Displays an error message if there are no recorded contacts.	*/
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
