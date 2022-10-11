/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:10 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/11 16:35:46 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Constructor	*/
Contact::Contact(void) : _firstname(""),
						_lastname(""),
						_nickname(""),
						_number(""),
						_secret("") {
	return ;
}

/*	Desctructor	*/
Contact::~Contact(void) {
	return ;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

/*	Returns the firstname private variable	*/
std::string const	Contact::getFirstname(void) const {
	return (this->_firstname);
}

/*	Returns the lastname private variable	*/
std::string const	Contact::getLastname(void) const {
	return (this->_lastname);
}

/*	Returns the nickname private variable	*/
std::string const	Contact::getNickname(void) const {
	return (this->_nickname);
}

/*	Returns the phone number private variable	*/
std::string const	Contact::getNumber(void) const {
	return (this->_number);
}

/*	Returns the darkest secret private variable	*/
std::string const	Contact::getSecret(void) const {
	return (this->_secret);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

/*	Sets the first name variable with the provided string, unless the provided
	string is empty or is not composed only of letters.
	Returns true if the variable was successfully set, false if not.	*/
bool	Contact::setFirstname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyAlpha(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	str[0] = std::toupper(str[0]);
	this->_firstname = str;
	return (true);
}

/*	Sets the last name variable with the provided string, unless the provided
	string is empty or is not composed only of letters.
	Returns true if the variable was successfully set, false if not.	*/
bool	Contact::setLastname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyAlpha(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		*it = std::toupper(*it);
	}
	this->_lastname = str;
	return (true);
}

/*	Sets the nickname variable with the provided string, unless the provided
	string is empty or is not composed only of letters.
	Returns true if the variable was successfully set, false if not.	*/
bool	Contact::setNickname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyAlpha(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	str[0] = std::toupper(str[0]);
	this->_nickname = str;
	return (true);
}

/*	Sets the phone number variable with the provided string, unless the provided
	string is empty or is not composed only of digits.
	Returns true if the variable was successfully set, false if not.	*/
bool	Contact::setNumber(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyDigits(str)) {
		std::cout << "Error: Phone numbers can only contain digits, spaces and hyphens." << std::endl;
		return (false);
	}
	this->_number = str;
	return (true);
}

/*	Sets the darkest secret variable with the provided string, unless the provided
	string is empty.
	Returns true if the variable was successfully set, false if not.	*/
bool	Contact::setSecret(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	this->_secret = str;
	return (true);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

/*	Checks whether a string is only composed of alphabetical characters.
	Returns true if it is, false if not.	*/
bool	Contact::_containsOnlyAlpha(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isalpha(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

/*	Checks whether a string is only composed of numeric characters.
	Returns true if it is, false if not.	*/
bool	Contact::_containsOnlyDigits(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isdigit(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

/*	Checks whether a any of the class variables are empty.
	Returns true if this instance of Contact is empty, false if not.	*/
bool	Contact::isEmpty(void) const {
	if (this->_firstname.empty()
		|| this->_lastname.empty()
		|| this->_nickname.empty()
		|| this->_number.empty()
		|| this->_secret.empty())
		return (true);
	return (false);
}

/*	Displays the contact information contained in this instance.
	Returns true if the contact information can be displayed.
	Returns false if the contact information is empty and cannot be displayed.	*/
bool	Contact::displayContactInfo(void) const {
	if (this->isEmpty())
		return (false);
	std::cout	<< "+ First name\t: "	<< this->getFirstname()	<< std::endl
				<< "+ Last name\t: "	<< this->getLastname()	<< std::endl
				<< "+ Nickname\t: "		<< this->getNickname()	<< std::endl
				<< "+ Phone number\t: "	<< this->getNumber() 	<< std::endl
				<< "+ Darkest secret: "	<< this->getSecret()	<< std::endl;
	return (true);
}