/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:28:35 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/14 13:47:20 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/* class ScalarConverter {
public:
	// Static function to perform the conversion and printing
	static void convertAndPrint(const std::string& str) {
		Converter converter;
		converter.setStr(str);
		converter.convert();
		std::cout << converter << std::endl;
	}
}; */

void ScalarConverter::convertAndPrint(const std::string& str) {
		Converter converter;
		converter.setStr(str);
		converter.convert();
		std::cout << converter << std::endl;
	}


