/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:08:06 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/13 17:24:34 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.h"

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};


Base *	generate(void)
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
	return (NULL);
}

void	identify(Base * p)
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


/* if you dont use the try and catch the program would stop with a std::bad_cast exception!
	This way, the execution goes on */
void    identify( Base& p ) {
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