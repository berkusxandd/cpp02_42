/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:32 by bince             #+#    #+#             */
/*   Updated: 2024/11/24 16:52:40 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed &operator = (Fixed const &src);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		int fixedNumber;
		static const int fractionalBits = 8;
};
#endif
