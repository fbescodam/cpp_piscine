/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 22:01:57 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 22:20:33 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*		horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}

int		main(void)
{
	Zombie*		horde;
	int			zombAmount = 6;

	horde = zombieHorde(zombAmount, "Zombo");
	for (int i = 0; i < zombAmount; i++)
		horde[i].announce();
	delete[] horde;
	system("leaks zombies");
}
