/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 21:52:58 by fbes          #+#    #+#                 */
/*   Updated: 2022/07/02 12:56:24 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void			announce(void);
		void			setName(std::string name);
		static Zombie*	zombieHorde(int N, std::string name);


	private:
		std::string		name;
};
