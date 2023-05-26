/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:20:01 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/26 10:33:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* This exercise it to work with references. Refernces corresponds to the 
	dereferenced pointer, and has to be assigned = to an existing pointer to variable.
	To access the value you don't have therefore to dereference it. 
	The comparison in the two output logs, which is identical in all the three cases
	shows how is possible to access a same variable and corresponding pointer with
	different notations/elemts.
 */
int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory addresses:\n"
		<< "string: " << &str << " - stringPTR: " << stringPTR << " - stringREF: " << &stringREF << std::endl;

	std::cout << "Vaues:\n"
		<< "string: " << str << " - stringPTR: " << *stringPTR << " - stringREF: " << stringREF << std::endl;
	return (0);
}