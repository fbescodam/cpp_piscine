/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:01:56 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/23 17:07:31 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

#define AMOUNT_OF_IDEAS 100

class Brain
{
	public:
		// constructors
		Brain(void);

		// copy constructor
		Brain(const Brain& other);

		// copy assignment operator
		Brain& operator = (const Brain& other);

		// destructor
		~Brain(void);

	private:
		std::string		ideas[AMOUNT_OF_IDEAS];
};
