/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:43:19 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/05 12:26:53 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int	main(void) {
	std::string diamondTrapName = "DT-XXY";
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	DiamondTrap	diamondTrap(diamondTrapName);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	diamondTrap.whoAmI();
	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(clapTrap.getAttackDamage());
	scavTrap.attack(clapTrapName);
	clapTrap.takeDamage(scavTrap.getAttackDamage());
	diamondTrap.attack(scavTrapName);
	scavTrap.takeDamage(diamondTrap.getAttackDamage());
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.takeDamage(5000);
	diamondTrap.beRepaired(5000);
	diamondTrap.whoAmI();
	return (0);
}