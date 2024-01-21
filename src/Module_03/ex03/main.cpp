/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:00 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 17:19:10 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "Colors.h"
/* ABSTRACT:
	topic: DIAMOND INHERITANCE
	   A
	 /   \
	B     C
	 \   /
	   D
	The diamond inheritance problem arises when a class inherits from two or more classes 
	that have a common base class. This results in a diamond-shaped inheritance diagram, 
	where the derived class is at the top, and two or more intermediate classes branch out 
	from it, eventually converging to a common base class.
	The "virtual" keyword (see Frag - Scav .hpp) is used for the middle level classes
	(B C) to avoid to have two copies of the base class A.
	Exercise:
	-- inheriting from Scav and Frag so setting both classes as virtual (see .hpp)
	-- choosing which implementation of the same function to inheritate 
		(the using keyword, see Diamond.hpp)
	-- getting different member variables from different base classes 
		(see the constructor in Diamond.cpp)
	-- didn't have problems compiling with -Wshadow...should throw problems if there are
		some conflicts like variables are different in different classes but didn't 
		have them while compiling actually
 */

#define DIAMOND "Diamond"

int	main(void) {
	DiamondTrap	Diamond(DIAMOND);

	Diamond.whoAmI(); // new function introduced in this exercise
	Diamond.highFivesGuys(); // inherited from Frag
	Diamond.attack("Giorgio"); // you'll see is inheritated from ScavTrap (see Diamond.hp) and not from Clap
}
