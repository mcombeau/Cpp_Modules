/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:17:31 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/17 15:26:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_MATERIA_CLASS_H
# define CURE_MATERIA_CLASS_H

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & src);
		~Cure(void);

		Cure &	operator=(Cure const & src);

		AMateria *	clone(void) const;
		void		use(ICharacter & target);
};

#endif