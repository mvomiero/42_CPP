/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 13:49:06 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ABSTRACT:
	improving the exercise before with a class ShrubberyCreationForm that at initialization is 
	not "signed", that checks if the bureaucrat's grade is high enough to be signed.
	If it is, the ShrubberyCreationForm will be signed.

	PS: gradeToExecute is just for the next exercises
*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "colors.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



/* int main( void )
{

	try {
		// the grade is too low, the ShrubberyCreationForm won't be signed
		const Bureaucrat bureaucrat("Bureaucrat",11);
		ShrubberyCreationForm shrubbery("Targetzzz");
		shrubbery.execute(bureaucrat);
		std::cout << CYAN BOLD "\n1️⃣ First try\n" RESET << std::endl;
		std::cout << shrubbery  << std::endl;
		std::cout << BLUE << bureaucrat << RESET << std::endl;

		//bureaucrat.incrementGrade(bureaucrat);

		
		// the bureaucrat's grade is incremented, will be enough to sign the shrubbery
		std::cout << CYAN BOLD "\n2️⃣ Second try\n" RESET << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << BLUE << bureaucrat << RESET << std::endl;


	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
} */

int main( void )
{

    try {
        Bureaucrat bureaucrat("ash", 2); // error with 200
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}