/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:19 by fbes          #+#    #+#                 */
/*   Updated: 2022/07/02 14:59:06 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	Bureaucrat mayor("Mayor", 1);
	Bureaucrat assistant("Assistant", 100);

	std::cout << std::endl;
	try {
		Form veryImportant("Very Important", 1, 1);
		Form notSoImportant("Not So Important", 1, 120);

		std::cout << std::endl;
		assistant.signForm(veryImportant);
		assistant.signForm(notSoImportant);

		std::cout << std::endl;
		mayor.signForm(veryImportant);
		mayor.signForm(notSoImportant);
		mayor.signForm(veryImportant);

		std::cout << std::endl;
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "Form creation failed because " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "Form creation failed because " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form notWorking("Woah It Does Not Work, How Unexpected", 3000, -230);
	}
	catch (Form::GradeTooHighException& e) {
		std::cout << "Form creation failed because " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << "Form creation failed because " << e.what() << std::endl;
	}
}
