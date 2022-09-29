/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scalar.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 13:19:52 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 13:53:59 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum literal_e {CHAR_L = 0, INT_L, FLOAT_L, DOUBLE_L};

union input {
	char c;
	int i;
	float f;
	double d;
};