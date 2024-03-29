/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:59:35 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 19:12:40 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main( void ) {

	std::string	input;
	Harl		harl;

	while (input != "exit") {
		std::cout << "Enter a level (or <exit>): ";
		std::cin >> input;
		harl.complain(input);
	}

	return EXIT_SUCCESS;
}