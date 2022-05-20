/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:32:58 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		// constructors
		ScavTrap(void);
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
