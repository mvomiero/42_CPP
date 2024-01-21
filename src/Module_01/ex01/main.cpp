/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:33:06 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 16:40:11 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 4

int	main(void) {
	Zombie* zombiesss = zombieHorde(N, "Zomby");

	for (int i = 0; i < N; i++) {
		zombiesss[i].announce();
	}
	delete[] zombiesss;
	return 0;
}