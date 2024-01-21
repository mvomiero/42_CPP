/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:33:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 15:39:25 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "Colors.h"

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	// Base class initialization happens in the member initialization list -- ClapTrap(name)
	// Member variables can be after assigned values within the constructor body (the _variables)
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << PURPLE "FragTrap " << _name << " has been created 🍓" RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << PURPLE "FragTrap " << this->_name << " destructor called 🍓" RESET<< std::endl;
}

void    FragTrap::highFivesGuys() {
	std::cout << PURPLE "\t🍓 " << this->_name << " says: give me a high five guyyyys 🙌" RESET << std::endl;
}