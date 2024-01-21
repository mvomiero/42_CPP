/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:39:38 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/19 11:55:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	~Ice();

	Ice( Ice const & src);
	Ice& operator=( Ice const & rhs);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif