/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:55:36 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 06:17:22 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	freek("Freek");
	ClapTrap	izaak("Izaak");

	freek.beRepaired(5);
	izaak.beRepaired(5);
	freek.attack("Izaak");
	izaak.takeDamage(0);
	izaak.attack("Freek");
	freek.takeDamage(0);
	freek.beRepaired(5);
	izaak.attack("Freek");
	freek.beRepaired(5);
	return (0);
}
