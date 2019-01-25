/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:41 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/24 23:32:12 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
{
	_fixedVal = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int fixed)
{
	_fixedVal = fixed;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float fixed)
{
	_fixedVal = fixed;
	std::cout << "Float constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &instance)
{
	std::cout << "Assignation operator called\n";
	_fixedVal = instance._fixedVal;
	return *this;
}

Fixed::Fixed(Fixed &cpy)
{
	_fixedVal = cpy._fixedVal;
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n";
	return _fixedVal;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	_fixedVal = raw;
}

float	Fixed::toFloat(void) const
{
	bool signedBit = _fixedVal & (1 << 31) ? true : false;
	//build float
	//
	//1 check signed bit
	//
	//2 find exponent
	//
	//3 find midpoint based on exponent
	//
	//8 bits are used for exponent
	unsigned char exponent = (_fixedVal >> 24) - 127;

	
	//23 mentissa bits that are used for actual value
	int mentissa = (_fixedVal & 0x007FFFFF);

	
}

