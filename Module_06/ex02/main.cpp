/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:08:06 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/14 17:38:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.h"

/* ABSTRACT:
	two functions to generate and identify an object:
	-- generate() just returns a pointer to a new element of the derived class
	-- identify() -> static polymorphism depending the input, which is either
		a pointer of a reference.
		With this two functions we see how dynamic_casting can be useful to identify
		the class of a given element.
		-- identify( pointer ) --> tries the casting, if it fails the pointer is NULL
			no problems because is downcastinc, so from the base class to the subclass.
			if it goes wrong, just the pointer is null
		-- identify( reference ) --> tries the casting, but since the input is
			a reference to a derived class, if you try the casting and is not of the same
			type, a std::bad_casting exception is thrown and the program crushes.
			That's why "try" and "catch" are used to handle exception.
 */

/* DYNAMIC CASTING:
	only type of casting that works dynamically, with polymorphic classes (have 
	at least one virtual function).
	Use cases:
	-- DOWNCASTING: the base pointer is set to an derived-class element
	(something we already did in some excercises. An example here:
		Base* basePtr = new Derived;
		Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
	-- some other smaller cases
	-- RETURN VALUE: is NULL if the casting fails, by reference an exception is thrown!
 */

/* Base classes and derived classes
 */
class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

/* generate():
	to generate a random derived class object
 */
Base *	generate( void )
{
	std::cout << "Generated: ";
	int	rnb = std::rand() % 3;

	switch (rnb) {
		case 0:
			std::cout << CYAN "A" RESET;
			return (new A);
		case 1:
			std::cout << GREEN "B" RESET;
			return (new B);
		case 2:
			std::cout << PURPLE "C" RESET;
			return (new C);
	}
	return (NULL); // Just because required from the compiler using the switch
}

/* to identify a Base* pointer, so to check if it's A, B, or C
 */
void	identify( Base * p )
{
	std::cout << "Identified as pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << CYAN "A" RESET;
	else if (dynamic_cast<B *>(p))
		std::cout << GREEN "B" RESET;
	else if (dynamic_cast<C *>(p))
		std::cout << PURPLE "C" RESET;
	else
		std::cout << RED "Unknown" RESET;
}

/* to identify an object, so a reference.
	NB Exceptions:	if you dont use the try and catch the program would stop with
	 a std::bad_cast exception! This way, the execution goes on
 */
void	identify( Base& p ) {
	std::cout << "Identified as reference: ";
	try {
		A& a = dynamic_cast< A& >( p );
		std::cout << CYAN "A" RESET << std::endl;
		(void)a;
	} catch(const std::exception& e) {}
	try {
		B& b = dynamic_cast< B& >( p );
		std::cout << GREEN "B" RESET << std::endl;
		(void)b;
	} catch( const std::exception& e ) {}
	try {
		C& c = dynamic_cast< C& >( p );
		std::cout << PURPLE "C" RESET << std::endl;
		(void)c;
	} catch( const std::exception& e ) {}
}

/* just creates random objects and then identifies them by pointer or by reference
 */
int	main(void)
{
	Base *	p;

	for (int i = 0; i < 25; i++)
	{
		std::cout << "Test [" << i << "]:\t";
		p = generate();
		std::cout << ", ";
		identify(p);
		std::cout << ", ";
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}