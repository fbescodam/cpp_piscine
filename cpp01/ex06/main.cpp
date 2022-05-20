/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 01:50:48 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 03:53:43 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int		main(int argc, char **argv)
{
	Harl	harl;

	if (argc > 1)
		harl.complain(argv[1]);
	else
		std::cerr << "Error: missing argument" << std::endl;
}
