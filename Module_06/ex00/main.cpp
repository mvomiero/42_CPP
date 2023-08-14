/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:26 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/14 14:32:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"
#include "ScalarConverter.hpp"

int main( int ac, char ** av )
{
	if ( ac != 2 ) {
		std::cout << "Usage: ./convert number" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		ScalarConverter::convertAndPrint(av[1]);
	}
	catch( const std::exception& e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}