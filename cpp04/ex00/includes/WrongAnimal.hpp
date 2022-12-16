/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:55 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 16:47:58 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_CLASS_H
# define WRONG_ANIMAL_CLASS_H

# include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string const & type);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);

		std::string const &	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
