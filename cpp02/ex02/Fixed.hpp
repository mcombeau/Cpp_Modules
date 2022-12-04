/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:05 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/03 11:40:46 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( int const n );
		Fixed( float const f );
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);

		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		Fixed &	operator++( void );
		Fixed	operator++( int	);
		Fixed &	operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed &			min( Fixed & lhs, Fixed & rhs );
		static Fixed &			max( Fixed & lhs, Fixed & rhs );
		static Fixed const &	min( Fixed const & lhs, Fixed const & rhs );
		static Fixed const &	max( Fixed const & lhs, Fixed const & rhs );

	private:
		int					_raw;
		static const int	_fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & os, const Fixed & number );

#endif