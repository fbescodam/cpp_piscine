/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 19:23:39 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"

class Intern
{
	public:
		// constructors
		Intern(void);

		// copy constructor
		Intern(const Intern& other);

		// copy assignment operator
		Intern& operator = (const Intern& other);

		// destructor
		~Intern(void);

		// exceptions
		class UnknownFormException: public std::exception {
			public:
				const char*	what(void) const _NOEXCEPT;
		};

		// functions
		Form* makeForm(const std::string form, const std::string target) const;
	private:
};
