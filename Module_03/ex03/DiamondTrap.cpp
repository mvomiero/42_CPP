/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:33:42 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 17:16:43 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	
	std::cout << CYAN "DiamondTrap " << this->_name << " has been created 💍" RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << CYAN "DiamondTrap " << this->_name << " destructor called 💍" RESET << std::endl;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << BRIGHT_YELLOW "I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << RESET << std::endl;
}