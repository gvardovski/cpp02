/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:10:59 by svolkau           #+#    #+#             */
/*   Updated: 2026/01/13 14:40:54 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _FixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _FixedPointValue(value << _fractionalBits)
{
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _FixedPointValue((int)roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" <<  std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return this->_FixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
	this->_FixedPointValue = raw;
}

int Fixed::toInt( void ) const
{
	return this->_FixedPointValue >> _fractionalBits;
}

float Fixed::toFloat( void ) const
{
	return (float)this->_FixedPointValue / (1 << _fractionalBits);
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_FixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(Fixed const & rhs) const
{
	if (this->toFloat() > rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const & rhs) const
{
	if (this->toFloat() < rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	if (this->toFloat() >= rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	if (this->toFloat() <= rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const & rhs) const
{
	if (this->toFloat() == rhs.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	if (this->toFloat() != rhs.toFloat())
		return true;
	return false;
}

Fixed & Fixed::operator++()
{
	this->_FixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_FixedPointValue++;
	return temp;
}

Fixed & Fixed::operator--()
{
	this->_FixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_FixedPointValue--;
	return temp;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a >= b)
		return a;
	return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a >= b)
		return a;
	return b;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a <= b)
		return a;
	return b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}