/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:21:18 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/17 16:29:50 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
	std::string _type;

public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal& src );

	~WrongAnimal( void );
	
	WrongAnimal& operator=( const WrongAnimal& rhs);

	void	makeSound( void ) const; // if it wouldnt be virtual the derived classes
		// if not virtual dedived classes would use this one instead
	std::string		getType( void ) const;
};

#endif