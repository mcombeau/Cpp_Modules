/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:55 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 14:18:10 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

# include <string>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const & src);
		Animal(std::string const & type);
		virtual ~Animal(void);

		Animal &	operator=(Animal const & src);

		std::string const &	getType(void) const;
		virtual void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
