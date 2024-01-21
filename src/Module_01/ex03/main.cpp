/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:44:01 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 12:11:26 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/* differences between HumanA and HumanB:
	-- HumanA takes the weapon in its construct -> it can then be stored in a refence
		element since it's a defined object
	-- HumanB needs a function to set the weapon -> it needs then a standard
		pointer and not a reference to store its weapon (it's an undefined element!)
 */
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	// added to see the output of no weapon and that you first have to initialize
	// it before setting to another Type
	{
		Weapon club = Weapon("crude spiked club");
		HumanB Rose("Rose");
		Rose.attack();
		Rose.setWeapon(club);
		club.setType("roses");
		Rose.attack();
	}

	return 0;
}