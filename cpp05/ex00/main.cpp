/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:19 by fbes          #+#    #+#                 */
/*   Updated: 2022/07/02 13:32:56 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int		main(void)
{
	Bureaucrat copyFrom("CopyMe", 20);

	try
	{
		std::cout << "Attempt to copy bureaucrat copyFrom to a new bureaucrat" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat(copyFrom);
		brocrat->decrementGrade();
		brocrat->decrementGrade();
		std::cout << "Name: " << brocrat->getName() << ", Grade: " << brocrat->getGrade() << std::endl;
		std::cout << "Attempt to copy bureaucrat copyFrom's details to brocrat" << std::endl;
		*brocrat = copyFrom;
		std::cout << "Name: " << brocrat->getName() << ", Grade: " << brocrat->getGrade() << std::endl;
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception)
	{
		std::cout << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception)
	{
		std::cout << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Attempt to create bureaucrat with level 0" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat("Useless", 0);
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception)
	{
		std::cout << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception)
	{
		std::cout << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Attempt to create bureaucrat with level 240" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat("Big", 240);
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception)
	{
		std::cout << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception)
	{
		std::cout << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Attempt to create bureaucrat with level 10 and increment level 15 times" << std::endl;
		Bureaucrat brocrat("A", 10);
		for (int i = 0; i < 15; i++) {
			brocrat.incrementGrade();
			std::cout << "Bureaucrat " << brocrat.getName() << " reached grade " << brocrat.getGrade() << std::endl;
		}
		std::cout << "Success" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException exception)
	{
		std::cout << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception)
	{
		std::cout << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << "Did you see bureaucrat A getting destructed here without a delete statement? Garbage cleanup on scopes!" << std::endl << std::endl;

	try
	{
		std::cout << "Attempt to create bureaucrat with level 140 and decrement level 15 times" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat("B", 140);
		for (int i = 0; i < 15; i++) {
			brocrat->decrementGrade();
			std::cout << "Bureaucrat " << brocrat->getName() << " reached grade " << brocrat->getGrade() << std::endl;
		}
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception)
	{
		std::cout << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception)
	{
		std::cout << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;
	system("leaks bureaucrats");
}
