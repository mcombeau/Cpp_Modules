/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:05:44 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/22 12:35:00 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"


RobotomyRequestForm::RobotomyRequestForm(void)
		:	AForm("Robotomy Request Form",
					RobotomyRequestForm::gradeToSign,
					RobotomyRequestForm::gradeToExecute),
			_target("Unknown")
{
	std::cout << CYAN "RobotomyRequestForm default constructor called."
		RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
		:	AForm(src),
			_target(src._target)
{
	std::cout << CYAN "RobotomyRequestForm copy constructor called."
		RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
		:	AForm("Robotomy Request Form",
					RobotomyRequestForm::gradeToSign,
					RobotomyRequestForm::gradeToExecute),
			_target(target)
{
	std::cout << CYAN "RobotomyRequestForm attribute constructor called."
		RESET << std::endl;
	if (_target.empty())
		_target = "Unknown";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << CYAN "RobotomyRequestForm destructor called."
		RESET << std::endl;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(
									RobotomyRequestForm const & src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "* kzzzzt... drilling noises... bip bip bip... clang! *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << "Oh no! " << this->_target << " resisted robotomization..." << std::endl;
	return ;
}
