/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:28:00 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 12:44:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

#include "ClapTrap.hpp"

# define FRAGTRAP_DEFAULT_HIT_POINTS 100
# define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
# define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & src);

		void	highFivesGuys(void);

	private:
		FragTrap(void);
};

#endif