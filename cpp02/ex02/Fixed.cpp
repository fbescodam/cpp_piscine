/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 03:18:58 by fbes          #+#    #+#                 */
/*   Updated: 2022/05/20 05:51:04 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// constructors
Fixed::Fixed(void)
{ this->fixed_point_num = 0; }

Fixed::Fixed(const int num)
{ this->fixed_point_num = num << this->num_fract_bits; }

Fixed::Fixed(const float num)
{ this->fixed_point_num = (int)roundf(num * (1 << this->num_fract_bits)); }


// copy constructor
Fixed::Fixed(const Fixed& other)
{ this->fixed_point_num = other.getRawBits(); }


// destructor
Fixed::~Fixed(void)
{
}


// copy assignment operator
Fixed& Fixed::operator= (const Fixed& other)
{
	if (this == &other)
		return (*this);
	this->fixed_point_num = other.getRawBits();
	return (*this);
}


// comparison operators
bool Fixed::operator > (const Fixed& other) const
{ return (this->fixed_point_num > other.getRawBits()); }

bool Fixed::operator >= (const Fixed& other) const
{ return (this->fixed_point_num >= other.getRawBits()); }

bool Fixed::operator < (const Fixed& other) const
{ return (this->fixed_point_num < other.getRawBits()); }

bool Fixed::operator <= (const Fixed& other) const
{ return (this->fixed_point_num <= other.getRawBits()); }

bool Fixed::operator == (const Fixed& other) const
{ return (this->fixed_point_num == other.getRawBits()); }

bool Fixed::operator != (const Fixed& other) const
{ return (this->fixed_point_num != other.getRawBits()); }


// arithmetic operators
Fixed Fixed::operator + (const Fixed& other) const
{
	Fixed	calc;
	calc.setRawBits(this->fixed_point_num + other.getRawBits());
	return (calc);
}

Fixed Fixed::operator - (const Fixed& other) const
{
	Fixed	calc;
	calc.setRawBits(this->fixed_point_num - other.getRawBits());
	return (calc);
}

Fixed Fixed::operator * (const Fixed& other) const
{
	Fixed	calc;
	calc.setRawBits((this->fixed_point_num * other.getRawBits()) >> this->num_fract_bits);
	return (calc);
}

Fixed Fixed::operator / (const Fixed& other) const
{
	Fixed	calc;
	calc.setRawBits((this->fixed_point_num << this->num_fract_bits) / other.getRawBits());
	return (calc);
}


// increment/decrement operators
Fixed& Fixed::operator++(void)
{
	++this->fixed_point_num;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	--this->fixed_point_num;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	calc(*this);
	operator++();
	return (calc);
}

Fixed Fixed::operator--(int)
{
	Fixed	calc(*this);
	operator--();
	return (calc);
}


// static methods
Fixed&			Fixed::min(Fixed &f1, Fixed &f2)
{ return (f1 < f2 ? f1 : f2); }

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2)
{ return (f1 < f2 ? f1 : f2); }

Fixed&			Fixed::max(Fixed &f1, Fixed &f2)
{ return (f1 >= f2 ? f1 : f2); }

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2)
{ return (f1 >= f2 ? f1 : f2); }


// conversions
float	Fixed::toFloat(void) const
{ return ((float)this->fixed_point_num / (1 << this->num_fract_bits)); }

int		Fixed::toInt(void) const
{ return (this->fixed_point_num >> this->num_fract_bits); }


// getters & setters
int	Fixed::getRawBits(void) const
{ return (this->fixed_point_num); }

void	Fixed::setRawBits(const int raw)
{ this->fixed_point_num = raw; }


// insertion operator
std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
