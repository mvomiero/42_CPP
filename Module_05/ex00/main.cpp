/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/26 17:13:42 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

int main( void )
{
		Bureaucrat high("High", 2);
		Bureaucrat low("Low", 150);
		
		std::cout << high << std::endl;
		std::cout << low << std::endl;

	std::cout << std::endl << "Incrementing and decrementing grades:" << std::endl;

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

	std::cout << std::endl << "Trying to create a bureaucrat with a grade too high:" << std::endl;
	
	try {
		Bureaucrat not_working("Low", 151);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}