/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:19 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 18:56:06 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat copyFrom("CopyMe", 20);
	std::cout << copyFrom << std::endl;

	try {
		std::cout << "Attempt to copy bureaucrat copyFrom to a new bureaucrat" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat(copyFrom);
		brocrat->decrementGrade();
		brocrat->decrementGrade();
		std::cout << "Name: " << brocrat->getName() << ", Grade: " << brocrat->getGrade() << std::endl;
		std::cout << "Attempt to copy bureaucrat copyFrom's details to brocrat" << std::endl;
		*brocrat = copyFrom;
		std::cout << *brocrat << std::endl;
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception) {
		std::cerr << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception) {
		std::cerr << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Attempt to create bureaucrat with grade 0" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat("Useless", 0);
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception) {
		std::cerr << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception) {
		std::cerr << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Attempt to create bureaucrat with grade 240" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat("Big", 240);
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception) {
		std::cerr << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception) {
		std::cerr << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Attempt to create bureaucrat with grade 10 and increment grade 15 times" << std::endl;
		Bureaucrat brocrat("A", 10);
		for (int i = 0; i < 15; i++) {
			brocrat.incrementGrade();
			std::cout << brocrat << std::endl;
		}
		std::cout << "Success" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException exception) {
		std::cerr << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception) {
		std::cerr << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << "Did you see bureaucrat A getting destructed here without a delete statement? Garbage cleanup on scopes!" << std::endl << std::endl;

	try {
		std::cout << "Attempt to create bureaucrat with grade 140 and decrement grade 15 times" << std::endl;
		Bureaucrat*	brocrat = new Bureaucrat("B", 140);
		for (int i = 0; i < 15; i++) {
			brocrat->decrementGrade();
			std::cout << *brocrat << std::endl;
		}
		std::cout << "Success" << std::endl;
		delete brocrat;
	}
	catch (Bureaucrat::GradeTooHighException exception) {
		std::cerr << "Bureaucrat::GradeTooHighException thrown and catched" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException exception) {
		std::cerr << "Bureaucrat::GradeTooLowException thrown and catched" << std::endl;
	}

	std::cout << std::endl;
	system("leaks bureaucrats");
}
