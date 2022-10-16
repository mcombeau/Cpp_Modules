/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:01:44 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/16 13:39:29 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class	Zombie
{
	private:
		std::string	_name;

		std::string	_getName(void) const;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void		announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif