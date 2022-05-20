/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 07:54:41 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 08:17:01 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// constructors
		WrongCat(void);

		// copy constructor
		WrongCat(const WrongCat& other);

		// copy assignment operator
		WrongCat& operator = (const WrongCat& other);

		// destructor
		~WrongCat(void);
};
