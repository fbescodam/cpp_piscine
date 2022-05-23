/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:41 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:37:42 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal
{
	public:
		// constructors
		Animal(void);

		// copy constructor
		Animal(const Animal& other);

		// copy assignment operator
		Animal& operator = (const Animal& other);

		// destructor
		virtual ~Animal(void);

		// public methods
		virtual void		makeSound(void) = 0;
		const std::string&	getType(void) const;


	protected:
		std::string		type;
};
