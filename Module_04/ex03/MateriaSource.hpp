/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:20:59 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 16:25:17 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	materias[4];

public:
	MateriaSource();
	~MateriaSource();

	MateriaSource( MateriaSource const & );
	MateriaSource&	operator=( MateriaSource const & );

	AMateria*	getMateria( std::string const & type );
	AMateria*	createMateria( std::string const & type );
	void		learnMateria( AMateria* );
};

#endif