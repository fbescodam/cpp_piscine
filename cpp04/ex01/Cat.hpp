/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:41 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:08:54 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		// constructors
		Cat(void);

		// copy constructor
		Cat(const Cat& other);

		// copy assignment operator
		Cat& operator = (const Cat& other);

		// destructor
		~Cat(void);

	private:
		Brain*	brain;
};
