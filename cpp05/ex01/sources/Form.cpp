/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:32:59 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/21 15:03:22 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

Form::Form(void) :	_name("Basic Form"),
					_isSigned(false),
					_gradeRequiredToSign(Bureaucrat::lowestGrade),
					_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Form default constructor called." RESET << std::endl;
	return ;
}

Form::Form(Form const & src) :	_name(src._name),
								_isSigned(false),
								_gradeRequiredToSign(src._gradeRequiredToSign),
								_gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << CYAN "Form copy constructor called." RESET << std::endl;
	return ;
}

Form::Form(std::string const & name, int const gradeToSign, int const gradeToExecute)
			:	_name(name),
				_isSigned(false),
				_gradeRequiredToSign(gradeToSign),
				_gradeRequiredToExecute(gradeToExecute)
{
	std::cout << CYAN "Form attribute constructor called." RESET << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade )
		throw (Form::GradeTooHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());
	return ;
}

Form::~Form(void)
{
	std::cout << CYAN "Form destructor called." RESET << std::endl;
	return ;
}

Form &	Form::operator=(Form const & src)
{
	std::cout << CYAN "Form assignment operator overload called." RESET << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeRequiredToSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int	Form::getGradeRequiredToExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_isSigned)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
	return ;
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

std::ostream &	operator<<(std::ostream & os, Form const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getGradeRequiredToSign()
		<< "; to execute: " << obj.getGradeRequiredToExecute() << ")";
	return (os);
}