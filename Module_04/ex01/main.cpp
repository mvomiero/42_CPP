/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:53 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 13:53:37 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.h"

/* ABSTRACT:
	allocating a class pointer to array as private member of a class in the constructor
	(and then deleting it in the destructor) : the Brain class, part of the Dog and Cat
	classes see e.g. Cat.cpp.
	Allocating in the main an array of objects and correspondingly freeing all its elements.
 */

int main( void )
{
	// setting two elements Cat and Dog to assign an idea.
	Cat* frontman = new Cat;
	frontman->setIdea( 0, BLUE "Welcome to our deep concert" RESET ); // to show they use their ideas (setting the idea)
	
	Dog* backman = new Dog; 
	backman->setIdea( 0, BLUE "Thank you for being there" RESET ); // to show they use their ideas (setting the idea)

	const Animal* animals[4] = { frontman, new Dog(), new Cat(), backman };
	std::cout << "\n\t🧠 ZOO CONCERT: 🧠\n" << std::endl;
	std::cout << frontman->getType() << ": " << frontman->getIdea( 0 ) << "\n" << std::endl; // display the idea we set before
	for ( int i = 0; i < 4; i++ ) {
		std::cout << animals[i]->getType() << " :" << std::endl;
		animals[i]->makeSound();
	}
	std::cout << "\n" << backman->getType() << ": " << backman->getIdea( 0 )  << std::endl; // display the idea we set before
	std::cout << "\n\t👏👏👏\n" << std::endl;
	
	//deleting:
	for ( int i = 0; i < 4; i++ ) {
		delete animals[i];
	}

	return 0;
}
