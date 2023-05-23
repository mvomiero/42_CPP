/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:21:10 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/23 13:42:25 by mvomiero         ###   ########.fr       */
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
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;
	int			index;

	std::string _printLen(std::string str) const;
	std::string _getInput(std::string str) const;

public:
	void	init(void);
	void	view(int index) const;
	void	display(int index) const;
	void	setIndex(int i);
};

#endif
