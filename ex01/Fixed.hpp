/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:32 by bince             #+#    #+#             */
/*   Updated: 2024/11/24 17:26:02 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	public:
		Fixed();
		Fixed(const int intVal);
		Fixed(const float fVal);
		Fixed(Fixed const &src);
		Fixed &operator = (Fixed const &src);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
		int toInt() const;
		float toFloat() const;
	private:
		int fixedNumber;
		static const int fractionalBits = 8;
};
std::ostream& operator<< (std::ostream& out, Fixed const &src);
#endif
