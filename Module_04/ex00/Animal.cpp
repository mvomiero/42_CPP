/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:21:08 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/16 18:00:18 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "Unknown animal" ) {
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type( type ) {
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}

Animal::Animal( const Animal& src ) {
	std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
	*this = src; // the copy operator assignment will be automatically called 
}

Animal::~Animal( void ) {
	std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& rhs) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return ( *this );
}

void	Animal::makeSound( void ) const {
	std::cout << "Unknown sound" << std::endl;
}

std::string Animal::getType( void ) const {
	return ( this->_type );
}