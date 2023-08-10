/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:02:17 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/10 12:06:26 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute ) {
	gradeRangeCheck();
}

AForm::AForm( const AForm& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

AForm::~AForm() {}

AForm&	AForm::operator=( const AForm& rhs ) {
	if ( this != &rhs )
		_signed = rhs.getSigned();
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool	AForm::getSigned() const {
	return _signed;
}

int	AForm::getGradeToSign() const {
	return _gradeToSign;
}

int	AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if ( bureaucrat.getGrade() > _gradeToSign )
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::gradeRangeCheck() {
	if (_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }

const char* AForm::NotSignedException::what() const throw() { return "Form not signed"; }

std::ostream&   operator<<( std::ostream& o, const AForm& rhs ) {
	o << "\nAForm INFO" << std::endl
	<< "AForm name: " << rhs.getName() << std::endl
	<< (rhs.getSigned() ? "signed ✅" : "unsigned ❌") << std::endl
	<< "Grade to sign: " << rhs.getGradeToSign() << std::endl
	<< "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return o;
}