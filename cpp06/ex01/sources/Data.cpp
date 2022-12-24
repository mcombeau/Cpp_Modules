/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:02:35 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/24 12:22:13 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

uintptr_t	serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream &	operator<<(std::ostream & os, const Data & obj)
{
	os << "Data structure stored at address [" << &obj << "]"
		<< "\n\t- value : " << obj.value
		<< "\n\t- string: " << obj.string << std::endl;
	return (os);
}