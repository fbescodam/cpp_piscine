/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 22:44:57 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/19 23:16:42 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		std::string&	getType(void);
		void			setType(std::string type);


	private:
		std::string		type;
};
