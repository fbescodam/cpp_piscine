/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:34:05 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

// constructors
FragTrap::FragTrap(void): ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "A FragTrap with name " << this->name << " has been constructed." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "A FragTrap with name " << this->name << " has been constructed." << std::endl;
}


// copy constructor
FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "FragTrap with name " << this->name << " has been cloned!?" << std::endl;
}


// copy assignment
FragTrap& FragTrap::operator = (const FragTrap& other)
{
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "FragTrap with name " << this->name << " has been cloned?!" << std::endl;
	return (*this);
}


// destructor
FragTrap::~FragTrap(void)
{
	if (this->hitPoints <= 0)
		std::cout << "FragTrap " << this->name << " died." << std::endl;
	else
		std::cout << "FragTrap " << this->name << " ran." << std::endl;
}


// public methods
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requested a high five!" << std::endl;
}
