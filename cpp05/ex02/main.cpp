/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:19 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 11:57:38 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat mayor("Mayor", 1);
	Bureaucrat assistant("Assistant", 64);
	std::cout << std::endl;

	ShrubberyCreationForm shrub("home");
	mayor.executeForm(shrub);
	if (assistant.signForm(shrub))
		assistant.executeForm(shrub);
	std::cout << std::endl;

	RobotomyRequestForm robot("Freek");
	assistant.signForm(robot);
	mayor.executeForm(robot);
	std::cout << std::endl;

	PresidentialPardonForm pardon("Zaphod Beeblebrox");
	mayor.signForm(pardon);
	assistant.executeForm(pardon);
	mayor.executeForm(pardon);
	std::cout << std::endl;

	// copy by constructor
	PresidentialPardonForm copiedPardon(pardon);
	assistant.executeForm(copiedPardon);
	assistant.signForm(copiedPardon);
	assistant.executeForm(copiedPardon);
	std::cout << std::endl;

	// copy by assignment
	PresidentialPardonForm finalPardon("The Evaluator");
	finalPardon = pardon;
	mayor.signForm(finalPardon);
	mayor.executeForm(finalPardon);
	std::cout << std::endl;
}
