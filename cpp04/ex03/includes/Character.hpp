/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:17:03 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 13:06:47 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
	public:
		Character(void);
		Character(Character const & src);
		Character(std::string const & name);
		~Character(void);

		Character &	operator=(Character const & src);

		std::string const &	getName(void) const;
		void				setName(std::string const & newName);
		void				equip(AMateria * m);
		void				unequip(int	idx);
		void				use(int idx, ICharacter & target);
		void				displayInventory(void) const;

	private:
		static int const	_inventorySize = 4;
		std::string	_name;
		AMateria *	_inventory[_inventorySize];

		void	_initializeEmptyInventory(void);
		void	_deleteInventory(void);
};

#endif