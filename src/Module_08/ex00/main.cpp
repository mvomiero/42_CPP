/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:49:02 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/12 12:30:37 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <colors.h>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

/* ABSTRACT:
	writing a function template for a function that takes a container T and a value.
	The function should return an iterator pointing to the first element in the container,
	or throw an exception if the element is not found.
	It's required that it works for sequence containers (not associative ones).
	Sequence containers are: vector, list, deque, forward_list, array, string.
*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./easyfind [number]" << std::endl;
		return EXIT_FAILURE;
	}

	int array[] = {1, 2, 3, 4, 5};
	std::cout << BG_BRIGHT_CYAN << "Vector test" << RESET << std::endl;
	try
	{
		std::vector<int> vect(array, array + sizeof(array) / sizeof(int));
		std::vector<int>::const_iterator it = easyfind(vect, atoi(av[1]));
		std::cout << "\tFound " << *it << std::endl;
		//*it = 42; // doesn't compile, you can just read and not write
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BRIGHT_CYAN << "List test" << RESET << std::endl;
	try
	{
		std::list<int> list(array, array + sizeof(array) / sizeof(int));
		std::list<int>::const_iterator it = easyfind(list, atoi(av[1]));
		std::cout << "\tFound " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BRIGHT_CYAN << "Deque test" << RESET << std::endl;
	try
	{
		std::deque<int> deq(array, array + sizeof(array) / sizeof(int));
		std::deque<int>::const_iterator it = easyfind(deq, atoi(av[1]));
		std::cout << "\tFound " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}