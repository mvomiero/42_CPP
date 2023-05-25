/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:21:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 12:16:53 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACT_MAX 8

#include "Contact.hpp"
#include <string>
#include <cstdlib>

class PhoneBook
{
private:
	Contact	_contacts[CONTACT_MAX];
	int		_searchInput(void) const;

public:
	void	addContact(void);
	void	printContacts(void) const;
	void	search(void) const;
	void	welcomeMessage(void) const;
};

#endif