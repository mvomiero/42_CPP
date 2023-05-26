/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:51:31 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 11:59:37 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* HumanB:
	here is NOT possible to use a reference, since weapon is declared but not
	passed as argumebt of the contructor, so it's not a defined element
	(therfore no reference). So a classic pointer definition is operated.
 */
class HumanB
{
private:
	std::string	_name;
	// _weapon is here a standard pointer
	Weapon*		_weapon;

public:
	// no Weapon object passed as argument in the constructor
	HumanB( std::string name );
	~HumanB();

	void	attack( void ) const;
	void	setWeapon( Weapon& weapon );
};