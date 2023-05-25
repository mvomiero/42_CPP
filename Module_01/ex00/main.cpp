/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:33:06 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 16:06:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	printHeapZombie(Zombie* heapy) {
	heapy->announce();
	std::cout << "As you can see, I'm existing outside the scope"
		<< "of the function that made me :)" << std::endl;
}

int	main( void ) {
	// Stack Zombie
	randomChump("Stacky 👻");
	std::cout << "Carpe diem! I just lived in the stack." << std::endl;

	// Heap Zombie --> you can pass the address and call the announce funtion
	// in another functin
	Zombie *heapy = newZombie("Heapy 👻");
	printHeapZombie(heapy);
	// If you don't delete the allocated pointer, the destructor function wont be executed
	delete heapy;
	return 0;
}