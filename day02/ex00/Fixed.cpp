/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:41 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/24 18:27:17 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
{
	_fixedVal = 0;
	std::cout << "Default constructor called\n";
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

