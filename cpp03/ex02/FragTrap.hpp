/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:56:28 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		// constructors
		FragTrap(std::string name);

		// copy constructor
		FragTrap(const FragTrap& other);

		// copy assignment operator
		FragTrap& operator = (const FragTrap& other);

		// destructor
		~FragTrap(void);

		// public methods
		void	highFivesGuys(void);
	private:
};
