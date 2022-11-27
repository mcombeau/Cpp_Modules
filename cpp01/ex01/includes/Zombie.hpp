/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:06:22 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 15:09:00 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>

class Zombie
{
	private:
		std::string	_name;
		std::string _getName( void ) const;

	public:
		Zombie(void);
		Zombie( std::string name );
		~Zombie();
		void	setName( std::string const name );
		void	announce( void );
};

#endif