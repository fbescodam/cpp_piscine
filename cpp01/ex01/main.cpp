/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 22:01:57 by fbes          #+#    #+#                 */
/*   Updated: 2022/07/02 12:56:41 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	Zombie*		horde;
	int			zombAmount = 6;

	horde = Zombie::zombieHorde(zombAmount, "Zombo");
	for (int i = 0; i < zombAmount; i++)
		horde[i].announce();
	delete[] horde;
	system("leaks zombies");
}
