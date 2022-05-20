/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:55:36 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:46:46 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main(void)
{
	ScavTrap	freek("Freek");
	ClapTrap	izaak("Izaak");
	FragTrap	leon("Leon");
	FragTrap	*leon2;
	DiamondTrap	david("David");

	freek.guardGate();
	izaak.beRepaired(5);
	david.whoAmI();
	leon2 = new FragTrap(leon);
	freek.attack("Izaak");
	izaak.takeDamage(20);
	david.attack("Freek");
	freek.takeDamage(30);
	leon.highFivesGuys();
	leon2->beRepaired(500);
	freek.attack("David");
	david.takeDamage(20);
	david.beRepaired(20);
	delete leon2;
	return (0);
}
