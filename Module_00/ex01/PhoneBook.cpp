/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:18:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/24 18:13:15 by mvomiero         ###   ########.fr       */
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
	
/* 	while (!inputOK) {
		std::cout << "Please enter the contact index: " << std::endl;
		std::cin >> input;
		std::cout << input << "this is the number index" << std::endl;
		if (input >= 1 && input <= 8)
			inputOK = true;
		else {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid index, try again!" << std::endl;
		}
	}
	std::cin.clear();
	std::cin.ignore();	
	return (input - 1); */
	std::string	strInput;
	
	while (!inputOK) {
	std::cout << "Please enter the contact index: " << std::endl;
	std::getline(std::cin, strInput);
	//input = std::stoi(strInput);
	input = std::atoi(strInput.c_str());
	//std::cout << input << "this is the number index" << std::endl;
	if (input >= 1 && input <= 8)
			inputOK = true;
		else {
			std::cin.clear();
			//std::cin.ignore();
			std::cout << "Invalid index, try again!" << std::endl;
		}
	}
	return (input - 1);

}

void	PhoneBook::search(void) const {
	int i = this->_readInput();
	this->_contacts[i].display(i);
}