/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:40:23 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/12 12:04:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <iterator>
# include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T& container, const int element)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw std::runtime_error("Element not found");
	return it;
}