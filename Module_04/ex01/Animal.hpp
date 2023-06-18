/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:21:18 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 12:33:18 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
protected:
	std::string _type;

public:
	Animal( void );
	Animal( std::string type );
	Animal( const Animal& src );

	virtual ~Animal( void );
		// destructor has to be virtual as well, to ensure the correct destruction 
		// of derived class objects through base class pointers. (see TESTS WRONG in the main.cpp)
	
	Animal& operator=( const Animal& rhs);

	virtual void	makeSound( void ) const;
		// if not virtual dedived classes would use this one instead
	std::string		getType( void ) const;
};

#endif