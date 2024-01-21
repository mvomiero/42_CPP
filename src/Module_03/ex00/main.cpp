/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/10 18:30:17 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ABSTRACT:
	Just implementing a class and a system of variables and method functions
	that modify this variables (ClapTrap robot attacking, reparing himself and reciving
	damage). Not really interaction between objects.
	I suppose is just a preamble exercise to implement with Inheritance in the nex
	exercises
 */

#define CLAPPY "Clappy"
#define TRAPPY "Trappy"

int	main(void) {
	ClapTrap	Clappy(CLAPPY);
	ClapTrap	Trappy(TRAPPY);

	Clappy.attack(TRAPPY); // It actually does nothing to the other (and points of damage are 0)
		//but supposed to cause the gain of Attack damage points, 1 energy point needed
	Trappy.takeDamage(5); // Not really from the other, there is no exchange
		// supposed to get Attack damage points
	Trappy.beRepaired(5); // gets Hit points back, 1 energy point needed
}
