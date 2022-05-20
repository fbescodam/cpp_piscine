/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:49:27 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		// constructors
		DiamondTrap(std::string name);

		// copy constructor
		DiamondTrap(const DiamondTrap& other);

		// copy assignment operator
		DiamondTrap& operator = (const DiamondTrap& other);

		// destructor
		~DiamondTrap(void);

		// public methods
		void	attack(const std::string& target);
		void	whoAmI(void);

		// using
		using FragTrap::hitPoints;
		using ScavTrap::energyPoints;
		using FragTrap::attackDamage;
		using ScavTrap::attack;
	private:
		std::string		name;
};
