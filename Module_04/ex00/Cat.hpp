/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:58:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/17 17:54:09 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Colors.h"

class Cat : public Animal
{
private:

public:
	Cat( void );
	~Cat( void );

	void	makeSound( void ) const; // you should normally use override, but that is c++11 (and not 98 that we are using)
};

#endif