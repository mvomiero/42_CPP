/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:57:41 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 12:21:01 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("Unknown") { }

AMateria::AMateria( std::string const & type )  : _type(type) { }

AMateria::AMateria( AMateria const & src )
{
	*this = src;
}

AMateria &	AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria( void ) { }

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use( ICharacter& target )
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}