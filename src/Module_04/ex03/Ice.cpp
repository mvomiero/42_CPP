/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:39:29 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 11:57:05 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") { }

Ice::Ice(Ice const & src) : AMateria("ice")
{
	*this = src;
}

Ice::~Ice(void) { }

Ice &	Ice::operator=(Ice const & rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

AMateria *	Ice::clone(void) const
{
	AMateria*	iceClone = new Ice();
	return (iceClone);
}

void	Ice::use(ICharacter & target)
{
	std::cout << CYAN "* shoots an ice bolt at " << target.getName() << " *"
		RESET << std::endl;
}