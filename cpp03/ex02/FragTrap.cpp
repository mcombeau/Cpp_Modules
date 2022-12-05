/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:27:48 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/05 11:17:15 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << CYAN "FragTrap default constructor called." RESET << std::endl;
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_maxHitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_maxEnergyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_maxAttackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	return ;
}

FragTrap::FragTrap(std::string & name) : ClapTrap(name) {
	std::cout << CYAN "A FragTrap named \"" << name << "\" was constructed."
		RESET << std::endl;
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_maxHitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_maxEnergyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_maxAttackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap() {
	std::cout << CYAN "FragTrap copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << CYAN "The FragTrap named \"" << this->_name
		<< "\" was destroyed." RESET << std::endl;
	return ;
}

FragTrap &	FragTrap::operator=(FragTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	if (this->_hitPoints == 0)
		std::cout << PURPLE << this->_name
			<< " extends a fingerless hand from its debris for a high-five."
			RESET << std::endl;
	else
		std::cout << PURPLE << this->_name << "jumps around trying to get "
			"someone to high-five it." RESET << std::endl;
	return ;
}
