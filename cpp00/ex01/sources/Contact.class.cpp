/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:10 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/08 18:20:06 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void) : _firstname(""),
						_lastname(""),
						_nickname(""),
						_number(""),
						_secret("") {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string const	Contact::getFirstname(void) const {
	return (this->_firstname);
}

std::string const	Contact::getLastname(void) const {
	return (this->_lastname);
}

std::string const	Contact::getNickname(void) const {
	return (this->_nickname);
}

std::string const	Contact::getNumber(void) const {
	return (this->_number);
}

std::string const	Contact::getSecret(void) const {
	return (this->_secret);
}

bool	Contact::_containsOnlyAlpha(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isalpha(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

bool	Contact::_containsOnlyDigits(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isdigit(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

bool	Contact::setFirstname(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyAlpha(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	this->_firstname = str;
	return (true);
}

bool	Contact::setLastname(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyAlpha(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	this->_lastname = str;
	return (true);
}

bool	Contact::setNickname(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_containsOnlyAlpha(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	this->_nickname = str;
	return (true);
}

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

bool	Contact::setSecret(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	this->_secret = str;
	return (true);
}

void	Contact::displayContactInfo(void) const {
	std::cout << "First name\t: "	<< this->getFirstname()	<< std::endl;
	std::cout << "Last name\t: "	<< this->getLastname()	<< std::endl;
	std::cout << "Nickname\t: "		<< this->getNickname()	<< std::endl;
	std::cout << "Phone number\t: "	<< this->getNumber() 	<< std::endl;
	std::cout << "Darkest secret\t: "<< this->getSecret()	<< std::endl;
	return ;
}