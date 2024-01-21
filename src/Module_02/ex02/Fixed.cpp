/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/15 15:50:00 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* CONSTRUCTORS */

Fixed::Fixed() : _rawBits( 0 ) {	// setting the value to 0
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _rawBits( n << _fractionalBits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _rawBits( roundf(n * (1 << _fractionalBits)) ) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* DESTRUCTORS */

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* OPERATOR OVERLOAD = */

Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_rawBits = src.getRawBits();
	return ( *this );
}

/* GETTERS AND SETTERS */

int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

/* CONVERSION */

float	Fixed::toFloat( void ) const {
	return ( (float)this->_rawBits / (1 << _fractionalBits) );
}

int	Fixed::toInt( void ) const {
	return this->_rawBits >> _fractionalBits;
}

/* << OPERATOR OVERLOAD */

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}

/* below section added in this exercise compared to ex01 */

/* COMPARISON OPERATORS */

bool	Fixed::operator>( const Fixed &rhs ) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<( const Fixed &rhs ) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=( const Fixed &rhs ) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=( const Fixed &rhs ) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==( const Fixed &rhs ) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=( const Fixed &rhs ) const {
	return this->getRawBits() != rhs.getRawBits();
}

/* ARITHMETIC OPERATORS */

Fixed	Fixed::operator+( const Fixed &rhs ) const {
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed	Fixed::operator-( const Fixed &rhs ) const {
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed	Fixed::operator*( const Fixed &rhs ) const {
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed	Fixed::operator/( const Fixed &rhs ) const {
	return Fixed( this->toFloat() / rhs.toFloat() );
}

/* INCREMENT / DECREMENT OPERATORS */

/* 
	PREFIX:
	increments the value and returns a reference to the same element
	POSTFIX:
	increments the value but returns the copy of the original object (so the increment is done later)
	The int parameter acts as a dummy parameter to differentiate it from the prefix increment operator.
 */

// Prefix ++hello
Fixed &	Fixed::operator++( void ) {
	this->_rawBits += 1;
	
	return ( *this );
}

//postfix hello++
Fixed Fixed::operator++( int ) {
	Fixed	tmp( *this );

	++(*this);
	return ( tmp );
}

// prefix --hello
Fixed &	Fixed::operator--( void ) {
	this->_rawBits -= 1;

	return ( *this );
}

// postfix hello--
Fixed Fixed::operator--( int ) {
	Fixed	tmp( *this );

	--(*this);
	return ( tmp );
}

/* MAX and MIN */

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}
