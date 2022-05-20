/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 03:18:54 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 03:46:33 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(Fixed& other);

		int			getRawBits(void) const;
		void		setRawBits(const int raw);


	private:
		int					fixed_point_num;
		static const int	num_fract_bits;
};
