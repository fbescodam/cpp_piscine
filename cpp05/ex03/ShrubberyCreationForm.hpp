/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 17:39:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"

#define ASCII_TREE "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n\
{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n\
_- -   | | _- _\n  _ -  | |   -_\n      // \\\\"
#define TREES_AMOUNT 4

class ShrubberyCreationForm: public Form
{
	public:
		// constructors
		ShrubberyCreationForm(const std::string target);

		// copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);

		// copy assignment operator
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& other);

		// destructor
		~ShrubberyCreationForm(void);

		// executor
		void onExecute(void) const;


	private:
		const std::string	target;
};
