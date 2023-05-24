/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:21:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/24 19:21:42 by mvomiero         ###   ########.fr       */
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
	int		_readInput(void) const;

public:
	void	addContact(void);
	void	printContacts(void) const;
	void	search(void) const;
	void	welcome(void) const;
};

#endif