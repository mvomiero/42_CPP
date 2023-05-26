/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:22:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 17:00:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook book;
	std::string input;
	book.welcomeMessage();
	while (1) {
		std::cout << "🐒 " << std::flush;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0) {
			book.printContacts();
			book.search();
		}
		else if (input.compare("EXIT") == 0) {
			return (0);
		}
		else
			std::cout << "Incorrect input! 🙈 " << std::endl;
	}
}