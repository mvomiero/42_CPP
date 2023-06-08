/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:31:54 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/08 10:28:32 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );	// using the copy constructor, b is exeactly the same as a, even the address
	Fixed c;

	c = b;	// c is a copy of b in its parameters but is another object with different address
			// and not the same address. That is because of the operation overload
	// ? but how does it knows we're inside the class???

	std::cout << a.getRawBits() << std::endl;	// of course the three values are 0
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}