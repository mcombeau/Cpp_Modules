/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:31:59 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/21 17:53:30 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_CLASS_H
# define AFORM_CLASS_H

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(AForm const & src);
		AForm(std::string const & name, int const gradeToSign, int const gradeToExecute);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & src);

		std::string const &	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeRequiredToSign(void) const;
		int					getGradeRequiredToExecute(void) const;

		void	beSigned(Bureaucrat const & bureaucrat);
		void	execute(Bureaucrat const & bureaucrat) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	protected:
		virtual void	beExecuted(void) const = 0;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeRequiredToSign;
		int const			_gradeRequiredToExecute;
};

std::ostream &	operator<<(std::ostream & os, AForm const & obj);

#endif