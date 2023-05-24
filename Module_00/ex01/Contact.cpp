/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:20:38 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/24 13:56:01 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::_getInput(std::string strMessage) const
{
	std::string	strInput = "";
	bool		inputOK = false;

	while (!inputOK)
	{
		std::cout << strMessage << std::endl;
		//should you use std::cin.good() as well to check?
		//std::cin.clear();
		std::getline(std::cin, strInput);
		if (!strInput.empty())
			inputOK = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input! Try again" << std::endl;
		}
	}
	return (strInput);
}

void	Contact::initContact(void) {
	// to clear the buffer from any remaining characters, before using getline
	//std::cin.ignore();
	this->_firstName = this->_getInput("Please enter you first name: ");
	this->_lastName = this->_getInput("Please enter your last name: ");
	this->_nickName = this->_getInput("Please enter your nickname: ");
	this->_phoneNumber = this->_getInput("Please enter your phone number: ");
	this->_darkestSecret = this->_getInput("Please enter your darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::setIndex(int i) {
	this->_index = i;
}

void	Contact::view(int index) const {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	// std::setw(10) sets the witdth of of the next input field
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_firstName << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display(int index) const {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << std::endl;
	std::cout << "------🙈 CONTACT #" << index << " 🙈------" << std::endl;
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickName << std::endl;
	std::cout << std::endl;
}
