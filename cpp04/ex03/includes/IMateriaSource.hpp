/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:34:30 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/18 18:42:29 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_CLASS_H
# define IMATERIASOURCE_CLASS_H

# include "AMateria.hpp"
# include <string>

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {}

		virtual void		learnMateria(AMateria * m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif