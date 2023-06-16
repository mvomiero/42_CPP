/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:48:53 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/16 18:15:15 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Animal.hpp"
#include "Cat.hpp"

int main( void ) {
	const Animal* prova = new Animal("Leone");
	const Animal* gatto = new Cat();
	//Cat gatto = Cat();

	prova->makeSound();
	gatto->makeSound();

	delete prova;
	delete gatto;
}