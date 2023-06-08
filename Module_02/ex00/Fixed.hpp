/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:58 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/08 10:25:21 by mvomiero         ###   ########.fr       */
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
	Fixed();	// default constructor
	Fixed( const Fixed &src );	// copy constructor
	~Fixed();	// destructor

	Fixed& operator=( const Fixed &src );	// operator overload
	int		getRawBits( void ) const;	//getter
	void	setRawBits( int const raw );	//setter
};

#endif