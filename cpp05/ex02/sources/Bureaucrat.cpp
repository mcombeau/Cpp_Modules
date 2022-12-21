/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:02:50 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/21 17:58:49 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

Bureaucrat::Bureaucrat(void)
		: _name("John Doe"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat default constructor called." RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
		: _name(src._name), _grade(src._grade)
{
	std::cout << CYAN "Bureaucrat copy constructor called." RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat name/grade constructor called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << CYAN "Bureaucrat desctructor called." RESET << std::endl;
	return ;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << CYAN "Bureaucrat assignment operator overload called."
		RESET << std::endl;
	this->_grade = src._grade;
	return (*this);
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->incrementGrade(1);
}

void	Bureaucrat::incrementGrade(int i)
{
	if (this->_grade - i < Bureaucrat::highestGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	else 
	{
		std::cout << GREEN << *this << " was promoted to grade "
			<< this->_grade - i << "!"
			RESET << std::endl;
		this->_grade -= i;
	}
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	this->decrementGrade(1);
}

void	Bureaucrat::decrementGrade(int i)
{
	if (this->_grade + i > Bureaucrat::lowestGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	else
	{
		std::cout << YELLOW << *this << " was demoted to grade "
			<< this->_grade + i << "!"
			RESET << std::endl;
		this->_grade += i;
	}
	return ;
}

void	Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << *this << " signed " << form << RESET << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << RED << *this << " couldn't sign " << form << " because: "
			<< e.what() << RESET << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm(AForm & form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << *this << " executed " << form << RESET << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << RED << *this << " couldn't execute " << form << " because: "
			<< e.what() << RESET << std::endl;
	}
	return ;
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat cannot outrank CEO: grade too low.");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat cannot sink to an intern's level: grade too high.");
}

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & obj)
{
	os << "Bureaucrat \"" << obj.getName()
		<< "\" (grade: " << obj.getGrade() << ")";
	return (os);
}
