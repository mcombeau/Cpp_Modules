/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:30:37 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/25 14:29:56 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_H
# define ITER_H

# include <cstdlib>
# include <iostream>

template <typename A, typename F>
void	iter(A * array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
	return ;
}

template <typename T>
void	printArray(T * array, size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl;
}

template <typename T>
void	addOne(T & number)
{
	number += 1;
	return ;
}

#endif
