/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:15:30 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 16:34:02 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie(); // Constructor
	~Zombie(); // Destructor
	// The three functions asked from the assignment
	void	announce( void ) const;
	void	setName( std::string name );
};

/*  Declaring the two external functions you need to create a Zombie pointer 
	pointer and a stack Zombie */
Zombie* zombieHorde( int N, std::string name );

#endif