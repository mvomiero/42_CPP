/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:49:02 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/12 12:08:26 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <colors.h>
#include <iostream>
#include <vector>
#include <list>

int main(int ac, char** av)
{
	if (ac != 2)
		return EXIT_FAILURE;

	int array[] = { 1, 2, 3, 4, 5 };
	std::cout << BG_BRIGHT_CYAN << "Vector test" << RESET << std::endl;
	try
	{
		std::vector< int > vect( array, array + sizeof( array ) / sizeof( int ) );
		std::vector< int >::const_iterator it = easyfind( vect, atoi( av[1] ) );
		std::cout << "Found " << *it << std::endl;
		//*it = 42; // doesn't compile, you can just read and not write
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << BG_BRIGHT_CYAN << "List test" << RESET << std::endl;
	try
	{
		std::list< int > vect( array, array + sizeof( array ) / sizeof( int ) );
		std::list< int >::const_iterator it = easyfind( vect, atoi( av[1] ) );
		std::cout << "Found " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}