/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/15 15:31:35 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* default constructor */
Fixed::Fixed() : _rawBits( 0 ) {	// setting the value to 0
	std::cout << "Default constructor called" << std::endl;
}

/* constructor with int as input:
	the formula "n << _fractionalBits" explained:
	by shifting the bits of the fractional part, we get the integer part
	--> ex. with n = 3, _fratcionalBits = 8
	--> _rawBits(3 << 8) = 3 * 2^8 = 3 * 256 = 768
	--> 768 is the value of _rawBits
	to get then the value of the fixed point, the raw value is divided by the scaling
	factor, which is 2^8 = 256. 
	So the result is 768 / 256 = 3
*/
Fixed::Fixed( const int n ) : _rawBits( n << _fractionalBits ) {
	std::cout << "Int constructor called" << std::endl;
}

/* constructor with float as input:
	the formula "roundf(n * (1 << _fractionalBits))" explained: 
	-> 1 << _fractionalBits --> scaling factor
	-> multipies the scaling factor for the float value, getting a value you can assign to _rawBits
	-> rounds the value
 */
Fixed::Fixed( const float n ) : _rawBits( roundf(n * (1 << _fractionalBits)) ) {
	std::cout << "Float constructor called" << std::endl;
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

/* copy assignment operator*/
Fixed&	Fixed::operator=( Fixed const & src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_rawBits = src.getRawBits();
	return ( *this );
}

/* getter of the _rawBits member */
int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

/* setter of the _rawBits member */
void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

/* dividing the _rawBits by the scalinig factor
	so in this case (_fractionalBits = 8) --> 1 << 8 = 1 * 2^8 = 256
 */
float	Fixed::toFloat( void ) const {
	return ( (float)this->_rawBits / (1 << _fractionalBits) );
}

/* does a shifting to the right get just the integer part of the number stored */
int	Fixed::toInt( void ) const {
	return this->_rawBits >> _fractionalBits;
}

/* so anytime we have the operator << followed by a Fixed object,
	it will be expanded to << i.toFloat()
	-- the operator << is actually stored in ostrem, not in cout(which is just pointing to the stream output)
 */
std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}
