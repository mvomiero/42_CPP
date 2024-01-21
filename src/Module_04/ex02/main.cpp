/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:53 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/18 15:32:35 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.h"

/* ABSTRACT:
	Abstract classes: base class that can't be instantiated.
	In this exercise, the Animal class is set as abstract (by setting one of its 
	functions = 0)
 */

/* ABSTRACT CLASS:
	used as base classe, it can't be instantiated (instatiation = creation of an object of
	a class) on its own.
	You make a class abstract settinig one or more of its functions = 0; 
	(see Animal.hpp, makeSound() function is = 0)
	The purpose of an abstract class is to define a common base but at the same
	time enfocing specific requirements of the derived class	
 */

int main( void )
{
	/* DEFAULT TESTS */
	const Animal* j = new Dog();
	const Animal* k = new Cat();

	delete j;//should not create a leak
	delete k;

	/* TESTS MARCO */

	// !!!! This line wouldn't work!! Animal is an abstract class!
	// Animal abstract = Animal("Abstract");
	
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
