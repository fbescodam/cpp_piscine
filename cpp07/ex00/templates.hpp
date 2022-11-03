/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   templates.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 18:09:00 by fbes          #+#    #+#                 */
/*   Updated: 2022/11/03 18:25:28 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}
