/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:54 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/09 11:36:26 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ABSTRACT:
	--> function overload: constructors with int or float as input
	--> toFloat() and toInt() functions
	--> << operator overload (in order to print directly)
 */

/* To print _rawBits in binary:
	this two lines allow you to print the raw number in binary. (just replace the b with whatever object name)
	In this way, you can se how the first 8 bits corresponds to the integer part, the others
	the fractional part.

	!!! remember to use the header as well
	#include <bitset>
	std::cout << "Binary power of 2:	7654321001234567" << std::endl;
	std::cout << "Binary representation:	" << std::bitset<16>(b.getRawBits()) << std::endl;
 */

int main(void) {

	Fixed		a; // default constructor
	Fixed const b( 10 ); // int constructor
	Fixed const c( 42.42f ); // float constructor
		// f after the float is a suffix to declare float literals (if not by default converted in double in c++)
	Fixed const d( b ); // copy constructor

	a = Fixed( 1234.4321f ); // operator overload
	// here operator overload, that's why we can use the << with the object and dont need to access the member
	std::cout << "a is " << a << std::endl;	// !!! operator overload -> using "<<" is like using a.toFloat()
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}