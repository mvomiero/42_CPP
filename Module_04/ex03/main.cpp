/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:28:44 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 15:34:57 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
//#include "ICharacter.hpp"
//#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/* ABSTRACT:
	Recap with classes, abstract classes, inheritance, allocation
	and interfaces (see down)

	run make verbose to have a message from the used functions
 */

/* STRUCTURE:

	(ICharacter) Character--> 
				(IMateriaSource) MateriaSource--> 
							(Amateria) --> (Cure, Ice)

	Let's crack down all this classes of this a bit complex exercise:
	-- Amateria: abstract class to implement the Materia classes Ice and Cure
		No memory allocation for this three classes, just the .clone() function returns
		a pointer to a dinamically allocated object (which is though stored and consequentially 
		freed in the MateriaSource class.
		functions: use() to display what the materia does
	-- (IMateriaSource) is just the interface of MateriaSource:
		learnMateria(): learns some AMaterias and stores them in an array of 4 elements.
		createMateria(): clones the required element reading from its own library.
	-- (ICharacter) is just the interface of Character
 */

/* INTEERFACES:
	In object-oriented programming (OOP), an interface is a programming construct 
	that defines a contract or a set of methods that a class must implement.
	In c++ there are no Interfaces but you can achieve a similar result with abstract
	classes (you declare the functions = 0 and so the subclasses will have to implement them)
 */

int main()
{
	if (VERBOSE) { std::cout << "\nVerbose mode on\n" << std::endl; }
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice()); 
	// 1. dinamic allocation of this object, will be destructed with the ~MateriaSource() destructor
	// the allocated pointer to the Amateria object is stored in src
	src->learnMateria(new Cure()); //same as up

	ICharacter* me = new Character("me");

	AMateria* tmp; // practical because an Amateria pointer I can assign it both to Ice and Cure objects
	tmp = src->createMateria("ice");
	// 2. dinamic allocation, will be destructed in the ~Character() destructor
	// thanks to the Amateria.clone() function a dinamically allocated object Amateria is stored in src - materiaSource
	me->equip(tmp);
	// the allocated pointer to the Amateria object stored in src is stored in Character
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	// a Fifth element is assigned but no bugs ;)
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	std::cout << BOLD BLUE "\n🌀 First ice battle 🌀" RESET << std::endl;
	std::cout << ITAL "ice, cure, cure, ice\n" RESET << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	// Fifth element but still no bugs ;)
	me->use(4, *bob);

	std::cout << BOLD BLUE "\n🌀 Second ice battle 🌀" RESET << std::endl;
	std::cout << ITAL "cure, ice (two elements are unequipped)\n" RESET << std::endl;
	
	me->unequip(0);
	me->unequip(1);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << BOLD BLUE "\n🌀 Third ice battle 🌀" RESET << std::endl;
	std::cout << ITAL "ice, ice, cure, ice (two elements ice restored)\n" RESET << std::endl;

	// the element ice is deleted from the character (with unequip()) but is still there
	// in src to equip the Character again
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}