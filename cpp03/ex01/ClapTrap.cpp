/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:50:37 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

// constructors
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "A ClapTrap with name " << this->name << " has been constructed." << std::endl;
}


// copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ClapTrap with name " << this->name << " has been cloned!?" << std::endl;
}


// copy assignment
ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ClapTrap with name " << this->name << " has been cloned!?" << std::endl;
	return (*this);
}


// destructor
ClapTrap::~ClapTrap(void)
{
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " died." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " ran." << std::endl;
}


// public methods
void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		return;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		return;
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " was repaired by " << amount << " points, now has " << this->hitPoints << " hitpoints." << std::endl;
}
