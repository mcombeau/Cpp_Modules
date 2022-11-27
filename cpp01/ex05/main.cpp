/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:13:54 by mcombeau          #+#    #+#             */
/*   Updated: 2022/11/27 16:18:53 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl	grumblerHarl;

	grumblerHarl.complain("DEBUG");
	grumblerHarl.complain("ERROR");
	grumblerHarl.complain("INFO");
	grumblerHarl.complain("WARNING");
	grumblerHarl.complain("BAD_JOKES");
	return ( 0 );
}