/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:15:31 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/24 17:38:43 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
	return ;
}

template <typename T>
T const & max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
T const & min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
void	printValues(T const &a, T const &b)
{
	std::cout << "a = " << a << ", b = " << b;
	return ;
}

#endif