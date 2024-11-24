/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:28 by bince             #+#    #+#             */
/*   Updated: 2024/11/24 17:25:32 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
Fixed::Fixed() : fixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int intVal)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedNumber = (intVal << fractionalBits);
}
Fixed::Fixed(const float fVal)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedNumber = roundf(fVal * (1 << fractionalBits));
}

Fixed& Fixed::operator = (Fixed const &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		this->fixedNumber = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}

int Fixed::getRawBits() const
{
	std::cout<< "getRawBits member function called" << std::endl;
	return (this->fixedNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedNumber = raw;
}

int Fixed::toInt() const
{
	return (this->fixedNumber >> fractionalBits);
}
float Fixed::toFloat() const
{
	return ((float)this->fixedNumber / (1 << fractionalBits));
}

std::ostream& operator<< (std::ostream& out, Fixed const &src)
{
	out << src.toFloat();
	return out;
}
