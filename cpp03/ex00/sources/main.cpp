/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:43:19 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 18:12:40 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int	main(void) {
	std::string trapName0 = "CT000";
	std::string trapName1 = "CT-42";

	ClapTrap	trap0(trapName0);
	ClapTrap	trap1(trapName1);

	trap0.beRepaired(0);
	for (int i = 0; i < 9; i++) {
		trap0.attack(trapName1);
		trap1.takeDamage(ClapTrap::defaultAttackDamage);
	}
	trap0.attack(trapName1);
	trap1.takeDamage(5);
	trap1.beRepaired(4);
	trap1.attack(trapName0);
	trap0.takeDamage(5);
	trap0.beRepaired(5000);
	trap1.beRepaired(5000);
	trap1.attack(trapName1);
	trap1.takeDamage(5000);
	trap1.beRepaired(5000);
	trap1.takeDamage(1);
	return (0);
}