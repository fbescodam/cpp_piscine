/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 01:50:48 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 02:27:41 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int		main(void)
{
	Harl	harl;

	std::cout << "Debug and above" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "Info and above" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "Warning and above" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "Error and above" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << "Info and above" << std::endl;
	harl.complain("INFO");
}
