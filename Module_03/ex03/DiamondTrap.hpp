/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:33:31 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 17:10:44 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;

public:
	DiamondTrap( std::string name );
	~DiamondTrap();

	/* using:
		since we are deriving the class both from Frag and Scav (so from Clap as well),
		since Clap has a first definition of the attack() function and Scav has an 
		implementation of the same function, we have to specify which one we want to 
		inheritate
	 */
	using	ScavTrap::attack;
	void	whoAmI( void );
};

#endif