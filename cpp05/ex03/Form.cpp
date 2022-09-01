/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/02 14:06:40 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 17:28:27 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// constructors
Form::Form(const std::string name, const unsigned short reqGradeExec, const unsigned short reqGradeSign)
: reqGradeExec(reqGradeExec), reqGradeSign(reqGradeSign), name(name)
{
	this->formSigned = false;
	if (this->reqGradeExec < 1 || this->reqGradeSign < 1)
		throw Form::GradeTooHighException();
	if (this->reqGradeExec > 150 || this->reqGradeSign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Constructed " << *this << std::endl;
}


// copy constructor
Form::Form(const Form& other)
: reqGradeExec(other.reqGradeExec), reqGradeSign(other.reqGradeSign), name(other.name), formSigned(other.formSigned)
{
	std::cout << "Copy by constructor " << *this << std::endl;
}


// copy assignment
Form& Form::operator = (const Form& other)
{
	if (this == &other)
		return (*this);
	this->formSigned = other.formSigned;
	std::cout << "Copy by assignment " << *this << std::endl;
	return (*this);
}


// destructor
Form::~Form(void)
{
	std::cout << "Deconstructed Form " << this->name << std::endl;
}


// exceptions
const char*	Form::GradeTooHighException::what(void) const _NOEXCEPT
{
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what(void) const _NOEXCEPT
{
	return "Grade too low";
}

const char*	Form::NotSignedException::what(void) const _NOEXCEPT
{
	return "Form is not signed";
}


// getters
const std::string Form::getName(void) const
{
	return (this->name);
}

unsigned short Form::getGradeRequiredForExecution(void) const
{
	return (this->reqGradeExec);
}

unsigned short Form::getGradeRequiredForSigning(void) const
{
	return (this->reqGradeSign);
}

bool Form::isSigned(void) const
{
	return (this->formSigned);
}


// modifiers
bool Form::beSigned(const Bureaucrat& brocrat)
{
	if (brocrat.getGrade() > this->reqGradeSign)
		throw Form::GradeTooLowException();
	else if (this->formSigned)
		return (false);
	return (this->formSigned = true);
}


// execution
void Form::execute(const Bureaucrat& brocrat) const
{
	if (brocrat.getGrade() > this->reqGradeExec)
		throw Form::GradeTooLowException();
	else if (!this->formSigned)
		throw Form::NotSignedException();
	this->onExecute();
}


// insertion operator
std::ostream& operator << (std::ostream &out, const Form& form)
{
	out << "Form \"" << form.getName() << "\", signed = " << form.isSigned();
	out << ", required grade for execution " << form.getGradeRequiredForExecution();
	out << ", required grade for signing " << form.getGradeRequiredForSigning();
	return (out);
}
