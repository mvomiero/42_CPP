/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:01:38 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/19 12:03:43 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
//#include "AMateria.hpp"

class Character : public ICharacter
{

private:
	std::string _name;
	AMateria	*_inventory[4];

public:
	Character(std::string const &name);
	Character(Character const &src);
	~Character();

	Character&			operator=(Character const &rhs);

	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif