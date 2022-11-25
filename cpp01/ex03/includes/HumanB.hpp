/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:24 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/25 14:24:26 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

# include <string>
# include "Weapon.hpp"

class	HumanB {
	private:
		Weapon				*_weapon;
		std::string const	_name;
	public:
		HumanB(std::string const aName);
		~HumanB(void);

		void	attack(void) const;
		void	setWeapon(Weapon &aWeapon);
};

#endif