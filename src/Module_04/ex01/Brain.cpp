/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:28:38 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 13:45:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain created (constructor call)" << std::endl;
}

Brain::~Brain( void ) {
	std::cout << "Brain destroyed (destructor call)" << std::endl;
}

Brain::Brain( const Brain& src ) {
	std::cout << "Brain created (copy constructor call)" << std::endl;
	*this = src;
}

Brain& Brain::operator=( const Brain& src )
{
	std::cout << "Brain assigned (assignment operator call)" << std::endl;
	if ( this != &src ) {
		for ( int i = 0; i < 100; i++ ) {
			this->_ideas[i] = src._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea( int n ) {
	return this->_ideas[n];
}

void Brain::setIdea( int n, std::string idea ) {
	this->_ideas[n] = idea;
}