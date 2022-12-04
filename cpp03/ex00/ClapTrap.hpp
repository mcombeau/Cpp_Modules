/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:42:45 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/04 16:21:36 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>

class ClapTrap
{
	public:
		static unsigned int const	defaultHitPoints = 10;
		static unsigned int const	defaultEnergyPoints = 10;
		static unsigned int const	defaultAttackDamage = 0;

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);
		
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		
		void		attack(std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		ClapTrap(void);
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
