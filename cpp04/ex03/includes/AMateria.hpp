/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:48:25 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 15:02:39 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(AMateria const & src);
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & src);

		std::string const & getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter & target);

	protected:
		std::string	_type;

};

#endif
