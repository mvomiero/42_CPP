/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:26 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/06 18:33:30 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"
#include "ScalarConverter.hpp"

/* ABSTRACT:
	creating a converter that converts a string input to char, int, float or double.
	It uses a convert method of a static class (not really existing in cpp, 
	but interpreted as a class whose functions are declared static and therefore 
	is not instantiable.
	-- My solution: ScalarConverter instantiates a Converter object that does all the
	operations.

	Converter:
	1. performs some checks on the input string to determine what is the type
	2. Checks if the type is convertible to the datatype, otherwise will be set 
		as "impossible"
	3. Converts thanks to the different data types thanks to static_cast
	4. Prints the different types
 */

/* STATIC CAST:
	static cast is made at compile time. It is considered one of the safest since 
	there are quite some checks and an error in casting would result in a compile 
	error. 
	Usage:
		int numInt = 42;
		double numDouble = static_cast<double>(numInt);
 */

int main( int ac, char ** av )
{
	if ( ac != 2 ) {
		std::cout << "Usage: ./convert number" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		ScalarConverter::convert(av[1]); // Static class -> no need to instantiate an object
	} catch( const std::exception& e ) {
		std::cerr << "Error: " << e.what() << std::endl; // to get the custom exception "Unknown type"
	}

	return EXIT_SUCCESS;
}