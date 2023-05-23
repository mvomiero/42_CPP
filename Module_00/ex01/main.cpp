/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:22:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/23 18:20:05 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
//#include <limits>
#include <iostream>

int	main(void)
{
	std::cout << "hello world" << std::endl;
	PhoneBook book;
	std::string input = "";
	book.welcome();
	while (input.compare("EXIT")) {
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0) {
			
		//	book.printContacts();
		//	book.search();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
}