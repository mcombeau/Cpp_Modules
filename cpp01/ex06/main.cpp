/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:13:54 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 16:46:47 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main( int ac, char **av )
{
	Harl	grumblerHarl;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl
			<< "Levels are: DEBUG - INFO - WARNING - ERROR" << std::endl;
		return ( 0 );
	}
	grumblerHarl.complain(av[1]);
	return ( 0 );
}
