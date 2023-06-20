/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:53 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 15:51:59 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.h"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

/* ABSTRACT:
	using dynamic polymorphism for subtypes. It is like the function overload (the function
	is overloaded at compilation becuse the parameters are different), but here is done
	at runtime by declaring base class elements virtual (so the subclass function overrides it).
	Base class Animal with derived classes Cat and Dog and corresponding
	Wrong classes, where the virtual keyword is not used (so no function override)
 */

/* POLYMORPHISM:
	polymorphism = treat differently different objects derived from a class. It is 
	for example the overload of a function, or the possibility to inheritate and change
	some stuff.
	There are two types of polymorphism: 
		-- Compile-time Polymorphism (Static Polymorphism):
			like in the past modules, different parameters then at compile time 
			is evaluated which is the corresponding function
		-- Run-time Polymorphism (Dynamic Polymorphism): 
			trough inheritance and virtual functions: appropriate function depending
			the type of object that is calling it. See in the main the TEST MARCO
			section, where a same pointer Animal can be assigned first to a Cat objec, 
			then to a Dog object.
 */

/* KEYWORD "virtual":
	if a base class member function is declared "virtual", it means it can be
	overridden by a function with the same signature in a derived class. It's an
	example of Dynamic Polymorphism.
	To override the makeSound function in the classes Cat and Dog, it is declared as
	virtual in Animal (see Animal.hpp)
	Since one function is virtual, is good practice to declare the destructor virtual as
	well, otherways there is a case where the destructor would't be called (see TEST
	MARCO section).
	So it works: at compilation time a table of virtual functions is set for every
	class, then at a runtime the right function to execute is chosen in this table
	(if a function is declared virtual of course).
	
 */

int	main( void ) {

	/* TEST DEFAULT */
	
	std::cout << BLUE BOLD "\nTEST DEFAULT\n" RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "J Type: " << j->getType() << " " << std::endl;
	std::cout << "I Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	/* TEST WRONG */

	std::cout << BLUE BOLD "\nTEST WRONG\n" RESET << std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	//WrongAnimal *wrongCat = new WrongCat();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
	std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	delete  wrong;
	delete  wrongCat; // here there is a problem: down
	/* just the destructor of Wronganimal is called, and not the one of WrongCat !! 
		that is because WrongAnimal destructor wasn't declared virtual */

	/* TEST MARCO */

	std::cout << BLUE BOLD "\nTEST MARCO\n" RESET << std::endl;
	/* here is an example of why declaring a pointer of the base class pointing
		to a subclass element: it's just practical because you can have the same 
		behavior for different subclasses */
	Animal* animalPtr;
	Dog dog;
	Cat cat;

	animalPtr = &dog;
	animalPtr->makeSound();  // Calls Dog::makeSound() dynamically

	animalPtr = &cat;
	animalPtr->makeSound();  // Calls Cat::makeSound() dynamically
}
