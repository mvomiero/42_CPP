/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:40:21 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/29 11:54:13 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& src ) {
	*this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=( const Intern& rhs ) {
	( void ) rhs;
	return (*this);
}

static AForm *	createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *	createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *	createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *	Intern::makeForm(std::string formName, std::string target)
{
	AForm *	formToCreate = NULL;
	static formList const	forms[3] = 
		{
			{"ShrubberyCreationForm", createShrubberyCreationForm},
			{"RobotomyRequestForm", createRobotomyRequestForm},
			{"PresidentialPardonForm", createPresidentialPardonForm}
		};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == formName)
		{
			formToCreate = forms[i].function(target);
			std::cout << GREEN "Intern created " << formToCreate->getName() << RESET << std::endl;
			return (formToCreate);
		}
	}
	std::cout << RED "Intern could not create form named \""
		<< formName << "\"" RESET;
	return (NULL);
}