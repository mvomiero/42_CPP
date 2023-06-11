/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:34:05 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/11 13:00:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap // just this syntax to inherit all the elements of the ClapTrap class
{
private:
	FragTrap(); // like for ClapTrap, so I force the user to input a Name

public:
	FragTrap( std::string name );
	~FragTrap();

	void	highFivesGuys();
};

#endif