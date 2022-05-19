/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 22:01:57 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 22:07:13 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static Zombie*	newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie();
	if (zombie)
		zombie->setName(name);
	return (zombie);
}

static void	randomChump(std::string name)
{
	Zombie	zombie;

	zombie.setName(name);
	zombie.announce();
}

int		main(void)
{
	Zombie	*zombie;

	zombie = newZombie("David");
	zombie->announce();
	delete zombie;

	randomChump("Nicolas");
}
