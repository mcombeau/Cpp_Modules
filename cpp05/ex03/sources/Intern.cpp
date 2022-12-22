/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:08:52 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/22 12:17:24 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

Intern::Intern(void)
{
	std::cout << CYAN "Intern default constructor called." RESET << std::endl;
	return ;
}

Intern::Intern(Intern const & src)
{
	std::cout << CYAN "Intern copy constructor called." RESET << std::endl;
	(void)src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << CYAN "Intern desctructor called." RESET << std::endl;
	return ;
}

Intern &	Intern::operator=(Intern const & src)
{
	std::cout << CYAN "Intern assignment operator overload called." RESET << std::endl;
	(void)src;
	return (*this);
}

static AForm *	createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *	createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *	createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name");
}

AForm *	Intern::makeForm(std::string formName, std::string target)
{
	AForm *	formToCreate = NULL;
	static formList const	forms[3] = 
		{
			{"shrubbery creation", createShrubberyCreationForm},
			{"robotomy request", createRobotomyRequestForm},
			{"presidential pardon", createPresidentialPardonForm}
		};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == formName)
		{
			formToCreate = forms[i].function(target);
			std::cout << GREEN "Intern created " << *formToCreate << RESET << std::endl;
			return (formToCreate);
		}
	}
	std::cout << RED "Intern could not create form named \""
		<< formName << "\"" RESET;
	throw Intern::InvalidFormName();
}
