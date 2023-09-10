/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:09:13 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/10 12:22:10 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template < typename T >
void	swap( T& a, T& b ) {
	T temp = a;
	a = b;
	b = temp;
}

template < typename T >
T	min( T& a, T& b ) {
	return ( a < b ? a : b );
}

template < typename T >
T	max( T& a, T& b ) {
	return ( a > b ? a : b );
}