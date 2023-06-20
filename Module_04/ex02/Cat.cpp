/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 16:18:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( BG_BRIGHT_CYAN "Cat" RESET)
{
	std::cout << "🐈 " << this->_type << " constructor called" << std::endl;
	this->_brain = new Brain();
}

void	Cat::makeSound( void ) const
{
	std::cout << "🐈 " << "miaooooo 🐈" << std::endl;
}

Cat::Cat( const Cat& src )
{
	*this = src;
}

Cat& Cat::operator=( const Cat& src )
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
		this->_brain = new Brain( *src._brain );
	}
	return *this;
}

Cat::~Cat( void )
{
	std::cout << "🐈 " << this->_type << " destructor called" << std::endl;
	delete this->_brain;
}

std::string	Cat::getIdea( int n ) const {
	return this->_brain->getIdea( n );
}

void	Cat::setIdea( int n, std::string idea ) const {
	this->_brain->setIdea( n, idea );
}