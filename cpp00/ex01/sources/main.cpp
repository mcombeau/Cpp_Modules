/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:16 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/10 17:37:02 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

std::string	getInput(PhoneBook *book) {
	std::string	userInput;

	if (!std::getline(std::cin, userInput) || std::cin.eof()) {
		std::cout << "EXIT" << std::endl;
		return ("EXIT");
	}
	userInput = book->trimBlank(userInput);
	for (std::string::iterator it = userInput.begin(); it != userInput.end(); it++)
			*it = std::toupper(*it);
	return (userInput);
}

int	main(void) {
	PhoneBook	book;
	std::string	userInput;

	std::cout << std::endl << "Welcome to the 1981 Forget-Me-Not(TM) PhoneBook(c)!" << std::endl;
	while (true) {
		std::cout << std::endl << "+---------------- Main Menu ----------------+" << std::endl << std::endl;
		std::cout << "What would you like to do?" << std::endl << "> ";
		userInput = getInput(&book);
		if (userInput == "EXIT")
			break ;
		else if (userInput == "ADD") {
			if (!book.addContact())
				break ;
		}			
		else if (userInput == "SEARCH") {
			if (!book.searchContact())
				break ;
		}
		else {
			std::cout << "Please enter one of the following:" << std::endl;
			std::cout << "\tADD\t: add a contact" << std::endl;
			std::cout << "\tSEARCH\t: search contact list" << std::endl;
			std::cout << "\tEXIT\t: exit the FMN(TM) PhoneBook(c)" << std::endl;
		}
	}
	std::cout << "Thank you for using the Forget-Me-Not(TM) PhoneBook(c). Come again soon!" << std::endl;
	return (0);
}