/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:53:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 11:52:49 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void ) const {
	if (this->_weapon.getType() != "") {
		std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
	} else {
		std::cout << _name << " ...no weapon no war :)" << std::endl;
	}
}