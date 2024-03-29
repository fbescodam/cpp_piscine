/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:47:17 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 11:58:43 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	public:
		// constructors
		Bureaucrat(std::string name, unsigned short grade);

		// copy constructor
		Bureaucrat(const Bureaucrat& other);

		// copy assignment operator
		Bureaucrat& operator = (const Bureaucrat& other);

		// destructor
		~Bureaucrat(void);

		// exceptions
		class GradeTooHighException: public std::exception {
			public:
				const char*	what(void) const _NOEXCEPT;
		};
		class GradeTooLowException: public std::exception {
			public:
				const char*	what(void) const _NOEXCEPT;
		};

		// getters
		const std::string&		getName(void) const;
		const unsigned short&	getGrade(void) const;

		// modifiers
		unsigned short&		incrementGrade(void);
		unsigned short&		decrementGrade(void);

		// functions
		bool				signForm(Form& form);
		bool				executeForm(const Form& form);
		
	private:
		const std::string	name;
		unsigned short		grade;
};

// insertion operator
std::ostream& operator << (std::ostream &out, const Bureaucrat& brocrat);
