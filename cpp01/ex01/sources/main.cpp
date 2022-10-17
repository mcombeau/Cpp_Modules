/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:06:35 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/16 17:49:55 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include "Zombie.hpp"

#define LIMIT_MIN -50000
#define LIMIT_MAX 50000
#define	NC "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

Zombie *zombieHorde(int N, std::string name);

std::string	colorZombieName(std::string const color, std::string const name) {
	std::string	colorName(name);

	colorName.insert(0, color);
	colorName.append(NC);
	return (colorName);
}

int	getNbZombies(void) {
	int	nb;

	std::cout << "Dear necromancer! How many zombies should we raise for our horde today?" << std::endl << "> ";
	while (!(std::cin >> nb) || nb > LIMIT_MAX || nb < LIMIT_MIN) {
		if (std::cin.eof())
			return (0);
		std::cout << "Um... Let's be reasonable here. Why don't you try a number between " << LIMIT_MIN << " and " << LIMIT_MAX << "?" << std::endl
					<< "> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (nb);
}

std::string	getHordeName(void) {
	std::string	name;

	std::cin.ignore();
	std::cout << "Perfect! And what shall this horde be called?" << std::endl << "> ";
	std::getline(std::cin, name);
	if (std::cin.eof()) {
		return (std::string());
	}
	return (name);
}

int	main(void) {
	int			nb;
	std::string name;
	
	nb = getNbZombies();
	name = getHordeName();
	
	std::cout << GREEN << "Attempting to raise the horde \'" << name << "\', of " << nb << " zombies..." << NC << std::endl;
	std::cout << GREEN << "Allocating space for zombies..." << NC << std::endl;
	Zombie	*horde = zombieHorde(nb, colorZombieName(RED, name));
	if (horde == NULL) {
		std::cout << "Your necromancy failed. These corpses will not rise." << std::endl;
		return (1);
	}
	std::cout << GREEN << "Mwahaha we have zombies...!" << NC << std::endl;
	for (int i = 0; i < nb; i++)
		horde[i].announce();
	std::cout << GREEN << "Returning zombies to their graves..." << NC << std::endl;
	delete [] horde;
	return (0);
}