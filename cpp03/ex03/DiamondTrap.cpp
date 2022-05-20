/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:18 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:45:36 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

// constructors
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	std::cout << "A DiamondTrap with name " << this->name << " has been constructed." << std::endl;
}


// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap with name " << this->name << " has been cloned!?" << std::endl;
}


// copy assignment
DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other)
{
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "DiamondTrap with name " << this->name << " has been cloned?!" << std::endl;
	return (*this);
}


// destructor
DiamondTrap::~DiamondTrap(void)
{
	if (this->hitPoints <= 0)
		std::cout << "DiamondTrap " << this->name << " died." << std::endl;
	else
		std::cout << "DiamondTrap " << this->name << " ran." << std::endl;
}


// public methods
void	DiamondTrap::attack(const std::string& target)
{ this->ScavTrap::attack(target); }

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->name << " wants to share that its ClapTrap name is actually " << this->ClapTrap::name << std::endl;
}
