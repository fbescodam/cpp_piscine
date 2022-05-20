/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:31:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		// constructors
		FragTrap(void);
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
