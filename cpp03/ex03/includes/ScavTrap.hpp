/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:58 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/05 12:07:35 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include "ClapTrap.hpp"

# define SCAVTRAP_DEFAULT_HIT_POINTS 100
# define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
# define SCAVTRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & src);

		void	attack(std::string & target);
		void	guardGate(void);

	protected:
		ScavTrap(void);
};

#endif