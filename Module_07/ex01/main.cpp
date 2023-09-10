/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:06:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/10 13:55:43 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "colors.h"
#define SIZE 4

/* ABSTRACT:
	using function templates to apply the same function to all the elements of an
	array. 
	The tests in the main show that the template is very versatile, you can use it 
	for example for int, char, double, std::string.
	The functions to apply, developed by me are a print and an increment one. 
	The increment is not suitable for all the datatypes (doesen't work with strings,
	you get a compilation error).
 */

int	main( void ) {

	int numbers[] = { 1, 2, 3, 4 };
	std::cout << BLUE "numbers:" RESET << std::endl;
	iter(numbers, SIZE, &print);
	std::cout << BLUE "numbers increment:" RESET << std::endl;
	iter(numbers, SIZE, &increment);
	iter(numbers, SIZE, &print);

	double fractionals[] = { 1.2, 2.3, 3.4, 4.5 };
	std::cout << BLUE "fractionals:" RESET << std::endl;
	iter(fractionals, SIZE, &print);
	std::cout << BLUE "fractionals increment:" RESET << std::endl;
	iter(fractionals, SIZE, &increment);
	iter(fractionals, SIZE, &print);

	char characters[] = { 'a', 'b', 'c', 'd' };
	std::cout << BLUE "characters:" RESET << std::endl;
	iter(characters, SIZE, &print);
	std::cout << BLUE "characters increment:" RESET << std::endl;
	iter(characters, SIZE, &increment);
	iter(characters, SIZE, &print);

	std::string strings[] = { "ciao", "come", "va", "marco" };
	std::cout << BLUE "strings:" RESET << std::endl;
	iter(strings, SIZE, &print);
	// the increment doesen't work for the strings, you get a compilation error!
	// std::cout << BLUE "strings increment:" RESET << std::endl;
	// iter(strings, SIZE, &increment);
	
}