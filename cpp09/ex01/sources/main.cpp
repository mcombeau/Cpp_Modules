/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:48:56 by mcombeau          #+#    #+#             */
/*   Updated: 2023/04/25 12:48:56 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cerr << RED "Usage: ./RPN [reverse Polish notation expression]" RESET <<
		          std::endl;
		return ( 1 );
	}
	try
	{
		RPN rpn( ( std::string( av[1] ) ) );
		int res = rpn.getResult();
		if ( VERBOSE )
		{
			std::cout << YELLOW << "Result: " RESET;
		}
		std::cout << res << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return ( 0 );
}
