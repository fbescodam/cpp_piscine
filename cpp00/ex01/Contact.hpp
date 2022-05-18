/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 19:50:32 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/18 21:48:04 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		setDetails(void);
		void		printDetails(void);


	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_num;
		std::string	darkest_secret;
};
