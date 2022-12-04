/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:43:19 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 18:25:35 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int	main(void) {
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);
	scavTrap.attack(clapTrapName);
	clapTrap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
	clapTrap.beRepaired(5000);
	scavTrap.guardGate();
	for (int i = 0; i < 50; i++)
		scavTrap.beRepaired(5000);
	scavTrap.attack(scavTrapName);
	scavTrap.guardGate();
	scavTrap.takeDamage(5000);
	return (0);
}