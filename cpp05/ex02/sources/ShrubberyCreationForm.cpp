/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:04:37 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/22 12:32:29 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

ShrubberyCreationForm::ShrubberyCreationForm(void)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::gradeToSign,
					ShrubberyCreationForm::gradeToExecute),
			_target("Unknown")
{
	std::cout << CYAN "ShrubberyCreationForm default constructor called."
		RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
		:	AForm(src),
			_target(src._target)
{
	std::cout << CYAN "ShrubberyCreationForm copy constructor called."
		RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::gradeToSign,
					ShrubberyCreationForm::gradeToExecute),
			_target(target)
{
	std::cout << CYAN "ShrubberyCreationForm attribute constructor called."
		RESET << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << CYAN "ShrubberyCreationForm destructor called."
		RESET << std::endl;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(
									ShrubberyCreationForm const & src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(),
								std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		if (std::rand() % 2)
			ofs << ShrubberyCreationForm::_shrubbery;
		else
			ofs << ShrubberyCreationForm::_shrubberyAlt;
		std::cout << "A shrubbery has been planted at "
				<< _target << "_shrubbery." << std::endl;
		ofs.close();
	}
	return ;
}

std::string const ShrubberyCreationForm::_shrubbery =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"           ;%%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"            % *%%, ,%%%%*(    '\n"
"          %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";

std::string const	ShrubberyCreationForm::_shrubberyAlt =
"\n"
"           \\/ |    |/\n"
"        \\/ / \\||/  /_/___/_\n"
"         \\/   |/ \\/\n"
"    _\\__\\_\\   |  /_____/_\n"
"           \\  | /          /\n"
"  __ _-----`  |{,-----------~\n"
"            \\ }{\n"
"             }{{\n"
"             }}{\n"
"             {{}\n"
"       , -=-~{ .-^- _\n"
"             `}\n"
"              {\n\n";
