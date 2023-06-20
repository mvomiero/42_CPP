/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:24:42 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/20 12:22:53 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (materias[i])
			delete materias[i];
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource& MateriaSource::operator=( MateriaSource const & rhs )
{
	if (this != &rhs) {
		for (int i = 0; i < 4; i++)
			materias[i] = rhs.materias[i];
	}
	return *this;
}

AMateria* MateriaSource::getMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
		if (materias[i] && materias[i]->getType() == type)
			return materias[i];
	return NULL;
}

void	MateriaSource::learnMateria( AMateria* m )
{
	for (int i = 0; i < 4; i++)
		if (materias[i] == NULL)
		{
			materias[i] = m;
			if (VERBOSE) {std:: cout << "learnMateria(): " << "Materiasource learned the Amateria " << m->getType() << std::endl; }
			return;
		}
}


AMateria*	MateriaSource::createMateria( std::string const& type )
{
	for ( int i = 0; i < 4; i++ )
		if ( materias[i] && materias[i]->getType() == type ) {
			if (VERBOSE) {std:: cout << "createMateria(): " << "Materiasource clones into its resources the Amateria " << type << std::endl; }
			return materias[i]->clone();
		}
	return NULL;
}