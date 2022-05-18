/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:58:12 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/18 22:05:10 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->last_add_index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::cmdAdd(void)
{
	this->list[this->last_add_index].setDetails();
	this->last_add_index++;
}

void	PhoneBook::cmdSearch(void)
{

}

void	PhoneBook::cmdExit(void)
{
	std::cout << "Goodbye" << std::endl;
	exit(0);
}
