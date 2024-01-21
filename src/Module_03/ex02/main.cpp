/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 15:40:35 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "Colors.h"
/* ABSTRACT:
	Really the same exact thing as ex01 (ScavTrup), just the contructor and destructor
	have different messages and the values are a bit different and
	the signature finction has another name and output (highFivesGuys instead of guardGate)
 */

#define CLAPPY "Clappy"
#define TRAPPY "Trappy"
#define FRAGOLA "Fragola"

int	main(void) {
	ClapTrap	Clappy(CLAPPY);
	ClapTrap	Trappy(TRAPPY);
	FragTrap	Fragola(FRAGOLA);

	Clappy.attack(TRAPPY);
	Trappy.takeDamage(5);
	Trappy.beRepaired(5);
	// until here from exercise before
	Fragola.highFivesGuys(); // specific of FragTrap
	Fragola.takeDamage(5); // from the base class but works for FragTrap as well
}
