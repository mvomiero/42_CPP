/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:18:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/24 13:56:51 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::welcome(void) const {
	std::cout << std::endl;
	std::cout << "🙊 Welcome to Your Awesome PhoneBook 🙉\n" << std::endl;
	std::cout << "--------------🙈CONTACTS🙈-------------\n" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quit the PhoneBook.\n" << std::endl;
	std::cout << "--------🐒--------🐒--------🐒---------\n" << std::endl;
};

void	PhoneBook::addContact(void) {
	static int	i;

	this->_contacts[i % 8].initContact();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::printContacts(void) const {
	std::cout << "--------------🙈CONTACTS🙈-------------\n" << std::endl;
	for (size_t i = 0; i < 8; i++) {
		this->_contacts[i].view(i);
	}
	std::cout << std::endl;
}

int	PhoneBook::_readInput() const {
	int		input;
	bool	inputOK = false;
	
	while (!inputOK) {
		std::cout << "Please enter the contact index: " << std::endl;
		std::cin >> input;
		if (input >= 0 && input <= 8)
			inputOK = true;
		else {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid index, try again!" << std::endl;
		}
	}
	std::cin.clear();
	std::cin.ignore();
	return (input);
}

void	PhoneBook::search(void) const {
	int i = this->_readInput();
	this->_contacts[i].display(i);
}