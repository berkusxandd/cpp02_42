/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:43:35 by bince             #+#    #+#             */
/*   Updated: 2024/11/24 19:12:45 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	//triangle 00
	Point const a(-4,5);
	Point const b(-7,-4);
	Point const c(1,-1);

	//points
	Point const e(-6,4);
	Point const f(-5,2);
	Point const d(-4,1);

	std::cout << bsp(a,b,c,e) << std::endl;
	std::cout << bsp(a,b,c,f) << std::endl;
	std::cout << bsp(a,b,c,d) << std::endl;
}
