/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:06 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/25 16:16:46 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

#define RESET "\e[0m"
#define	CYAN "\e[36m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Constructor	*/
HumanB::HumanB(std::string const aName) : _weapon(NULL), _name(aName) {
	std::cout << CYAN
		<< this->_name << " enters the Colosseum with a whimper."
		<< RESET << std::endl;
	return ;
}

/*	Desctructor	*/
HumanB::~HumanB(void) {
	std::cout << CYAN
		<< this->_name << " flees the Colosseum!"
		<< RESET << std::endl;
	return ;
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	HumanB::setWeapon(Weapon &aWeapon) {
	if (aWeapon.getType().empty()) {
		if (this->_weapon == NULL || this->_weapon->getType().empty()) {
			std::cout << GREEN
				<< this->_name << " tries to pick up a weapon but fails!"
				<< RESET << std::endl;
		}
		else {
			std::cout << GREEN
				<< this->_name << " drops their weapon!"
				<< RESET << std::endl;
		}
	}
	else {
		if (this->_weapon == NULL || this->_weapon->getType().empty()) {
			std::cout << GREEN
				<< this->_name << " picks up a " << aWeapon.getType()
				<< RESET << std::endl;
		}
		else {
			std::cout << GREEN
				<< this->_name << " switches to a " << aWeapon.getType()
				<< RESET << std::endl;
		}
	}
	if (aWeapon.getType().empty())
		this->_weapon = NULL;
	else
		this->_weapon = &aWeapon;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	HumanB::attack(void) const {
	std::cout << YELLOW << this->_name << " attacks with their ";
	if (this->_weapon != NULL && this->_weapon->getType() != "")
		std::cout << this->_weapon->getType() << ".";
	else
		std::cout << "bare fists!";	
	std::cout << RESET << std::endl;
	return ;
}
