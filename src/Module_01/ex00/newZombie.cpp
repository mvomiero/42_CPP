/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:26:50 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 18:51:58 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates a new zombie allocated (using new) */
Zombie	*newZombie( std::string name )
{
	Zombie	*zomby = new Zombie( name );

	return ( zomby );
}