/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:14:28 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 18:58:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor; it's needed if you are gonna create an array of objects of this class
Zombie::Zombie( void ) {
}

// Destructor: prints a message of the destruction of the Zombie
Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
}

// to set the name of the zombie
void	Zombie::setName( std::string name ) {
	this->_name = name;
}

// The Zombie announces himself
void	Zombie::announce( void ) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
