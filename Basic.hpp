/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Basic.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 05:56:21 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 05:56:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Basic
{
	public:
		// constructors
		Basic(void);

		// copy constructor
		Basic(const Basic& other);

		// copy assignment operator
		Basic& operator = (const Basic& other);

		// destructor
		~Basic(void);


	private:
};
