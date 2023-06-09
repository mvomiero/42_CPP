/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:58 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/09 11:35:59 by mvomiero         ###   ########.fr       */
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

	/* OPERATOR OVERLOAD */
	Fixed& operator=( const Fixed &src );	// operator overload

	/* GETTER - SETTER */
	int		getRawBits( void ) const;	//getter
	void	setRawBits( int const raw );	//setter

	/* CONVERSION */
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

	/* OPERATOR << OVERLOAD */
std::ostream & operator<<( std::ostream & o, Fixed const & i );


#endif