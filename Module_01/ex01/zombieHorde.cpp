/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:26:50 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/25 16:41:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates a new zombie allocated (using new) */
Zombie *zombieHorde( int N, std::string name )
{
	if ( N <= 0 )
		return ( NULL );
	Zombie	*zombiesssss = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombiesssss[i].setName( name );
	}
	return ( zombiesssss );
}