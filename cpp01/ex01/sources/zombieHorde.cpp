/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:07:05 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/16 16:01:07 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie	*aZombieHorde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		aZombieHorde[i].setName(name);
	}
	return (aZombieHorde);
}