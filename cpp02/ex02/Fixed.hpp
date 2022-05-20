/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 03:18:54 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 05:50:58 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		// constructors
		Fixed(void);
		Fixed(const int num);
		Fixed(const float fnum);

		// copy constructor
		Fixed(const Fixed& other);

		// copy assignment operator
		Fixed& operator = (const Fixed& other);

		// destructor
		~Fixed(void);

		// comparison operators
		bool operator >  (const Fixed& other) const;
		bool operator <  (const Fixed& other) const;
		bool operator >= (const Fixed& other) const;
		bool operator <= (const Fixed& other) const;
		bool operator == (const Fixed& other) const;
		bool operator != (const Fixed& other) const;

		// arithmetic operators
		Fixed operator + (const Fixed& other) const;
		Fixed operator - (const Fixed& other) const;
		Fixed operator * (const Fixed& other) const;
		Fixed operator / (const Fixed& other) const;

		// increment/decrement operators
		Fixed& operator ++ (void);
		Fixed& operator -- (void);
		Fixed operator ++ (int);
		Fixed operator -- (int);

		// conversion methods
		float		toFloat(void) const;
		int			toInt(void) const;

		// getters & setters
		int			getRawBits(void) const;
		void		setRawBits(const int raw);

		// static methods
		static Fixed&		min(Fixed& f1, Fixed &f2);
		static const Fixed&	min(const Fixed& f1, const Fixed &f2);
		static Fixed&		max(Fixed& f1, Fixed &f2);
		static const Fixed&	max(const Fixed& f1, const Fixed &f2);


	private:
		int					fixed_point_num;
		static const int	num_fract_bits = 8;
};

// insertion operator
std::ostream& operator << (std::ostream& out, const Fixed& fixed);
