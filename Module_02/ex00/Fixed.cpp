/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/07 12:47:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// class Fixed
// {
// private:
// 	int					_fixedPointValue;
// 	static const int	_fractionalBits = 8;

// public:
// 	Fixed();
// 	Fixed( const Fixed &rhs );
// 	~Fixed();

// 	Fixed& operator=( const Fixed &rhs );
// 	int		getRawBits( void ) const;
// 	void	setRawBits( int const raw );
// };

Fixed::Fixed() : _fixedPointValue( 0 ) {	// setting the value to 0
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cout << "Copy assignment operator called." << std::endl;
	if ( this != &src )
		this->_fixedPointValue = src.getRawBits();
	return ( *this );
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}
