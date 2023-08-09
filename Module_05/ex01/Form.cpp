/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:02:17 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/09 17:10:00 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form( const std::string& name, int gradeToSign ) : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( 0 ) {
	gradeRangeCheck();
}

Form::Form( const Form& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

Form::~Form() {}

Form&	Form::operator=( const Form& rhs ) {
	if ( this != &rhs )
		_signed = rhs.getSigned();
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool	Form::getSigned() const {
	return _signed;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

int	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if ( bureaucrat.getGrade() > _gradeToSign )
		throw Form::GradeTooLowException();
	_signed = true;
}

void	Form::gradeRangeCheck() {
	if (_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs ) {
	o << "\nFORM INFO" << std::endl
	<< "Form name: " << rhs.getName() << std::endl
	<< (rhs.getSigned() ? "signed ✅" : "unsigned ❌") << std::endl
	<< "Grade to sign: " << rhs.getGradeToSign() << std::endl
	<< "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return o;
}