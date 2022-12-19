/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:03:10 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/19 18:22:06 by mcombeau         ###   ########.fr       */
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

void	createTestBureaucrat(std::string name, int grade)
{
	std::cout << std::endl << "-- Creating bureaucrat named \""
		<< name << "\" with grade " << grade << ":" << std::endl;
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << " successfully created." << std::endl;
		return ;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{

	std::cout << std::endl << "---- TEST BUREAUCRAT DEFAULT CONSTRUCTOR" << std::endl;
	{
		Bureaucrat	bureaucrat;
		std::cout << "Default bureaucrat is: " << bureaucrat << std::endl;
	}

	std::cout << std::endl << "---- TEST BUREAUCRAT NAME/GRADE CONSTRUCTORS" << std::endl;
	createTestBureaucrat("Horace", 20);
	createTestBureaucrat("Anne", 150);
	createTestBureaucrat("Fred", 1);
	createTestBureaucrat("Robert", 0);
	createTestBureaucrat("Michelle", 151);
	createTestBureaucrat("Jacqueline", -10);

	{
		std::cout << std::endl << "---- TEST BUREAUCRAT ASSIGNMENT OPERATOR" << std::endl; 
		Bureaucrat bureaucrat1("Carol", Bureaucrat::lowestGrade);
		Bureaucrat bureaucrat2("George", 42);

		std::cout << "Two bureaucrats created:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;
		
		bureaucrat1 = bureaucrat2;
		std::cout << "First bureaucrat = second bureaucrat:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;
	}
	{
		std::cout << std::endl << "---- TEST BUREAUCRAT GRADE INCREMENT/DECREMENT" << std::endl;
		Bureaucrat bureaucrat("Sam", 2);
		std::cout << "Bureaucrat created:\n"
			"\t" << bureaucrat << std::endl;
		try
		{
			std::cout << "Decrementing grade by 1 -> result should be " << bureaucrat.getGrade() + 1 << ":" << std::endl;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1 << ":" << std::endl;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1 << ":" << std::endl;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1 << ":" << std::endl;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cout << RED "Exception: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cout << RED "Exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "---- TEST BUREAUCRAT GRADE INCREMENT/DECREMENT" << std::endl;
		Bureaucrat bureaucrat("Alex", Bureaucrat::lowestGrade);
		std::cout << "Bureaucrat created:\n"
			"\t" << bureaucrat << std::endl;
		try
		{
			std::cout << "Incrementing grade by 50 -> result should be " << bureaucrat.getGrade() - 50 << ":" << std::endl;
			bureaucrat.incrementGrade(50);
			std::cout << bureaucrat << std::endl;
			std::cout << "Incrementing grade by 42 -> result should be " << bureaucrat.getGrade() - 42 << ":" << std::endl;
			bureaucrat.incrementGrade(42);
			std::cout << bureaucrat << std::endl;
			std::cout << "Decrementing grade by 45 -> result should be " << bureaucrat.getGrade() + 45 << ":" << std::endl;
			bureaucrat.decrementGrade(45);
			std::cout << bureaucrat << std::endl;
			std::cout << "Decrementing grade by 100 -> result should be " << bureaucrat.getGrade() + 100 << ":" << std::endl;
			bureaucrat.decrementGrade(100);
			std::cout << bureaucrat << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cout << RED "Exception: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cout << RED "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
