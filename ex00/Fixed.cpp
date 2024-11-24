/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:28 by bince             #+#    #+#             */
/*   Updated: 2024/11/24 16:43:29 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
Fixed::Fixed() : fixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
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
