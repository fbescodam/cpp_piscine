/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:50:32 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 21:00:55 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		set_details(void);
		void		print_details(void);
		void		print_row(size_t index, unsigned int column_width);
		bool		wasModified(void);


	private:
		bool		modified;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_num;
		std::string	darkest_secret;

		bool		set_detail(std::string item_name, std::string* item);
};
