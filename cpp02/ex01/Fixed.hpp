/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 03:18:54 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 04:25:37 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float fnum);
		Fixed(const Fixed& other);
		~Fixed(void);
		Fixed& operator = (const Fixed& other);

		int			getRawBits(void) const;
		void		setRawBits(const int raw);
		float		toFloat(void) const;
		int			toInt(void) const;


	private:
		int					fixed_point_num;
		static const int	num_fract_bits = 8;
};

std::ostream& operator << (std::ostream& out, const Fixed& fixed);
