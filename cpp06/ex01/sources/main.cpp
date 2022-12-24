/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/24 12:36:03 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data	data = {.value = 12345, .string = "Hello World!"};
	uintptr_t	serializedPointerAsInt = serialize(&data);
	Data *		deserializedPointer = deserialize(serializedPointerAsInt);

	if (deserializedPointer == &data)
		std::cout << GREEN "Successful serialization and deserialization." RESET
			<< std::endl << std::endl;
	else
		std::cout << RED "Failed serialization and deserialization: " RESET
			<< std::endl << std::endl;
	std::cout << "Original " << data << std::endl;
	std::cout << "Pointer to data structure serialized as int: "
		<< serializedPointerAsInt << std::endl << std::endl;
	std::cout << "Deserialized " << *deserializedPointer << std::endl;
	return (0);
}
