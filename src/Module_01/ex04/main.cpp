/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:51:50 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 12:59:05 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedPro.hpp"

int main ( int ac, char **av )
{
	if (ac != 4) {
		std::cerr << "Usage: ./sedpro <filename> <to_find> <replace>." << std::endl;
		return EXIT_FAILURE;
	} else {
		SedPro	sedTemp(av[1]);

		sedTemp.replace(av[2], av[3]);
	}
	return EXIT_SUCCESS;
}