/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:15 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 18:37:43 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// constructors
Bureaucrat::Bureaucrat(std::string name, unsigned short grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}


// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	this->grade = other.grade;
}


// copy assignment
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
}


// destructor
Bureaucrat::~Bureaucrat(void)
{

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

unsigned short&	Bureaucrat::getGrade(void)
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
