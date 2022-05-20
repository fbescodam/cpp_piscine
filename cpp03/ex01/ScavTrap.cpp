/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:52:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

// constructors
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "A ScavTrap with name " << this->name << " has been constructed." << std::endl;
}


// copy constructor
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap with name " << this->name << " has been cloned!?" << std::endl;
}


// copy assignment
ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap with name " << this->name << " has been cloned?!" << std::endl;
	return (*this);
}


// destructor
ScavTrap::~ScavTrap(void)
{
	if (this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " died." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " ran." << std::endl;
}


// public methods
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is now guarding the gate (gate keeper mode)." << std::endl;
}
