/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:39 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 08:20:54 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

// constructors
WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "A \"cat\" has been created" << std::endl;
}


// copy constructor
WrongCat::WrongCat(const WrongCat& other)
{
	this->type = other.type;
	std::cout << "A \"cat\" has been copied with a constructor" << std::endl;
}


// copy assignment
WrongCat& WrongCat::operator = (const WrongCat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "A \"cat\" has been copied by assignment" << std::endl;
	return (*this);
}


// destructor
WrongCat::~WrongCat(void)
{
	std::cout << "A \"cat\" has been destroyed" << std::endl;
}
