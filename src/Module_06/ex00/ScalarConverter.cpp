/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:28:35 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/09 16:45:59 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* instantiates a Converter object and performs the operations to set the input string,
	convert and print.
 */
void ScalarConverter::convert(const std::string& str) {
	Converter converter;
	converter.setStr(str);
	converter.convert();
	std::cout << converter << std::endl;
}


