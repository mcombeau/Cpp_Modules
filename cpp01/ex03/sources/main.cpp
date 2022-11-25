/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:14 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/25 16:14:33 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
	Weapon	knife = Weapon("butter knife");
	Weapon	club = Weapon("crude spiked club");
	Weapon	flamethrower = Weapon("flamethrower");
	Weapon	fists = Weapon("");

	std::cout << "\n* WELCOME TO THE COLOSSEUM! *\n" << std::endl;

	HumanA	alice("Alice", club);
	HumanB	bob("Bob");

	std::cout << "\n* 3, 2, 1... FIGHT! *\n" << std::endl;
	
	alice.attack();
	bob.attack();

	bob.setWeapon(knife);
	club.setType("");
	alice.attack();
	bob.attack();

	bob.setWeapon(fists);
	club.setType("whip");
	alice.attack();
	bob.attack();

	bob.setWeapon(flamethrower);
	bob.attack();
	club.setType("butter knife");
	alice.attack();

	std::cout << std::endl;
	return 0;
}