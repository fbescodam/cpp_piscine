/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 18:31:42 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/03 18:53:31 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <array>

template <typename T, size_t N>
void iter(std::array<T, N>* arr, size_t size, void(*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func((*arr).at(i));
}
