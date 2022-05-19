/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:58:12 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 21:38:43 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->next_add_index = 0;
	this->first_added = false;
}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::print_table_headers(void)
{
	std::cout << std::setw(COLUMN_WIDTH) << "INDEX" << "|";
	std::cout << std::setw(COLUMN_WIDTH) << "FIRST NAME" << "|";
	std::cout << std::setw(COLUMN_WIDTH) << "LAST NAME" << "|";
	std::cout << std::setw(COLUMN_WIDTH) << "NICKNAME" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << std::setfill('-') << std::setw(COLUMN_WIDTH) << "" << (i < 3 ? "+" : "");
	std::cout << std::setfill(' ') << std::endl;
}

void	PhoneBook::cmd_add(void)
{
	this->list[this->next_add_index].set_details();
	this->first_added = true;
	this->next_add_index++;
	if (this->next_add_index > 7)
		this->next_add_index = 0;
}

static bool	is_fully_numeric_string(std::string str)
{
	std::string::const_iterator it = str.begin();
	while (it != str.end())
	{
		if (!std::isdigit(*it))
			return (false);
		it++;
	}
	return (true);
}

static bool	contact_chooser_invalid_index()
{
	std::cout << "Invalid index" << std::endl;
	return (false);
}

bool	PhoneBook::contact_chooser(size_t *index, bool require_mod)
{
	std::string		index_str;

	std::cout << "Choose a contact to display: ";
	std::getline(std::cin, index_str);
	if (std::cin.eof()) // on EOF (Ctrl + D), exit the program with an error
		exit(1);
	if (index_str.length() == 0) // if string is empty, redisplay without showing "invalid index"
		return (false);
	if (!is_fully_numeric_string(index_str)) // invalid index: string contains non-numeric characters
		return (contact_chooser_invalid_index());
	try {
		*index = (size_t) std::stoi(index_str);
	}
	catch ( ... ) {
		return (contact_chooser_invalid_index()); // invalid index: (any) parsing error
	}
	*index -= 1;
	if (*index > 7) // invalid index: out of bounds
		return (contact_chooser_invalid_index());
	if (require_mod && !this->list[*index].wasModified()) // invalid index: contact was not initialized yet
		return (contact_chooser_invalid_index());
	return (true);
}

void	PhoneBook::cmd_search(void)
{
	size_t	index;

	if (!this->first_added)
	{
		std::cout << "No contacts have been saved yet. Try using the ADD command" << std::endl;
		return;
	}
	this->print_table_headers();
	for (size_t i = 0; i < 8; i++) {
		this->list[i].print_row(i + 1, COLUMN_WIDTH);
	}
	while (!contact_chooser(&index, true));
	this->list[index].print_details();
}

int		PhoneBook::cmd_exit(int exit_code)
{
	std::cout << "Goodbye" << std::endl;
	return (exit_code);
}
