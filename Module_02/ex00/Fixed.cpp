/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/15 15:21:31 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* default constructor */
Fixed::Fixed() : _rawBits( 0 ) {	// setting the value to 0
	std::cout << "Default constructor called" << std::endl;
}

/* copy constructor:
	the data is passed and a new object is created */
Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src; // you can directly use the copy assignment operator
	//this->setRawBits(src.getRawBits()); // another way of doing the copy
}

/* destructor */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* returns an object with the same data as src. C++ knows is an operator overload
	because the keyword operator followed by a valid operator (operator=) is given
	as function name. 
		Since it can be a bit confusing, the elemts of the function:
		--> Fixed& -> return type (a reference to the modified object)
		--> Fixed::operator= (name of the function and class)
		--> ( Fixed const & src ) (parameter, another object constant reference)
 */
Fixed& Fixed::operator=( Fixed const & src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_rawBits = src.getRawBits();
	return ( *this );
}

/* getter of the _rawBits member */
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

/* setter of the _rawBits member */
void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}
