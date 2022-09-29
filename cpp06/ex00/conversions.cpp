/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 16:06:27 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 16:07:05 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "scalar.hpp"

void convertChar(const char& c, output_t& out)
{
	out.c = c;
	out.c_overflows = false;
	out.i = static_cast<int>(c);
	out.i_overflows = false;
	out.f = static_cast<float>(c);
	out.d = static_cast<double>(c);
}

void convertInt(const int& i, output_t& out)
{
	out.c = static_cast<char>(i);
	out.c_overflows = (i < CHAR_MIN || i > CHAR_MAX);
	out.i = i;
	out.i_overflows = false;
	out.f = static_cast<float>(i);
	out.d = static_cast<double>(i);
}

void convertFloat(const float& f, output_t& out)
{
	out.c = static_cast<char>(f);
	out.c_overflows = (f < CHAR_MIN || f > CHAR_MAX);
	out.i = static_cast<int>(f);
	out.i_overflows = (f < INT_MIN || f > INT_MAX);
	out.f = f;
	out.d = static_cast<double>(f);
}

void convertDouble(const double& d, output_t& out)
{
	out.c = static_cast<char>(d);
	out.c_overflows = (d < CHAR_MIN || d > CHAR_MAX);
	out.i = static_cast<int>(d);
	out.i_overflows = (d < INT_MIN || d > INT_MAX);
	out.f = static_cast<float>(d);
	out.d = d;
}