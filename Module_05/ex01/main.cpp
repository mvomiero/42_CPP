/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/09 17:08:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ABSTRACT:
	exceptions using try and catch, creating a custom subclass derived from std::exceptions
*/

/* EXCEPTIONS:
	-- Exceptions in C++ are a powerful mechanism for handling unexpected or erroneous
		conditions that may arise during program execution.
	-- Controlled manner to respond to errors, instead of crushing the program.
	-- Lots of predefined classes like std::runtime_errors, std::logic_errors and so on,
		but you can develop your own ones (like in this exercise).
	
	Usage: 
	-- `try` is used to enclose potentially error-prone code
	-- `throw` is used to raise exceptions when errors occur
	-- `catch` is used to handle and recover from those exceptions gracefully.

	you can throw basically anything from an int to these subclasses of std::exception
	which are the default. the parameter to catch will be a reference of an object of the 
	same class to correctly catch the right exception. 

	-- what () function: 
		exceptions normally have a what() function that returns a string giving more
		informations about the problem that happended (here is overloaded in the subclass)
*/

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.h"

int main( void )
{

	try {
		Bureaucrat bureaucrat("Bureaucrat",11);
		Form form("Form", 10);
		std::cout << CYAN BOLD "\n1️⃣ First try\n" RESET << std::endl;
		bureaucrat.signForm(form);
		std::cout << form  << std::endl;
		std::cout << BLUE << bureaucrat << RESET << std::endl;

		bureaucrat.incrementGrade();

		std::cout << CYAN BOLD "\n2️⃣ Second try\n" RESET << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << BLUE << bureaucrat << RESET << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}