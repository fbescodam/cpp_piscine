/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:49:36 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/18 21:48:19 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		cmdAdd(void);
		void		cmdSearch(void);
		void		cmdExit(void);


	private:
		Contact		list[8];
		int			last_add_index;
};
