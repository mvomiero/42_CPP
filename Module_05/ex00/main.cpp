/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/09 13:05:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
		Bureaucrat high("High", 2);
		Bureaucrat low("Low", 150);
		
		std::cout << high << std::endl;
		std::cout << low << std::endl;

	try {
		high.incrementGrade();
		std::cout << high << std::endl;
		high.incrementGrade();
		std::cout << high << std::endl;

	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		low.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}