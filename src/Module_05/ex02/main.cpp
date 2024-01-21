/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/26 18:23:52 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ABSTRACT:
	a more complicated form system: Bureaucrat is the one that signs the Forms 
	and executes their own properties (the execute function). 
	Since the three derived classes have different values for gradeToSign and 
	gradeToExecute, if you change the grade of the bureaucrat, you'll be able
	to perform some operations on some forms, but not on all of them. 
*/

#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "colors.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main( void )
{

	try {
		Bureaucrat bureaucrat("Giorgio", 5);
		// you can try differen values like 160, 120, 55 etc, 
		// you'll see that some operations are not enabled and that exceptions are
		// thrown
		ShrubberyCreationForm form1("Shrubby 🌳");
		RobotomyRequestForm form2("Robooty 🍑🤖");
		PresidentialPardonForm form3("President 👁️");

		std::cout << CYAN BOLD "\n-----FORM 1 (Shrubby 🌳)-----\n" RESET << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		std::cout << CYAN BOLD "\n-----FORM 2 (Robooty 🍑🤖)-----\n" RESET << std::endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		std::cout << CYAN BOLD "\n-----FORM 2 (President 👁️)-----\n" RESET << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}