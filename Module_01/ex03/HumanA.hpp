/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:44:53 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 12:00:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* HumanA:
	here is possible to use a reference, since the constructor gets Weapon as
	an argument
 */
class HumanA
{
private:
	std::string	_name;
	//here _weapon is a reference, since is a defined object, passed from the constructor
	Weapon&		_weapon;
	HumanA();

public:
	// Weapon object pass as argument
	HumanA( std::string name, Weapon& weapon );
	~HumanA();

	void	attack( void ) const;
};