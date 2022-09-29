/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 19:27:51 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// constructors
Intern::Intern(void)
{
	std::cout << "Constructed intern" << std::endl;
}


// copy constructor
Intern::Intern(const Intern& other)
{
	if (sizeof(other)) // gotta use the variable otherwise the compiler complains on -wextra
	std::cout << "Copy intern by constructor (although there is nothing to copy)" << std::endl;
}


// copy assignment
Intern& Intern::operator = (const Intern& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Copy intern by assignment (although there is nothing to copy)" << std::endl;
	return (*this);
}


// destructor
Intern::~Intern(void)
{
	std::cout << "Deconstructed intern" << std::endl;
}


// exceptions
const char*	Intern::UnknownFormException::what(void) const _NOEXCEPT
{
	return "Unknown form (will the intern lose their job?)";
}


// functions
Form* Intern::makeForm(const std::string form, const std::string target) const
{
	static std::string	knownForms[] = { "robotomy request", "presidential pardon request", "shrubbery request" };
	size_t				i;

	for (i = 0; i < knownForms->length() + 1; i++)
		if (knownForms[i] == form)
			break;

	switch (i) {
		case 0:
			return (new RobotomyRequestForm(target));
		case 1:
			return (new PresidentialPardonForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw UnknownFormException();
	}
}
