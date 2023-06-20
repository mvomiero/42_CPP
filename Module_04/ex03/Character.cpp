/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:04:24 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 12:21:40 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const & name ) : _name(name)
{
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character( Character const & src ) : _name(src._name)
{
	*this = src;
}

Character& Character::operator=( Character const & rhs )
{
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

void	Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			if (VERBOSE) { std::cout << "equip(): Character " << this->_name << " equipped with " << m->getType() << std::endl;}
			return;
		}
}

void	Character::unequip( int idx ) {
	if (idx >= 0 && idx < 4){
		if (this->_inventory[idx])
			std::cout << "Character " << this->_name << " unequipped" << std::endl;
	}
	else
		std::cout << "Character " << this->_name << " can't unequip" << std::endl;
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx < 4)
	{
		if (this->_inventory[idx])
		{
			if (VERBOSE) { std::cout << "use(): Character " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl; }
			this->_inventory[idx]->use(target);
		}
	}
}

std::string const& Character::getName() const {
	return this->_name;
}