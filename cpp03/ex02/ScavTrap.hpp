/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:51:53 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		// constructors
		ScavTrap(std::string name);

		// copy constructor
		ScavTrap(const ScavTrap& other);

		// copy assignment operator
		ScavTrap& operator = (const ScavTrap& other);

		// destructor
		~ScavTrap(void);

		// public methods
		void	guardGate(void);
	private:
};
