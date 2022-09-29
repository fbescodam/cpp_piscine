/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 19:09:32 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

// constructors
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: Form("RobotomyRequestForm", 45, 72), target(target)
{
	std::cout << "Constructed RobotomyRequestForm " << *this << std::endl;
}


// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form(other), target(other.target)
{
	std::cout << "Copy RobotomyRequestForm by constructor " << *this << std::endl;
}


// copy assignment
RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	std::cout << "Copy RobotomyRequestForm by assignment " << *this << std::endl;
	return (*this);
}


// executor
void RobotomyRequestForm::onExecute(void) const
{
	std::cout << "DRRRRRRRRRRRRR" << std::endl << "PRRR rdrrrdrrrr DRRRRRRRRRRRRR" << std::endl;
	srand(time(NULL));
	int success = rand() & 1;
	if (success)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy on " << this->target << " has failed" << std::endl;
}


// destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Deconstructed RobotomyRequestForm " << *this << std::endl;
}
