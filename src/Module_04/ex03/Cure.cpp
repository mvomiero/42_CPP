/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:39:29 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 11:57:05 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") { }

Cure::Cure(Cure const & src) : AMateria("cure")
{
	*this = src;
}

Cure::~Cure(void) { }

Cure &	Cure::operator=(Cure const & rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

AMateria *	Cure::clone(void) const
{
	AMateria*	cureClone = new Cure();
	return (cureClone);
}

void	Cure::use(ICharacter & target)
{
	std::cout << BLUE "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}