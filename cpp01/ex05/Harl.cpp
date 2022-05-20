/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 01:49:50 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 02:18:53 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas yo started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*ptr[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr[i])();
			break;
		}
	}
}
