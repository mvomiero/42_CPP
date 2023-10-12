/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:23:10 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/12 15:53:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BG_RED << "-------- TEST ASSIGNEMENT --------" << RESET << std::endl;
		std::cout << ITAL "\tsimple test\n" RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << ITAL CYAN "shortest and longest span" RESET << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << BG_RED << "------------- TEST 1 -------------" << RESET << std::endl;
		std::cout << ITAL "\taddRange() and exceptions\n" RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);

		std::vector<int> vect;
		vect.push_back(17);
		vect.push_back(9);
		vect.push_back(11);

		sp.addRange(vect.begin(), vect.end());

		std::cout << ITAL CYAN "shortest and longest span" RESET << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try
		{
			std::cout << ITAL CYAN "Trying to add a number to a full vector" RESET << std::endl;
			sp.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << ITAL CYAN "Trying to add a range to a full vector" RESET << std::endl;
			sp.addRange(vect.begin(), vect.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	
	

	try
	{
		std::cout << BG_RED << "------------- TEST 2 -------------" << RESET << std::endl;
		std::cout << ITAL "\tbig container\n" RESET << std::endl;
		std::vector<int> vect(10000);
		std::srand(time(NULL));
		std::generate(vect.begin(), vect.end(), std::rand);

		Span span(vect.size());

		span.addRange(vect.begin(), vect.end());

		std::cout << ITAL CYAN "shortest and longest span" RESET << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}