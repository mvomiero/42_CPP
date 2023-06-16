/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/16 18:35:29 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << this->_type << " constructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "miaooooo 🐈" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
}