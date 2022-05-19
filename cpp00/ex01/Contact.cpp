/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:58:08 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 21:20:37 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

static bool is_non_printable_char(char c)
{
	return !(std::isprint(c));
}

static void strip_non_printable_chars(std::string& str)
{
	str.erase(std::remove_if(str.begin(), str.end(), is_non_printable_char), str.end());
}

static std::string truncate(std::string str, size_t width)
{
	if (str.length() > width)
	{
		return (str.substr(0, width - 1) + ".");
	}
	return (str);
}

Contact::Contact(void)
{
	this->modified = false;
}

Contact::~Contact(void)
{

}

bool	Contact::set_detail(std::string item_name, std::string* item)
{
	std::cout << item_name << ": ";
	std::getline(std::cin, *item);
	if (std::cin.eof()) // on EOF (Ctrl + D), exit the program with an error
		exit(1);
	strip_non_printable_chars(*item);
	if ((*item).length() > 0)
		return (true);
	std::cout << "Invalid input" << std::endl;
	return (false);
}

void	Contact::set_details(void)
{
	while (!this->set_detail("FIRST NAME", &this->first_name));
	while (!this->set_detail("LAST NAME", &this->last_name));
	while (!this->set_detail("NICKNAME", &this->nick_name));
	while (!this->set_detail("PHONE NUMBER", &this->phone_num));
	while (!this->set_detail("DARKEST SECRET", &this->darkest_secret));
	this->modified = true;
}

void	Contact::print_details(void)
{
	std::cout << std::setw(16) << "FIRST NAME: " << this->first_name << std::endl;
	std::cout << std::setw(16) << "LAST NAME: " << this->last_name << std::endl;
	std::cout << std::setw(16) << "NICKNAME: " << this->nick_name << std::endl;
	std::cout << std::setw(16) << "PHONE NUMBER: " << this->phone_num << std::endl;
	std::cout << std::setw(16) << "DARKEST SECRET: " << this->darkest_secret << std::endl;
}

void	Contact::print_row(size_t index, unsigned int column_width)
{
	if (!this->modified)
		return;
	std::cout << std::setw(column_width) << index << "|";
	std::cout << std::setw(column_width) << truncate(this->first_name, column_width) << "|";
	std::cout << std::setw(column_width) << truncate(this->last_name, column_width) << "|";
	std::cout << std::setw(column_width) << truncate(this->nick_name, column_width) << std::endl;
}

bool	Contact::wasModified(void)
{
	return (this->modified);
}
