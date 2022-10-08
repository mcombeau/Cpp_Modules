/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:11:53 by mcombeau          #+#    #+#             */
/*   Updated: 2022/10/08 13:13:56 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string const msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		std::cout << msg;
	for (int i = 1; av[i]; i++) {
		std::string s(av[i]);
		for (std::string::iterator it = s.begin(); it != s.end(); it++)
			*it = std::toupper(*it);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
