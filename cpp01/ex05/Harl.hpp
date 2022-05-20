/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 01:49:52 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 02:14:46 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Harl
{
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);


	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};
