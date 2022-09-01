/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/01 17:40:52 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// constructors
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: Form("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Constructed ShrubberyCreationForm " << *this << std::endl;
}


// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: Form(other), target(other.target)
{
	std::cout << "Copy ShrubberyCreationForm by constructor " << *this << std::endl;
}


// copy assignment
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	std::cout << "Copy ShrubberyCreationForm by assingment " << *this << std::endl;
	return (*this);
}


// executor
void ShrubberyCreationForm::onExecute(void) const
{
	std::fstream file;

	file.open(this->target + "_shrubbery", std::fstream::out);
	if (!file.good())
	{
		std::cerr << "Error: could not open file " << this->target << "_shrubbery" << std::endl;
		exit(1);
	}
	for (int i = 0; i < TREES_AMOUNT; i++)
		file << ASCII_TREE << std::endl;
	file.close();
}


// destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Deconstructed ShrubberyCreationForm " << *this << std::endl;
}
