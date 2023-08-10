/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 12:10:40 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ABSTRACT:
	improving the exercise before with a class AForm that at initialization is 
	not "signed", that checks if the bureaucrat's grade is high enough to be signed.
	If it is, the AForm will be signed.

	PS: gradeToExecute is just for the next exercises
*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "colors.h"

int main( void )
{

	try {
		// the grade is too low, the AForm won't be signed
		Bureaucrat bureaucrat("Bureaucrat",11);
		AForm AForm("AForm", 10);
		std::cout << CYAN BOLD "\n1️⃣ First try\n" RESET << std::endl;
		bureaucrat.signAForm(AForm);
		std::cout << AForm  << std::endl;
		std::cout << BLUE << bureaucrat << RESET << std::endl;

		bureaucrat.incrementGrade();

		// the bureaucrat's grade is incremented, will be enough to sign the AForm
		std::cout << CYAN BOLD "\n2️⃣ Second try\n" RESET << std::endl;
		bureaucrat.signAForm(AForm);
		std::cout << AForm << std::endl;
		std::cout << BLUE << bureaucrat << RESET << std::endl;

	/* NB:
		using a standard std::exeception I will intercect all the exceptions, then the what message
		will give me more inAFormation about what happened. the problem is if you would have
		more than one exception, it would intercect just the first one.
		So: this is not the best approach but still can be practical */
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}