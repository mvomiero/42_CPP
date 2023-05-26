/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:03 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 12:03:02 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type) {
	this->setType(type);
}

Weapon::~Weapon() {
}

/* int the next function, a constant reference to the string element is returned
	the declaration ot the function is therefore a bit complicated:
	--> const	std::string& -----> is the return type
	--> Weapon::getType( void ) --> is then the name and arguments of the function
 */
const	std::string& Weapon::getType( void ) {
	return this->_type;
}

void	Weapon::setType( std::string inputType ) {
	this->_type = inputType;
}