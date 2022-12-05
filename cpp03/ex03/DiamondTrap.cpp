/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:20:35 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/05 12:20:22 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define PURPLE "\e[34m"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	std::cout << CYAN "DiamondTrap default constructor called." RESET << std::endl;
	this->_hitPoints = FragTrap::_maxHitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = ScavTrap::_maxEnergyPoints;
	this->_maxEnergyPoints = ScavTrap::_maxEnergyPoints;
	this->_attackDamage = FragTrap::_maxAttackDamage;
	this->_maxAttackDamage = FragTrap::_maxAttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	FragTrap(name + "_frag_name"),
	ScavTrap(name + "_scav_name"),
	_name(name)
{
	std::cout << CYAN "A DiamondTrap named \"" << name << "\" was constructed."
		RESET << std::endl;
	this->_hitPoints = FragTrap::_maxHitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = ScavTrap::_maxEnergyPoints;
	this->_maxEnergyPoints = ScavTrap::_maxEnergyPoints;
	this->_attackDamage = FragTrap::_maxAttackDamage;
	this->_maxAttackDamage = FragTrap::_maxAttackDamage;	
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << CYAN "DiamondTrap copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << CYAN "The DiamondTrap named \"" << this->_name
		<< "\" was destroyed." RESET << std::endl;
	return ;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & src)
{
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_hitPoints == 0)
		std::cout << PURPLE << this->_name
			<< ", grandchild of " << ClapTrap::_name << " rests in pieces." << std::endl;
	else
		std::cout << PURPLE << "I AM " << this->_name
			<< ", GRANDCHILD OF THE MIGHTY " << ClapTrap::_name << "!" << std::endl;
	return ;
}