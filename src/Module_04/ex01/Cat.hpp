/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 13:45:06 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Colors.h"

class Cat : public Animal
{
private:
	Brain	*_brain;

public:
	Cat( void );
	Cat( const Cat& src);
	~Cat( void );

	Cat& operator=( const Cat& rhs );

	void	makeSound( void ) const; // you should normally use override, but that is c++11 (and not 98 that we are using)
	std::string	getIdea( int n ) const;
	void	setIdea( int n, std::string idea ) const;
};

#endif