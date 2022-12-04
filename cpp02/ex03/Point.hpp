/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:19:24 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/03 12:41:43 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_H
# define POINT_CLASS_H

# include "Fixed.hpp"

class	Point
{
	public:
		Point( void );
		Point( Fixed const x, Fixed const y );
		Point( Point const & src );
		~Point( void );

		Point & operator=( Point const & src );

		Fixed const &	getX( void ) const;
		Fixed const &	getY( void ) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif