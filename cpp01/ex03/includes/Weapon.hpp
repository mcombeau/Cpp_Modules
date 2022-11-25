/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:21 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/17 14:52:09 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <string>

class	Weapon {
	private:
		std::string	_type;

	public:
		Weapon(std::string const type);
		~Weapon(void);

		std::string const	&getType(void) const;
		void				setType(std::string const newType);
};

#endif