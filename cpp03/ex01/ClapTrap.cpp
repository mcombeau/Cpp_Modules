/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:42:50 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 18:10:30 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"

ClapTrap::ClapTrap(void)
	: _name("Default"),
	_hitPoints(CLAPTRAP_DEFAULT_HIT_POINTS),
	_energyPoints(CLAPTRAP_DEFAULT_ENERGY_POINTS),
	_attackDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE),
	_maxHitPoints(CLAPTRAP_DEFAULT_HIT_POINTS),
	_maxEnergyPoints(CLAPTRAP_DEFAULT_ENERGY_POINTS),
	_maxAttackDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE) {
	std::cerr << CYAN "ClapTrap default constructor called." RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(CLAPTRAP_DEFAULT_HIT_POINTS),
	_energyPoints(CLAPTRAP_DEFAULT_ENERGY_POINTS),
	_attackDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE),
	_maxHitPoints(CLAPTRAP_DEFAULT_HIT_POINTS),
	_maxEnergyPoints(CLAPTRAP_DEFAULT_ENERGY_POINTS),
	_maxAttackDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE) {
	std::cerr << CYAN "A ClapTrap named \"" << name << "\" was constructed." RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cerr << CYAN "ClapTrap copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cerr << CYAN "The ClapTrap named \"" << this->_name << "\" was destroyed." RESET << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void	ClapTrap::attack(std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout << YELLOW "ClapTrap " << this->_name
			<< " can't attack: it is destroyed." RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << YELLOW "ClapTrap " << this->_name
			<< " can't attack: its battery is depleted." RESET
			<< std::endl;
		return ;
	}
	if (target == this->_name)
		target = "itself";
	this->_energyPoints--;
	std::cout << YELLOW "ClapTrap " << this->_name
		<< " attacks " << target << " and hits for " << this->_attackDamage
		<< " damage!" RESET << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << RED << this->_name
			<< " can't take anymore damage: it is already beyond repair!" RESET
			<< std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0) {
		this->_hitPoints = 0;
		std::cout << RED << this->_name
			<< " takes " << amount << " damage and is destroyed!" RESET << std::endl;
	}
	else {
		this->_hitPoints -= amount;
		std::cout << RED << this->_name
			<< " takes " << amount << " damage!" RESET << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << GREEN << this->_name
			<< " can't repair itself: it is too severely damaged." RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << GREEN << this->_name
			<< " can't repair itself: its battery is depleted and needs recharging."
			RESET << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) > this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
	if (amount == 0) {
		this->_energyPoints--;
		std::cout << GREEN << this->_name
			<< " wastes energy trying to repair itself when it is already in tip top shape."
			RESET << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << GREEN << this->_name << " repairs itself for "
		<< amount << "." RESET << std::endl;
	return ;
}
