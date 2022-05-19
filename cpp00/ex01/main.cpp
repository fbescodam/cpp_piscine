/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:49:46 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 21:03:13 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

int	main(void)
{
	PhoneBook phonebook;
	std::string	command;

	std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
	std::cout << "Available commands: [ADD, SEARCH, EXIT]" << std::endl;
	std::cout << "@ ";
	while(std::getline(std::cin, command)) {
		if (command == "ADD")
			phonebook.cmd_add();
		else if (command == "SEARCH")
			phonebook.cmd_search();
		else if (command == "EXIT")
			return (phonebook.cmd_exit(0));
		else if (command.length() > 0)
			std::cout << "Unknown command" << std::endl;
		std::cout << "@ ";
	}
}
