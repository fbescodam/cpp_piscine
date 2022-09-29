/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scalar.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 13:19:52 by fbes          #+#    #+#                 */
/*   Updated: 2022/09/29 14:41:41 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef enum literal_e {
	CHAR_L = 0,
	INT_L,
	FLOAT_L,
	DOUBLE_L
} literal_t;

typedef union input_u {
	char	c;
	int		i;
	float	f;
	double	d;
} input_t;

typedef struct output_s {
	char	c;
	int		i;
	float	f;
	double	d;
} output_t;