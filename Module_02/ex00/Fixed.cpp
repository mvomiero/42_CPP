/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/08 10:23:15 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* default constructor */
Fixed::Fixed() : _rawBits( 0 ) {	// setting the value to 0
	std::cout << "Default constructor called" << std::endl;
}

/* copy constructor:
	the current object is set equal to the src object passed as parameter */
Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* destructor */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* returns an object whose parameter _setPointValue is set equal to the address
	to object src given as parameter
 */
Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cout << "Copy assignment operator called." << std::endl;
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
