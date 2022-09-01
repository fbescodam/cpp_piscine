/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:15 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 18:57:16 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// constructors
Bureaucrat::Bureaucrat(std::string name, unsigned short grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Create bureaucrat " << this->name << " with grade " << this->grade << std::endl;
}


// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name)
{
	this->grade = other.grade;
	std::cout << "Copy by constructor bureaucrat " << this->name << " with grade " << this->grade << std::endl;
}

// copy assignment
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
	std::cout << "Copy by assignment bureaucrat " << this->name << " with grade " << this->grade << std::endl;
}

// destructor
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructed bureaucrat " << this->name << " with grade " << this->grade << std::endl;
}


// exceptions
const char*	Bureaucrat::GradeTooHighException::what(void) const _NOEXCEPT
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const _NOEXCEPT
{
	return "Grade too low";
}


// getters
const std::string&	Bureaucrat::getName(void) const
{
	return this->name;
}

const unsigned short&	Bureaucrat::getGrade(void) const
{
	return this->grade;
}


// modifiers
unsigned short&	Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return this->grade;
}

unsigned short&	Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return this->grade;
}


// methods
bool Bureaucrat::signForm(Form& form)
{
	try {
		if (!form.beSigned(*this))
		{
			std::cerr << this->name << " couldn't sign form " << form.getName() << " because it is already signed" << std::endl;
			return (false);
		}
		std::cout << this->name << " signed " << form.getName() << std::endl;
		return (true);
	}
	catch (Form::GradeTooLowException exception) {
		std::cerr << this->name << " couldn't sign form " << form.getName() << " because their grade is not higher than or equal to the grade required for signing" << std::endl;
	}
	return (false);
}

bool Bureaucrat::executeForm(const Form& form)
{
	try {
		std::cout << this->name << " executed " << form.getName() << std::endl;
		form.execute(*this);
		return (true);
	}
	catch (Form::NotSignedException exception) {
		std::cerr << this->name << " couldn't execute form " << form.getName() << " because it has not been signed yet" << std::endl;
	}
	catch (Form::GradeTooLowException exception) {
		std::cerr << this->name << " couldn't execute form " << form.getName() << " because their grade is not higher than or equal to the grade required for execution" << std::endl;
	}
	return (false);
}


// insertion operator
std::ostream& operator << (std::ostream &out, const Bureaucrat& brocrat)
{
	out << brocrat.getName() << ", bureaucrat grade " << brocrat.getGrade() << ".";
	return (out);
}
