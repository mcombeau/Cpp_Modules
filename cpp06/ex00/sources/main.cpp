/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/23 16:23:33 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

int	main(int ac, char ** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert_scalar <scalar_to_convert>\n"
			"Valid scalars to convert: int, float, double or char."
			<< std::endl;
		return (1);
	}
	
	try
	{
		std::cout << YELLOW "---- Converting [" << av[1] << "]" RESET << std::endl;
		Converter	scalarConverter(av[1]);
		std::cout << scalarConverter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Input could not be converted: " << e.what() << std::endl;
	}
	return (0);
}
