/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:55:36 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 07:03:12 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ScavTrap	freek("Freek");
	ClapTrap	izaak("Izaak");
	FragTrap	leon("Leon");
	FragTrap	*leon2;

	freek.guardGate();
	izaak.beRepaired(5);
	leon2 = new FragTrap(leon);
	freek.attack("Izaak");
	izaak.takeDamage(20);
	leon.highFivesGuys();
	leon2->beRepaired(500);
	delete leon2;
	return (0);
}
