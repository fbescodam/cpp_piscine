/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 21:53:04 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 22:07:42 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name << " was destroyed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
