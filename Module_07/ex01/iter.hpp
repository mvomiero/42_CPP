/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:00:56 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/10 13:13:49 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template < typename T >
void	iter( T* array, size_t size, void( *f ) ( T& )) {
	for ( size_t i = 0; i < size; i++ )
		f( array[i] );
}

// a print function to do some testing
template < typename T >
void	print( T& i ) {
	std::cout << i << std::endl;
}

// an increment function to do some testing
template < typename T >
void	increment( T& i ) {
	i++;
}