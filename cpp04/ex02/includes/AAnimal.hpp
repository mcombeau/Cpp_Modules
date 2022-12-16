/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:16:55 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/14 14:18:10 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_H
# define AANIMAL_CLASS_H

# include <string>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const & src);
		// AAnimal(std::string const & type);
		virtual ~AAnimal(void);

		AAnimal &	operator=(AAnimal const & src);

		// std::string const &	getType(void) const;
		virtual void		makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif
