/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:43:19 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 18:22:16 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int	main(void) {
	std::string trapName0 = "SCVT-2000";
	std::string trapName1 = "CT-42";

	ScavTrap	trap0(trapName0);
	ClapTrap	trap1(trapName1);

	trap1.attack(trapName0);
	trap0.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);
	trap0.attack(trapName1);
	trap1.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
	trap1.beRepaired(5000);
	trap0.guardGate();
	for (int i = 0; i < 50; i++)
		trap0.beRepaired(5000);
	trap0.attack(trapName0);
	trap0.guardGate();
	trap0.takeDamage(5000);
	return (0);
}