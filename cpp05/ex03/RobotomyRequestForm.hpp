/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 18:23:38 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	public:
		// constructors
		RobotomyRequestForm(const std::string target);

		// copy constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);

		// copy assignment operator
		RobotomyRequestForm& operator = (const RobotomyRequestForm& other);

		// destructor
		~RobotomyRequestForm(void);

		// executor
		void onExecute(void) const;


	private:
		const std::string	target;
};
