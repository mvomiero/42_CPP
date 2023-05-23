/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:21:10 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/23 18:28:01 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
// to comment out here down
#include <iomanip>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	int			_index;

	std::string _printLen(std::string str) const;
	std::string _getInput(std::string strMessage) const;

public:
	void	initContact(void);
	void	view(int index) const;
	void	display(int index) const;
	void	setIndex(int i);
};

#endif
