/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:32:54 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 13:05:40 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) 
	: AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ), _target( src._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& rhs ) {
	_target = rhs._target; 
	return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
	if ( this->getSigned() == false )
		throw AForm::NotSignedException();
	else if ( executor.getGrade() > this->getGradeToExecute() ) {
		throw AForm::GradeTooLowException();
	}

	std::ofstream file( this->getName() + "_shrubbery" );
	file << "                            '.,\n" <<
"                              'b      *\n" <<
"                               '$    #.\n" <<
"                                $:   #:\n" <<
"                                *#  @):\n" <<
"                                :@,@):   ,.**:'\n" <<
"                      ,         :@@*: ..**'\n" <<
"                       '#o.    .:(@'.@*'\n" <<
"                          'bq,..:,@@*'   ,*\n" <<
"                          ,p$q8,:@)'  .p*'\n" <<
"                         '    '@@Pp@@*'\n" <<
"                               Y7'.'\n" <<
"                              :@):.\n" <<
"                             .:@:'.\n" <<
"                           .::(@:.\n" << std::endl;
	file.close();
}