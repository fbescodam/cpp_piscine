/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:19 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 19:41:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int		main(void)
{
	Bureaucrat	mayor("Mayor", 1);
	Intern		nobody;
	Form*		form;

	try {
		std::cout << std::endl;
		form = nobody.makeForm("robotomy request", "Freek");
		if (form)
			mayor.signForm(*form);
			mayor.executeForm(*form);
			delete form;

		std::cout << std::endl;
		form = nobody.makeForm("shrubbery request", "street");
		if (form)
			mayor.signForm(*form);
			mayor.executeForm(*form);
			delete form;

		std::cout << std::endl;
		form = nobody.makeForm("presidential pardon request", "Anyone");
		if (form)
			mayor.signForm(*form);
			mayor.executeForm(*form);
			delete form;

		std::cout << std::endl;
		form = nobody.makeForm("food request", "Freek");
		if (form)
			mayor.signForm(*form);
			mayor.executeForm(*form);
			delete form;
	}
	catch (Intern::UnknownFormException) {
		std::cerr << "Unknown form" << std::endl;
	}
}
