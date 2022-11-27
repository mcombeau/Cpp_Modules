/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:13:51 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 15:24:04 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>

class Harl
{
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );

	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level );
};

#endif