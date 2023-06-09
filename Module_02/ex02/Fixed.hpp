/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:58 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/09 13:17:54 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8; // the type is defined from the assignment

public:
	/* CONSTRUCTOR - DESTRUCTOR */
	Fixed();	// default
	Fixed( const int n );	// integer as input
	Fixed( const float n );	//float as input
	Fixed( const Fixed &src );	// copy constructor
	~Fixed();	// destructor

	/* OPERATOR OVERLOAD = */
	Fixed& operator=( const Fixed &src );	// operator overload

	/* GETTER - SETTER */
	int		getRawBits( void ) const;	//getter
	void	setRawBits( int const raw );	//setter

	/* CONVERSION */
	float	toFloat( void ) const;
	int		toInt( void ) const;

	/* COMPARISON OPERATORS */
	bool	operator>( const Fixed &rhs ) const ;
	bool	operator<( const Fixed &rhs ) const ;
	bool	operator>=( const Fixed &rhs ) const ;
	bool	operator<=( const Fixed &rhs ) const ;
	bool	operator==( const Fixed &rhs ) const ;
	bool	operator!=( const Fixed &rhs ) const ;

	/* ARITHMETIC OPERATORS */
	Fixed	operator+( const Fixed &rhs ) const ;
	Fixed	operator-( const Fixed &rhs ) const ;
	Fixed	operator*( const Fixed &rhs ) const ;
	Fixed	operator/( const Fixed &rhs ) const ;

	/* INCREMENT - DECREMENT OPERATORS */
	Fixed&	operator++( void ); // prefix
	Fixed	operator++( int ); // postfix
	Fixed&	operator--( void ); // prefix
	Fixed	operator--( int ); // postfix

	/* MAX and MIN */
	/* static member functions:
		generally used for more global operations inside the class and not the
		particular object (don't have the this pointer).
		They even work even if no object of the class is declared.
		Here is a perfect case because it is the comparison of two given objects
	 */
	static Fixed& min( Fixed &a, Fixed &b );
	static const Fixed& min( const Fixed &a, const Fixed &b );
	static Fixed& max( Fixed &a, Fixed &b );
	static const Fixed& max( const Fixed &a, const Fixed &b );
};

	/* OPERATOR << OVERLOAD */
std::ostream & operator<<( std::ostream & o, Fixed const & i );


#endif