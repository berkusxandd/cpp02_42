/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:28 by bince             #+#    #+#             */
/*   Updated: 2024/11/24 19:12:40 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
Fixed::Fixed() : fixedNumber(0)
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::Fixed(const int intVal)
{
	this->fixedNumber = (intVal << fractionalBits);
}
Fixed::Fixed(const float fVal)
{
	this->fixedNumber = roundf(fVal * (1 << fractionalBits));
}

Fixed& Fixed::operator = (Fixed const &src)
{
	if (this != &src)
		this->fixedNumber = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
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

Fixed Fixed::operator+(Fixed const &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(Fixed const &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(Fixed const &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(Fixed const &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

bool Fixed::operator<(Fixed const &src) const
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>(Fixed const &src) const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<=(Fixed const &src) const
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator>=(Fixed const &src) const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator==(Fixed const &src) const
{
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(Fixed const &src) const
{
	return (this->getRawBits() != src.getRawBits());
}

Fixed& Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed const&  Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed& Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (rhs);
	else
		return (lhs);
}

Fixed const&  Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (rhs);
	else
		return (lhs);
}

Fixed &Fixed::operator++()
{
	this->fixedNumber++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedNumber++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->fixedNumber--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedNumber--;
	return tmp;
}

std::ostream& operator<< (std::ostream& out, Fixed const &src)
{
	out << src.toFloat();
	return out;
}
