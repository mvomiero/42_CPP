/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:54 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/15 16:06:01 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ABSTRACT:
	- comparison, arithmetic, increment/decrement operators
	- public overloaded member functions min and max (static)

	* call make test to have just the numeric output
 */

/* NOTE rhs:
	rhs stands for "right-hand side". It's a convention normally used to indicate
	the right side of a comparison or assignment operation.
	ex: x = 5; a > b; --> 5 and b would be the rhs.
 */

int main ( void ) {
	Fixed		a; // default constructor
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) ); // arithmetic operator overload + copy constructor

	std::cout << a << std::endl; // assigned to 0
	std::cout << ++a << std::endl; // increment of 1 of the _rawBit variable.
		// the result you obtain is a weird number 0.0039.. that is because we add 1 to the particular
		// notation of the _rawBits variable
	std::cout << a << std::endl; // to see that the variable hasn't change its value
	std::cout << a++ << std::endl; // the value is still the same
	std::cout << a << std::endl; // now the value has changed (increment was postfix a++)
	std::cout << b << std::endl; // just to see the value of b
	std::cout << Fixed::max( a, b ) << std::endl; // the max value is of course b

	// My own tests for the min and max with or without const
	std::cout << "0 test marco" << std::endl;
	Fixed resultRef = Fixed::min(a, b);
	std::cout << resultRef << std::endl;
	resultRef.setRawBits(1); // you couldn't do the same with the other min fuction, since it retruns a const reference
	std::cout << resultRef << std::endl;
	const Fixed& constResultRef = Fixed::min(a, b);
	std::cout << constResultRef << std::endl;
	//actually doesent crush with /0
	//Fixed const	d( Fixed( 5.05f ) / Fixed( 0 ) );
	//std::cout << d << std::endl; 
	return 0;
}