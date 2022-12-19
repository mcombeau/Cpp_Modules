/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:16:21 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/17 17:52:41 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_CLASS_H
# define ICHARACTER_CLASS_H

# include "AMateria.hpp"
# include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(void) {}

		virtual std::string const & getName(void) const = 0;
		virtual void equip(AMateria * m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif