/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:18:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/23 18:03:50 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::welcome(void) const {
	std::cout << std::endl;
	std::cout << "Welcome to Your Awesome PhoneBook" << std::endl;
	std::cout << std::endl;
	std::cout << "--------------USAGE---------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
};

void	PhoneBook::addContact(void) {
	static int	i;
	
	this->_contacts[i % 8].initContact();
//	this->_contacts[i % 8].setIndex(i % 8);
	this->_contacts[i].view(i);
	i++;
	
}

