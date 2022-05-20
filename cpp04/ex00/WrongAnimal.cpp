/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:39 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 08:18:59 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

// constructors
WrongAnimal::WrongAnimal(void)
{
	std::cout << "An animal has been created" << std::endl;
}


// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "An animal has been copied with a constructor" << std::endl;
}


// copy assignment
WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "An animal has been copied by assignment" << std::endl;
	return (*this);
}


// destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "An animal has been destroyed" << std::endl;
}


// public methods
void	WrongAnimal::makeSound(void) const
{
	std::string		types[] = { "WrongCat", "WrongDog" };
	int				i;
	int				types_amount = sizeof(types) / sizeof(*types);

	for (i = 0; i < types_amount + 1; i++)
		if (i == types_amount || types[i] == this->type)
			break;

	switch (i)
	{
		case 0:
			std::cout << "Mooooooooooooo" << std::endl;
			break;
		case 1:
			std::cout << "Why did I have to copy this class and spend 10 minutes of my life in agony (this is the sound a human makes)" << std::endl;
			break;
	}
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->type);
}
