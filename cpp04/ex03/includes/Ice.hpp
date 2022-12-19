/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:56:33 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/17 15:26:58 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_MATERIA_CLASS_H
# define ICE_MATERIA_CLASS_H

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		~Ice(void);

		Ice	&	operator=(Ice const & src);

		AMateria *	clone(void) const;
		void		use(ICharacter & target);
};

#endif