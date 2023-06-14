/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:15:30 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 18:52:37 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie( std::string name ); // Constructor
	~Zombie(); // Destructor
	void	announce( void ) const;
};

/*  Declaring the two external functions you need to create a Zombie pointer 
	pointer and a stack Zombie */
Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
#endif