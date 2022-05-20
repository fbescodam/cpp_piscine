/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:55:36 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:52:52 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ScavTrap	freek("Freek");
	ClapTrap	izaak("Izaak");

	freek.guardGate();
	izaak.beRepaired(5);
	freek.attack("Izaak");
	izaak.takeDamage(20);
	return (0);
}
