/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:36:57 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 12:08:43 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & src);

		void		learnMateria(AMateria * m);
		AMateria *	createMateria(std::string const & type);
		void		displayKnownRecipes(void);

	private:
		static int const	_maxRecipes = 4;
		AMateria *	_recipes[_maxRecipes];

		void	_initializeEmptyRecipes(void);
		void	_deleteRecipes(void);
};

#endif