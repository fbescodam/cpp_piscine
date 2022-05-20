/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:53:16 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:43:11 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ClapTrap
{
	public:
		// constructors
		ClapTrap(std::string name);

		// copy constructor
		ClapTrap(const ClapTrap& other);

		// copy assignment operator
		ClapTrap& operator = (const ClapTrap& other);

		// destructor
		~ClapTrap(void);

		// public methods
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);


	protected:
		std::string		name;
		int				hitPoints;
		int				energyPoints;
		int				attackDamage;

};
