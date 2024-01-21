/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:59:35 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 16:31:48 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int ac, char **av ) {

	if (ac != 2) {
		std::cout << "Wrong arguments!" << std::endl;
		std::cout << "Use: ./harlFilter <level>" << std::endl;
		return (EXIT_FAILURE);
	}
	Harl	harl;

	harl.complain(av[1]);

	return EXIT_SUCCESS;
}