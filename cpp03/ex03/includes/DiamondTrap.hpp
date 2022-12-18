/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:20:46 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 12:45:12 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		DiamondTrap &	operator=(DiamondTrap const & src);

		using	ScavTrap::attack;

		void	whoAmI(void);

	protected:
		DiamondTrap(void);
	
	private:
		std::string	_name;
};

#endif
