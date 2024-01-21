/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:00:56 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/11 15:49:38 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename A, typename F>
void	iter(A * array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
	return ;
}
