/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:18:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 12:31:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Outputs the welcome message */
void	PhoneBook::welcomeMessage(void) const {
	std::cout << std::endl;
	std::cout << "🙊 Welcome to Your Awesome PhoneBook 🙉\n" << std::endl;
	std::cout << "--------------🙈COMMANDS🙈-------------\n" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quit the PhoneBook.\n" << std::endl;
	std::cout << "--------🐒--------🐒--------🐒---------\n" << std::endl;
};

/* adds a contact by calling the two other functions of the Contact class*/
void	PhoneBook::addContact(void) {
	static int	i;

	this->_contacts[i % CONTACT_MAX].initContact();
	this->_contacts[i % CONTACT_MAX].setIndex(i % CONTACT_MAX);
	i++;
}

/* prints the contacts using the .view() function of the contact class */
void	PhoneBook::printContacts(void) const {
	std::cout << "--------------🙈CONTACTS🙈-------------\n" << std::endl;
	for (size_t i = 0; i < CONTACT_MAX; i++) {
		this->_contacts[i].displayInline(i);
	}
	std::cout << std::endl;
}

/* returns the input, starting a loop until a correct input is found. 
	Input are the index numbers, from 1 to 8. Input is stored in a string with 
	getline and then converted to an integer with atoi. In this case some problems
	are avoided compared to use std::cin << which converts the element automatically */
int	PhoneBook::_searchInput() const {
	int		input;
	bool	inputOK = false;
	std::string	strInput;
	
	while (!inputOK) {
	std::cout << "Please enter the contact index: " << std::endl;
	std::getline(std::cin, strInput);
	input = std::atoi(strInput.c_str());
	if (input >= 1 && input <= CONTACT_MAX)
			inputOK = true;
		else {
			std::cin.clear();
			std::cout << "Invalid index, try again!" << std::endl;
		}
	}
	return (input - 1);
}

/* gets the input and then calls the .display() function from the Contacts class */
void	PhoneBook::search(void) const {
	int i = this->_searchInput();
	this->_contacts[i].display(i);
}