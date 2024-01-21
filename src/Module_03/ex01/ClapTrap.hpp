/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:30 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 11:09:17 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected: // you need to set them as protected if you want to access them even in the subclass!!
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	ClapTrap(); // I set it private so the user has to input a name. I could as well not use it.

public:
	ClapTrap( std::string name );
	ClapTrap(const ClapTrap &);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap& rhs);

	void	attack(std::string const& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif