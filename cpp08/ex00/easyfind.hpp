/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 10:26:23 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/15 11:35:51 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>

template <typename T>
int easyfind(const T& container, const int n)
{
	typename T::const_iterator res = std::find(container.begin(), container.end(), n);
	if (res == container.end())
		throw std::exception();
	return *res;
}
