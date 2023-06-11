/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 15:38:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "Colors.h"
/* ABSTRACT:
	First attempt of creating a subclass (ScavTrav, subclass of Claptrap).
	Highlights:
	-- the private members of the base class are to be set as protected in order 
		for the subclass to inheritate them
	-- the constructor of the subclass has to first initialize the base class in 
		the initialization list, then in the constructor body is possible to assign
		variables. This way two objects are created, the base and then the subclass.
		That's why then later for example the destructor is called two times for Serena.
		For more see ScavTrap.cpp, constructor function.
	-- for the inheritance you just have to use the syntax used for the declaration
		(see ScavTrap.hpp)
 */

/* NB - COLORS_H:
	added from here a header for the colors, it is practical to recognise some
	elements and the corresponding actions.
 */

#define CLAPPY "Clappy"
#define TRAPPY "Trappy"
#define SERENA PURPLE"Serena"RESET

int	main(void) {
	ClapTrap	Clappy(CLAPPY);
	ClapTrap	Trappy(TRAPPY);
	ScavTrap	Serena(SERENA);

	Clappy.attack(TRAPPY);
	Trappy.takeDamage(5);
	Trappy.beRepaired(5);
	// until here from exercise before
	Serena.highFivesGuys(); // specific of ScavTrap
	Serena.takeDamage(5); // from the base class but works for ScavTrap as well
}
