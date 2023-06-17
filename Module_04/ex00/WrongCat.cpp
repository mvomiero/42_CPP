/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/17 16:50:30 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( BG_BRIGHT_RED "WrongCat" RESET)
{
	std::cout << this->_type << " constructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "miaooooo 🐈" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
}