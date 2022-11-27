/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 15:12:48 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_CLASS_H
# define HUMAN_A_CLASS_H

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string const	_name;
		Weapon const 		&_weapon;
		
	public:
		HumanA( std::string const aName, Weapon const &aWeapon );
		~HumanA( void );

		void	attack( void ) const;
};

#endif