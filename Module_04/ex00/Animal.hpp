/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:21:18 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/16 18:15:38 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string _type;

public:
	Animal( void );
	Animal( std::string type );
	Animal( const Animal& src );

	virtual ~Animal( void );
	
	Animal& operator=( const Animal& rhs);

	//virtual void	makeSound( void ) const;
	 void	makeSound( void ) const;
	std::string		getType( void ) const;
};

#endif