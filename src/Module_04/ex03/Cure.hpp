/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:39:38 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/19 11:55:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	~Cure();

	Cure( Cure const & src);
	Cure& operator=( Cure const & rhs);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif