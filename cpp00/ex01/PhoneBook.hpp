/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:49:36 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 21:37:25 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

#define COLUMN_WIDTH 10

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		cmd_add(void);
		void		cmd_search(void);
		int			cmd_exit(int exit_code);


	private:
		Contact		list[8];
		bool		first_added;
		int			next_add_index;

		void		print_table_headers(void);
		bool		contact_chooser(size_t *index, bool require_mod = true);
};
