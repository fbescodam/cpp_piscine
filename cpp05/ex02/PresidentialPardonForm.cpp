/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 19:06:38 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// constructors
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: Form("PresidentialPardonForm", 5, 25), target(target)
{
	std::cout << "Constructed PresidentialPardonForm " << *this << std::endl;
}


// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: Form(other), target(other.target)
{
	std::cout << "Copy PresidentialPardonForm by constructor " << *this << std::endl;
}


// copy assignment
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	std::cout << "Copy PresidentialPardonForm by assignment " << *this << std::endl;
	return (*this);
}


// executor
void PresidentialPardonForm::onExecute(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


// destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Deconstructed PresidentialPardonForm " << *this << std::endl;
}
