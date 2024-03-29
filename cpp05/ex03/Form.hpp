/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/02 14:06:42 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 19:40:26 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		// constructors
		Form(const std::string name, const unsigned short reqGradeExec, const unsigned short reqGradeSign);

		// copy constructor
		Form(const Form& other);

		// copy assignment operator
		Form& operator = (const Form& other);

		// destructor
		virtual ~Form(void);

		// exceptions
		class GradeTooHighException: public std::exception {
			public:
				const char*	what(void) const _NOEXCEPT;
		};
		class GradeTooLowException: public std::exception {
			public:
				const char*	what(void) const _NOEXCEPT;
		};
		class NotSignedException: public std::exception {
			public:
				const char*	what(void) const _NOEXCEPT;
		};

		// getters
		unsigned short		getGradeRequiredForExecution(void) const;
		unsigned short		getGradeRequiredForSigning(void) const;
		const std::string	getName() const;
		bool				isSigned() const;

		// modifiers
		bool				beSigned(const Bureaucrat& brocrat);

		// execution
		void				execute(const Bureaucrat& executor) const;
		// above is the same as execute(Bureaucrat const& executor) const;
		virtual void		onExecute(void) const = 0;

	private:
		const unsigned short	reqGradeExec;
		const unsigned short	reqGradeSign;
		const std::string		name;
		bool					formSigned;
};

// insertion operator
std::ostream& operator << (std::ostream &out, const Form& form);
