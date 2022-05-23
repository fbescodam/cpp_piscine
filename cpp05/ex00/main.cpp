/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:19 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 18:38:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int		main(void)
{
	try
	{
		Bureaucrat*	brocrat = new Bureaucrat("Bro", 0);
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

	try
	{
		Bureaucrat*	brocrat = new Bureaucrat("Bro", 240);
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

	try
	{
		Bureaucrat*	brocrat = new Bureaucrat("Bro", 10);
		for (int i = 0; i < 15; i++) {
			brocrat->incrementGrade();
			std::cout << "Bureaucrat " << brocrat->getName() << " reached grade " << brocrat->getGrade() << std::endl;
		}
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

	try
	{
		Bureaucrat*	brocrat = new Bureaucrat("Bro", 140);
		for (int i = 0; i < 15; i++) {
			brocrat->decrementGrade();
			std::cout << "Bureaucrat " << brocrat->getName() << " reached grade " << brocrat->getGrade() << std::endl;
		}
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
}
