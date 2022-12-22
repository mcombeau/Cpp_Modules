/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:32:59 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/21 18:28:10 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

AForm::AForm(void) :_name("Basic Form"),
					_isSigned(false),
					_gradeRequiredToSign(Bureaucrat::lowestGrade),
					_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Form default constructor called." RESET << std::endl;
	return ;
}

AForm::AForm(AForm const & src) :	_name(src._name),
									_isSigned(false),
									_gradeRequiredToSign(src._gradeRequiredToSign),
									_gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << CYAN "Form copy constructor called." RESET << std::endl;
	return ;
}

AForm::AForm(std::string const & name, int const gradeToSign, int const gradeToExecute)
			:	_name(name),
				_isSigned(false),
				_gradeRequiredToSign(gradeToSign),
				_gradeRequiredToExecute(gradeToExecute)
{
	std::cout << CYAN "Form attribute constructor called." RESET << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade )
		throw (AForm::GradeTooHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());
	std::srand(time(0));
	return ;
}

AForm::~AForm(void)
{
	std::cout << CYAN "Form destructor called." RESET << std::endl;
	return ;
}

AForm &	AForm::operator=(AForm const & src)
{
	std::cout << CYAN "Form assignment operator overload called." RESET << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeRequiredToSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int	AForm::getGradeRequiredToExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_isSigned)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
	return ;
}

void	AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (this->_isSigned == false)
		throw (AForm::NotSignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiredToExecute)
		throw (AForm::GradeTooLowException());
	this->beExecuted();
	return ;
}

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed.");
}

std::ostream &	operator<<(std::ostream & os, AForm const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getGradeRequiredToSign()
		<< "; to execute: " << obj.getGradeRequiredToExecute() << ")";
	return (os);
}
