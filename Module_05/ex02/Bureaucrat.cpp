/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:29 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 13:48:00 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade) {
	gradeRangeCheck();
}

/* can't use the copy assignment operator since name is a const and has therfore
	to be initializes when the object is instantiated */
Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if ( this != &rhs )
		_grade = rhs._grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::gradeRangeCheck() {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::incrementGrade() {
	_grade--;
	gradeRangeCheck();
}

void    Bureaucrat::decrementGrade() {
	_grade++;
	gradeRangeCheck();

}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void	Bureaucrat::signForm( AForm& AForm ) {
	try {
		AForm.beSigned( *this );
		std::cout << GREEN BOLD << *this << " signed " << AForm.getName() << RESET << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << RED BOLD << _name << " coulnd't sign " << AForm.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void    Bureaucrat::executeForm( const AForm& form ) const {
    try {
        form.execute( *this );
    } catch ( std::exception& e ) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

