/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:21:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/23 16:40:44 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_readInput(void) const;

public:
	void	addContact(void);
	void	printContacts(void) const;
	void	search(void) const;
	void	welcome(void) const;
};

#endif