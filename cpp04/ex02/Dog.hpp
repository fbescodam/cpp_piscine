/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:41 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:38:04 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		// constructors
		Dog(void);

		// copy constructor
		Dog(const Dog& other);

		// copy assignment operator
		Dog& operator = (const Dog& other);

		// destructor
		~Dog(void);

		// methods
		void	makeSound(void);

	private:
		Brain*	brain;
};
