/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 13:49:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Colors.h"

class Dog : public Animal
{
private:
	Brain	*_brain;

public:
	Dog( void );
	Dog( const Dog& src);
	~Dog( void );

	Dog& operator=( const Dog& rhs );

	void	makeSound( void ) const; // you should normally use override, but that is c++11 (and not 98 that we are using)
	std::string	getIdea( int n ) const;
	void	setIdea( int n, std::string idea ) const;

};

#endif