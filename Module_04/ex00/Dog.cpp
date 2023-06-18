/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:44:06 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 11:12:36 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( BG_BLUE "Dog" RESET )
{
	std::cout << "🐕 " << this->_type << " constructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "🐕 " << "baubaubau 🐕" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "🐕 " << this->_type << " destructor called" << std::endl;
}