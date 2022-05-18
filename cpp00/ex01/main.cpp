/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:49:46 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/18 22:01:30 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string	command;

	std::cout << "Welcome to the Phone Book" << std::endl;
	std::cout << "Enter a command: [ADD, SEARCH, EXIT]" << std::endl;
	while(std::getline(std::cin, command)) {
		if (command == "ADD")
			phonebook.cmdAdd();
		else if (command == "SEARCH")
			phonebook.cmdSearch();
		else if (command == "EXIT")
			phonebook.cmdExit();
		else
			std::cout << "Unknown command" << std::endl;
	}
}
