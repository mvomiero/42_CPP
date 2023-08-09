/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:13:29 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/09 13:04:16 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade) {
	gradeRangeCheck();
}

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
