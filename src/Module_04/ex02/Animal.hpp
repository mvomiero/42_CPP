/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:21:18 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 15:30:34 by mvomiero         ###   ########.fr       */
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
	
	Animal& operator=( const Animal& rhs);

	virtual void	makeSound( void ) const = 0; // !!!! Has to be set = 0 to make the class derived!
	std::string		getType( void ) const;
};

#endif