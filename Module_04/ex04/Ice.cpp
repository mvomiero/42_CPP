/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:39:29 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/19 11:49:47 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << CYAN "Ice default constructor called" RESET << std::endl;
	return ;
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	std::cout << CYAN "Ice copy constructor called" RESET << std::endl;
	*this = src;
	return ;
}

Ice::~Ice(void)
{
	std::cout << CYAN "Ice destructor called" RESET << std::endl;
	return ;
}

Ice &	Ice::operator=(Ice const & rhs)
{
	std::cout << CYAN "Ice assignment operator called" RESET << std::endl;
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