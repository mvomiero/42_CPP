/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:54 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/09 18:15:52 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ABSTRACT:
	Practical case for how to use the Fixed class and methods of the previous exercises
	in order to determine if a given point is part of a traingle (vertexes and edges excluded).
	Formula comes from algebra and adapted to code.
 */

/* just to print out the values and if the expected value corresponds to the one we get */
void	printIsBsp(Point const a, Point const b, Point const c, Point const p, bool expected )
{
	std::cerr << "-- Triangle: A(" << a.getX() << ", " << a.getY() << ") "
		<< "B(" << b.getX() << ", " << b.getY() << ") "
		<< "C(" << c.getX() << ", " << c.getY() << ")" << std::endl
		<< "-- Point: P(" << p.getX() << ", " << p.getY() << ")" << std::endl;
	std::cout << "Point inside triangle? ";
	if (bsp(a, b, c, p) == true)
		std::cout <<  "yesssa!" ;
	else
		std::cout <<  "NO." ;
	std::cout << " (Expected ";
	if (expected == true)
		std::cout << "yesssa!";
	else
		std::cout << "NO";
	std::cout << ")" << std::endl << std::endl;
	return ;
}

int main ( void ) {

	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(3, 6);
	Point d; // just to try out the operator overload (works), used in case 4
	d = a;

	// four test cases:
	std::cout << "CASE 1: point inside triangle:" << std::endl;
	printIsBsp(a, b, c, Point (3, 1), true);
	std::cout << "CASE 2: point outside triangle:" << std::endl;
	printIsBsp(a, b, c, Point (8, 8), false);
	std::cout << "CASE 3: point on edge:" << std::endl;
	printIsBsp(a, b, c, Point (3, 0), false);
	std::cout << "CASE 4: point on vertex:" << std::endl;
	printIsBsp(a, b, c, d, false);

	return (0);
}