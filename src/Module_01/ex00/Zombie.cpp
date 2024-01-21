/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:14:28 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 15:32:51 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor: saves the name given as a parameter
Zombie::Zombie( std::string name ) {
	this->_name = name;
}

// Destructor: prints a message of the destruction of the Zombie
Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
}

// The Zombie announces himself
void	Zombie::announce( void ) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
