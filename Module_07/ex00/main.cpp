/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:19:03 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/10 12:31:11 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

/* ABSTRACT:
	using function templates to implement min, max and swap functions
 */

/* TEMPLATES:
	templates are used in c++ to create data structures and algorithms that can
	be used with various data types.
	the syntax starts with the line "template <typename T>", where T is convention
	but could be anything, and is the datatype that is going to be used along all the 
	function.
 */

int main( void )
{
	int a = 2;
	int b = 3;

	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "before swap: " "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "after swap: " "c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;

	return 0;
}