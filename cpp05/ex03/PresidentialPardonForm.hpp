/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 18:42:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
		// constructors
		PresidentialPardonForm(const std::string target);

		// copy constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);

		// copy assignment operator
		PresidentialPardonForm& operator = (const PresidentialPardonForm& other);

		// destructor
		~PresidentialPardonForm(void);

		// executor
		void onExecute(void) const;


	private:
		const std::string	target;
};
