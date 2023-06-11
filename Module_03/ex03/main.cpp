/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 15:49:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "Colors.h"
/* ABSTRACT:
	Really the same exact thing as ex01 (ScavTrup), just the contructor and destructor
	have different messages and the values are a bit different and
	the signature finction has another name and output (highFivesGuys instead of guardGate)
 */

#define DIAMOND "Diamond"
#define TRAPPY "Trappy"
#define FRAGOLA "Fragola"

int	main(void) {
	DiamondTrap	Diamond(DIAMOND);

	Diamond.whoAmI();
	Diamond.highFivesGuys();
	Diamond.attack("Giorgio");
}
