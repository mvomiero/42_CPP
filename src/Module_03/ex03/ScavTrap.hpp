/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:34:05 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 16:24:49 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "Colors.h"

class ScavTrap : virtual public ClapTrap // just this syntax to inherit all the elements of the ClapTrap class
{
private:
	ScavTrap(); // like for ClapTrap, so I force the user to input a Name

public:
	ScavTrap( std::string name );
	~ScavTrap();

	void	attack(std::string const& target);
	void	guardGate();
};

#endif