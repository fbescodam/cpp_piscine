/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:41 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 08:16:47 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class WrongAnimal
{
	public:
		// constructors
		WrongAnimal(void);

		// copy constructor
		WrongAnimal(const WrongAnimal& other);

		// copy assignment operator
		WrongAnimal& operator = (const WrongAnimal& other);

		// destructor
		~WrongAnimal(void);

		// public methods
		void				makeSound(void) const;
		const std::string&	getType(void) const;


	protected:
		std::string		type;
};
