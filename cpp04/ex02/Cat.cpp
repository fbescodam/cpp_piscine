/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:39 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:38:44 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

// constructors
Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "A cat has been created" << std::endl;
}


// copy constructor
Cat::Cat(const Cat& other)
{
	this->type = other.type;
	std::cout << "A cat has been copied with a constructor" << std::endl;
}


// copy assignment
Cat& Cat::operator = (const Cat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "A cat has been copied by assignment" << std::endl;
	return (*this);
}


// destructor
Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "A cat has been destroyed" << std::endl;
}


// methods
void	Cat::makeSound(void)
{
	std::cout << "MEEEEOOOOOOWWWWW" << std::endl;
}
