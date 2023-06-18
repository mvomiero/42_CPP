/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 13:52:20 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( BG_BLUE "Dog" RESET)
{
	std::cout << "🐕 " << this->_type << " constructor called" << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory Allodogion is failed : " << e.what() << std::endl;
	}
}

void	Dog::makeSound( void ) const
{
	std::cout << "🐕 " << "baubaubau 🐕" << std::endl;
}

Dog::Dog( const Dog& src )
{
	*this = src;
}

Dog& Dog::operator=( const Dog& src )
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
		this->_brain = new Brain( *src._brain );
	}
	return *this;
}

Dog::~Dog( void )
{
	std::cout << "🐕 " << this->_type << " destructor called" << std::endl;
	delete this->_brain;
}

std::string	Dog::getIdea( int n ) const {
	return this->_brain->getIdea( n );
}

void	Dog::setIdea( int n, std::string idea ) const {
	this->_brain->setIdea( n, idea );
}