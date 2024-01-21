/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:53:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 11:50:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const {
	if (this->_weapon != NULL && this->_weapon->getType() != "") {
		std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	} else {
		std::cout << _name << " ...no weapon no war :)" << std::endl;
	}
}