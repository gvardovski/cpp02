/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:10:59 by svolkau           #+#    #+#             */
/*   Updated: 2026/01/13 11:18:14 by svolkau          ###   ########.fr       */
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}