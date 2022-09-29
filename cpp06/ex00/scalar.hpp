/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scalar.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 13:19:52 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 16:12:40 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

// enum that defines the type of the input
typedef enum literal_e {
	CHAR_L = 0,
	INT_L,
	FLOAT_L,
	DOUBLE_L
} literal_t;

// union that holds the input and is readable with any of the specified types
typedef union input_u {
	char	c;
	int		i;
	float	f;
	double	d;
} input_t;

// output that holds all output and booleans that define overflows
typedef struct output_s {
	char	c;
	bool	c_overflows;
	int		i;
	bool	i_overflows;
	float	f;
	double	d;
} output_t;

// conversion functions
void convertChar(const char& c, output_t& out);
void convertInt(const int& i, output_t& out);
void convertFloat(const float& f, output_t& out);
void convertDouble(const double& d, output_t& out);

// type getter
literal_t getLiteralType(const std::string& str);