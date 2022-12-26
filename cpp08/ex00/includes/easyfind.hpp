/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:23:44 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/26 14:36:18 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP_H
# define EASYFIND_TPP_H

# include <algorithm>
# include <iterator>
# include <stdexcept>

template <typename T>
typename T::const_iterator	easyfind(T const & container, int const element)
{
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw (std::out_of_range("Element not found in container."));
	return (it);
}

#endif