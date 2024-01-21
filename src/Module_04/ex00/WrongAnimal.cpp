/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:16:20 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/17 17:23:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "Unknown wronganimal" ) {
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src ) {
	std::cout << "WrongAnimal " << this->_type << " copy constructor called" << std::endl;
	*this = src; // the copy operator assignment will be automatically called 
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& rhs) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return ( *this );
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Unknown sound 🦖" << std::endl;
}

std::string WrongAnimal::getType( void ) const {
	return ( this->_type );
}